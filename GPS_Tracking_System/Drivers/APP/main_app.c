#include "APP/main_app.h"

volatile uint32_t count=0;
volatile uint32_t count1=0;
volatile uint32_t count_UART=0;
void MY_Systick_Function(void)
 { 
	 LCD_DELAY++;
	 if(count++>=1000){
	   count1++;
		 count_UART++;
		 count = 0;
		 
      }
 }
 
 
 
 


void UART5_Handler(void) {
    if (UART5_MIS_R & (1 << 4))
			{
        char c = MCAL_UART_RX(UART5_ID);
        UART5_ICR_R |= (1 << 4); 
				HAL_GPS_Receive_Handler(c);
        				
    }
}

void App_Main_Loop(void)
{ 
	   
		 GPS_Task();
		 //LED_Blink_Task();
	   ADC_Task();
	   GUI_Task();
	
	
      
}



void LED_Blink_Task(void )
{ 
  if(count1>=2)
		{
			count1=0;
			HAL_LED_TOGGLE(PORTF_ID,PIN_3);
			
}

}



void GPS_Task(void)
{
      char* MY_Region=0;
      if(string_ready_uart5 == STRING_OK )
			{
			
			string_ready_uart5 =STRING_NOT_OK ;
		  HAL_GPS_parseGPRMC((const char*)str_uart5,  &GPS_data);
			MY_Region = HAL_GPS_check_region(GPS_data.latitude,GPS_data.longitude);
	    HAL_LCD_WRITE_AT(0, 0, (char*)MY_Region);			
			}
}	
 






void ADC_Task(void)
{  char x[50];
    uint16_t adc_value;
	 float distance;
	
	 	if(GPS_data.status !='A'){
			return;
		  }
		else
		{
			GPS_data.status='V';
  HAL_LCD_SET_CURSOR(1,5);
	  HAL_LCD_SEND_DATA(3);
	  HAL_LCD_SEND_DATA(4);
    HAL_LCD_SEND_DATA(7);
	  HAL_LCD_SEND_DATA(6);
	  HAL_LCD_SEND_DATA(5);
	  
	HAL_LCD_SET_CURSOR(1,13);
	  HAL_LCD_SEND_DATA(3);
	  HAL_LCD_SEND_DATA(2);
	  HAL_LCD_SEND_DATA(1);
		}
	  
    adc_value = ADC0_Read_Channel(0);
	  if (adc_value < 585)
    {
	    HAL_LCD_WRITE_AT(1,0,"GATE1" );
			distance=1000*HAL_GPS_CalculateDistance(30.065757, 31.278352, GPS_data.latitude, GPS_data.longitude);
			//float_to_string( , x, 0);
			//HAL_LCD_WRITE_AT(1,10, x);
     // MCAL_UART_TX_STRING(UART0_ID,"1");
			}    
    else if (adc_value < 1170)
        {
	    HAL_LCD_WRITE_AT(1,0,"GATE2" );
			distance=1000*HAL_GPS_CalculateDistance(30.064723, 31.277494, GPS_data.latitude, GPS_data.longitude);		
		//	float_to_string( 1000*HAL_GPS_CalculateDistance(30.064723, 31.277494, GPS_data.latitude, GPS_data.longitude), x, 0);
		//	HAL_LCD_WRITE_AT(1,10, x);
     // MCAL_UART_TX_STRING(UART0_ID,"2");
			}
    else if (adc_value < 1755)
       {
	    HAL_LCD_WRITE_AT(1,0,"GATE3" );
			distance=1000*HAL_GPS_CalculateDistance(30.063951, 31.277804, GPS_data.latitude, GPS_data.longitude);	 
			//float_to_string( 1000*HAL_GPS_CalculateDistance(30.063951, 31.277804, GPS_data.latitude, GPS_data.longitude), x, 0);
			HAL_LCD_WRITE_AT(1,10, x);
     // MCAL_UART_TX_STRING(UART0_ID,"3");
			}
    else if (adc_value < 2340)
        {
	    HAL_LCD_WRITE_AT(1,0,"GATE4" );
				distance=1000*HAL_GPS_CalculateDistance(30.062912, 31.278176, GPS_data.latitude, GPS_data.longitude);		
			//float_to_string( 1000*HAL_GPS_CalculateDistance(30.062912, 31.278176, GPS_data.latitude, GPS_data.longitude), x, 0);
		//	HAL_LCD_WRITE_AT(1,10, x);
      //MCAL_UART_TX_STRING(UART0_ID,"4");
			}
    else if (adc_value < 2925)
      {
	   HAL_LCD_WRITE_AT(1,0,"GATE5" );
				distance=1000*HAL_GPS_CalculateDistance(30.063368, 31.280331, GPS_data.latitude, GPS_data.longitude);
		//	float_to_string( 1000*HAL_GPS_CalculateDistance(30.063368, 31.280331, GPS_data.latitude, GPS_data.longitude), x, 0);
			//HAL_LCD_WRITE_AT(1,10, x);
      //MCAL_UART_TX_STRING(UART0_ID,"5");
			}
    else if (adc_value < 3510)
      {
	    HAL_LCD_WRITE_AT(1,0,"GATE6" );
				distance=1000*HAL_GPS_CalculateDistance(30.064826, 31.280389, GPS_data.latitude, GPS_data.longitude);
			//float_to_string( 1000*HAL_GPS_CalculateDistance(30.064826, 31.280389, GPS_data.latitude, GPS_data.longitude), x, 0);
		//	HAL_LCD_WRITE_AT(1,10, x);
      //MCAL_UART_TX_STRING(UART0_ID,"6");
			}
    else
        
			{
	    HAL_LCD_WRITE_AT(1,0,"GATE7" );
				distance=1000*HAL_GPS_CalculateDistance(30.065809, 31.279970, GPS_data.latitude, GPS_data.longitude);
		//	float_to_string( 1000*HAL_GPS_CalculateDistance(30.065809, 31.279970, GPS_data.latitude, GPS_data.longitude), x, 0);
			//HAL_LCD_WRITE_AT(1,10, x);
      //MCAL_UART_TX_STRING(UART0_ID,"7");
			}
			if(distance<10)
			{
			float_to_string(distance, x, 0);
			HAL_LCD_WRITE_AT(1,10, x);
			HAL_LCD_WRITE_AT(1,11, "  ");	
			}	
			else if(distance<100)
			{
			float_to_string(distance, x, 0);
			HAL_LCD_WRITE_AT(1,10, x);
			HAL_LCD_WRITE_AT(1,12, " ");	
			}	
			else 
				{
			float_to_string(distance, x, 0);
			HAL_LCD_WRITE_AT(1,10, x);
			
			}		
				
			
			if(distance<30)
			{
				HAL_LED_ON(PORTF_ID,PIN_3);
				HAL_LED_OFF(PORTF_ID,PIN_1);
		  	HAL_LED_OFF(PORTF_ID,PIN_2);
			}	
			else if(distance<70)
				{
			HAL_LED_ON(PORTF_ID,PIN_2);
				HAL_LED_OFF(PORTF_ID,PIN_1);
		  	HAL_LED_OFF(PORTF_ID,PIN_3);
			}	
			else 
				{
				HAL_LED_ON(PORTF_ID,PIN_1);
				HAL_LED_OFF(PORTF_ID,PIN_3);
		  	HAL_LED_OFF(PORTF_ID,PIN_2);
			}	
}



void GUI_Task(void)
{
	if(count_UART>=2)
		{
			count_UART=0;
		 HAL_GPS_sendGPSData( UART0_ID ,GPS_data.latitude, GPS_data.longitude);
		}
}

/*
 uint32_t GUI_address=0;

void GUI_Task(void)
{//part 1
	if(HAL_BUTTON_READ(PORTF_ID,PIN_0)==low)
	{
		LCD_DELAY=0;
	 while(LCD_DELAY<100);
		HAL_LED_TOGGLE(PORTF_ID,PIN_3);
		while(HAL_BUTTON_READ(PORTF_ID,PIN_0)==high);
		MCAL_EEPROM_Write(0, 0, 'a');
		//HAL_GPS_SaveCoordinates(30.063562, 31.281057,GUI_address/16 ,GUI_address%16);
		//GUI_address+=2;
	}
	
	//part 2
	if(HAL_BUTTON_READ(PORTF_ID,PIN_4)==low)
	{uint32_t i=0;uint32_t data;
	float lat;
  float lon;	
		
HAL_LED_TOGGLE(PORTF_ID,PIN_1);	
LCD_DELAY=0;
	 while(LCD_DELAY<100);		
		while(HAL_BUTTON_READ(PORTF_ID,PIN_4)==high);
		MCAL_EEPROM_Read(0, 0, &data);
		MCAL_UART_TX(UART0_ID,data);
		for(i=0;i<GUI_address;i+=2)
		  {
				HAL_GPS_LoadCoordinates(&lat,&lon,i/16 ,i%16);
				HAL_GPS_sendGPSData(UART0_ID,lat,lon);
		  }
			GUI_address=0;
		
	}	
	
	
}

*/

