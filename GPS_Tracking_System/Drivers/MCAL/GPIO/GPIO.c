


#include "MCAL/GPIO/GPIO.h"


void MCAL_GPIO_INIT(uint8_t GPIO_SEL){
		switch(GPIO_SEL){
			case PORTA_ID:
				SET_BIT(SYSCTL_RCGCGPIO_R,PORTA_ID);
				while((GET_BIT(SYSCTL_PRGPIO_R,PORTA_ID)) == low);
				GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
			break;
			case PORTB_ID:
				SET_BIT(SYSCTL_RCGCGPIO_R,PORTB_ID);
				while((GET_BIT(SYSCTL_PRGPIO_R,PORTB_ID)) == low);
				GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
			break;
			case PORTC_ID:
				SET_BIT(SYSCTL_RCGCGPIO_R,PORTC_ID);
				while((GET_BIT(SYSCTL_PRGPIO_R,PORTC_ID)) == low);
				GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
			break;
			case PORTD_ID:
				SET_BIT(SYSCTL_RCGCGPIO_R,PORTD_ID);
				while((GET_BIT(SYSCTL_PRGPIO_R,PORTD_ID)) == low);
				GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
			break;
			case PORTE_ID:
				SET_BIT(SYSCTL_RCGCGPIO_R,PORTE_ID);
				while((GET_BIT(SYSCTL_PRGPIO_R,PORTE_ID)) == low);
				GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
			break;
			case PORTF_ID:
				SET_BIT(SYSCTL_RCGCGPIO_R,PORTF_ID);
				while((GET_BIT(SYSCTL_PRGPIO_R,PORTF_ID)) == low);
				GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
			break;
		}
}

void MCAL_GPIO_DIGITAL_INIT(uint8_t GPIO_SEL,uint8_t pin){
			switch(GPIO_SEL){
					case PORTA_ID:
						SET_BIT(GPIO_PORTA_CR_R,pin);
						CLR_BIT(GPIO_PORTA_AMSEL_R,pin);
					  CLR_BIT(GPIO_PORTA_AFSEL_R,pin);
				   	CLR_MASK(GPIO_PORTA_PCTL_R,0xF<<(pin*4));
					  SET_BIT(GPIO_PORTA_DEN_R,pin);
					break;
					case PORTB_ID:
						SET_BIT(GPIO_PORTB_CR_R,pin);
						CLR_BIT(GPIO_PORTB_AMSEL_R,pin);
					  CLR_BIT(GPIO_PORTB_AFSEL_R,pin);
					  CLR_MASK(GPIO_PORTB_PCTL_R,0xF<<(pin*4));//GPIO_PORTB_PCTL_R  &= ~(0xF<<(pin*4));
					  SET_BIT(GPIO_PORTB_DEN_R,pin);	
					break;
					case PORTC_ID:
					  SET_BIT(GPIO_PORTC_CR_R,pin);
						CLR_BIT(GPIO_PORTC_AMSEL_R,pin);
					  CLR_BIT(GPIO_PORTC_AFSEL_R,pin);
					  CLR_MASK(GPIO_PORTC_PCTL_R,0xF<<(pin*4));
					  SET_BIT(GPIO_PORTC_DEN_R,pin);	
					break;
					case PORTD_ID:
						SET_BIT(GPIO_PORTD_CR_R,pin);
						CLR_BIT(GPIO_PORTD_AMSEL_R,pin);
					  CLR_BIT(GPIO_PORTD_AFSEL_R,pin);
					  CLR_MASK(GPIO_PORTD_PCTL_R,0xF<<(pin*4));
					  SET_BIT(GPIO_PORTD_DEN_R,pin);	
					break;
					case PORTE_ID:
						SET_BIT(GPIO_PORTE_CR_R,pin);
						CLR_BIT(GPIO_PORTE_AMSEL_R,pin);
					  CLR_BIT(GPIO_PORTE_AFSEL_R,pin);
					  CLR_MASK(GPIO_PORTE_PCTL_R,0xF<<(pin*4));
					  SET_BIT(GPIO_PORTE_DEN_R,pin);	
					break;
					case PORTF_ID:
						SET_BIT(GPIO_PORTF_CR_R,pin);
						CLR_BIT(GPIO_PORTF_AMSEL_R,pin);
					  CLR_BIT(GPIO_PORTF_AFSEL_R,pin);
					  CLR_MASK(GPIO_PORTF_PCTL_R,0xF<<(pin*4));
					  SET_BIT(GPIO_PORTF_DEN_R,pin);	
					break;
		}
}


void MCAL_GPIO_DIGITAL_PIN_MODE(uint8_t Port, uint8_t pin, uint8_t Mode, uint8_t Polarity) {
	switch(Port) {
		case PORTA_ID:
			if(Mode == Output)
				SET_BIT(GPIO_PORTA_DIR_R, pin);
			else {
				CLR_BIT(GPIO_PORTA_DIR_R, pin);
				switch(Polarity) {
					case Pull_up:
						SET_BIT(GPIO_PORTA_PUR_R, pin);
						CLR_BIT(GPIO_PORTA_PDR_R, pin);
						break;
					case Pull_down:
						SET_BIT(GPIO_PORTA_PDR_R, pin);
						CLR_BIT(GPIO_PORTA_PUR_R, pin);
						break;
					case Floating:
						CLR_BIT(GPIO_PORTA_PUR_R, pin);
						CLR_BIT(GPIO_PORTA_PDR_R, pin);
						break;
				}
			}
			break;

		case PORTB_ID:
			if(Mode == Output)
				SET_BIT(GPIO_PORTB_DIR_R, pin);
			else {
				CLR_BIT(GPIO_PORTB_DIR_R, pin);
				switch(Polarity) {
					case Pull_up:
						SET_BIT(GPIO_PORTB_PUR_R, pin);
						CLR_BIT(GPIO_PORTB_PDR_R, pin);
						break;
					case Pull_down:
						SET_BIT(GPIO_PORTB_PDR_R, pin);
						CLR_BIT(GPIO_PORTB_PUR_R, pin);
						break;
					case Floating:
						CLR_BIT(GPIO_PORTB_PUR_R, pin);
						CLR_BIT(GPIO_PORTB_PDR_R, pin);
						break;
				}
			}
			break;

		case PORTC_ID:
			if(Mode == Output)
				SET_BIT(GPIO_PORTC_DIR_R, pin);
			else {
				CLR_BIT(GPIO_PORTC_DIR_R, pin);
				switch(Polarity) {
					case Pull_up:
						SET_BIT(GPIO_PORTC_PUR_R, pin);
						CLR_BIT(GPIO_PORTC_PDR_R, pin);
						break;
					case Pull_down:
						SET_BIT(GPIO_PORTC_PDR_R, pin);
						CLR_BIT(GPIO_PORTC_PUR_R, pin);
						break;
					case Floating:
						CLR_BIT(GPIO_PORTC_PUR_R, pin);
						CLR_BIT(GPIO_PORTC_PDR_R, pin);
						break;
				}
			}
			break;

		case PORTD_ID:
			if(Mode == Output)
				SET_BIT(GPIO_PORTD_DIR_R, pin);
			else {
				CLR_BIT(GPIO_PORTD_DIR_R, pin);
				switch(Polarity) {
					case Pull_up:
						SET_BIT(GPIO_PORTD_PUR_R, pin);
						CLR_BIT(GPIO_PORTD_PDR_R, pin);
						break;
					case Pull_down:
						SET_BIT(GPIO_PORTD_PDR_R, pin);
						CLR_BIT(GPIO_PORTD_PUR_R, pin);
						break;
					case Floating:
						CLR_BIT(GPIO_PORTD_PUR_R, pin);
						CLR_BIT(GPIO_PORTD_PDR_R, pin);
						break;
				}
			}
			break;

		case PORTE_ID:
			if(Mode == Output)
				SET_BIT(GPIO_PORTE_DIR_R, pin);
			else {
				CLR_BIT(GPIO_PORTE_DIR_R, pin);
				switch(Polarity) {
					case Pull_up:
						SET_BIT(GPIO_PORTE_PUR_R, pin);
						CLR_BIT(GPIO_PORTE_PDR_R, pin);
						break;
					case Pull_down:
						SET_BIT(GPIO_PORTE_PDR_R, pin);
						CLR_BIT(GPIO_PORTE_PUR_R, pin);
						break;
					case Floating:
						CLR_BIT(GPIO_PORTE_PUR_R, pin);
						CLR_BIT(GPIO_PORTE_PDR_R, pin);
						break;
				}
			}
			break;

		case PORTF_ID:
			if(Mode == Output)
				SET_BIT(GPIO_PORTF_DIR_R, pin);
			else {
				CLR_BIT(GPIO_PORTF_DIR_R, pin);
				switch(Polarity) {
					case Pull_up:
						SET_BIT(GPIO_PORTF_PUR_R, pin);
						CLR_BIT(GPIO_PORTF_PDR_R, pin);
						break;
					case Pull_down:
						SET_BIT(GPIO_PORTF_PDR_R, pin);
						CLR_BIT(GPIO_PORTF_PUR_R, pin);
						break;
					case Floating:
						CLR_BIT(GPIO_PORTF_PUR_R, pin);
						CLR_BIT(GPIO_PORTF_PDR_R, pin);
						break;
				}
			}
			break;
	}
}


void MCAL_GPIO_WRITE_PIN(uint8_t GPIO_SEL, uint8_t pin, uint8_t data){
	switch(GPIO_SEL){
					case PORTA_ID:
						if(data==high)
							SET_BIT(GPIO_PORTA_DATA_R,pin);
						else
							CLR_BIT(GPIO_PORTA_DATA_R,pin);
					break;
					case PORTB_ID:
					  if(data==high)
							SET_BIT(GPIO_PORTB_DATA_R,pin);
						else
							CLR_BIT(GPIO_PORTB_DATA_R,pin);
					break;
					case PORTC_ID:
						if(data==high)
							SET_BIT(GPIO_PORTC_DATA_R,pin);
						else
							CLR_BIT(GPIO_PORTC_DATA_R,pin);
					break;
					case PORTD_ID:
						if(data==high)
							SET_BIT(GPIO_PORTD_DATA_R,pin);
						else
							CLR_BIT(GPIO_PORTD_DATA_R,pin);
					break;
					case PORTE_ID:
						if(data==high)
							SET_BIT(GPIO_PORTE_DATA_R,pin);
						else
							CLR_BIT(GPIO_PORTE_DATA_R,pin);
					break;
					case PORTF_ID:
						if(data==high)
							SET_BIT(GPIO_PORTF_DATA_R,pin);
						else
							CLR_BIT(GPIO_PORTF_DATA_R,pin);
					break;
		}
}

void MCAL_GPIO_WRITE_PORT(uint8_t GPIO_SEL, uint8_t data) {
	switch(GPIO_SEL) {
		case PORTA_ID:
			GPIO_PORTA_DATA_R = data;
			break;
		case PORTB_ID:
			GPIO_PORTB_DATA_R = data;
			break;
		case PORTC_ID:
			GPIO_PORTC_DATA_R = data;
			break;
		case PORTD_ID:
			GPIO_PORTD_DATA_R = data;
			break;
		case PORTE_ID:
			GPIO_PORTE_DATA_R = data;
			break;
		case PORTF_ID:
			GPIO_PORTF_DATA_R = data;
			break;
	}
}




uint8_t MCAL_GPIO_READ_PIN(uint8_t GPIO_SEL, uint8_t pin){
	switch(GPIO_SEL){
					case PORTA_ID:
						return GET_BIT(GPIO_PORTA_DATA_R,pin);
					case PORTB_ID:
						return GET_BIT(GPIO_PORTB_DATA_R,pin);
					case PORTC_ID:
						return GET_BIT(GPIO_PORTC_DATA_R,pin);
					case PORTD_ID:
						return GET_BIT(GPIO_PORTD_DATA_R,pin);
					case PORTE_ID:
						return GET_BIT(GPIO_PORTE_DATA_R,pin);
					case PORTF_ID:
						return GET_BIT(GPIO_PORTF_DATA_R,pin);
					default:
			        return 0;
					
		}
}
uint8_t MCAL_GPIO_READ_PORT(uint8_t GPIO_SEL) {
	switch(GPIO_SEL) {
		case PORTA_ID:
			return (uint8_t)(GPIO_PORTA_DATA_R & 0xFF);
		case PORTB_ID:
			return (uint8_t)(GPIO_PORTB_DATA_R & 0xFF);
		case PORTC_ID:
			return (uint8_t)(GPIO_PORTC_DATA_R & 0xFF);
		case PORTD_ID:
			return (uint8_t)(GPIO_PORTD_DATA_R & 0xFF);
		case PORTE_ID:
			return (uint8_t)(GPIO_PORTE_DATA_R & 0xFF);
		case PORTF_ID:
			return (uint8_t)(GPIO_PORTF_DATA_R & 0xFF);
		default:
			return 0; // in case of invalid port
	}
}


void MCAL_GPIO_TOGGLE_PIN(uint8_t GPIO_SEL, uint8_t pin){
	switch(GPIO_SEL){
		case PORTA_ID:
			TOG_BIT(GPIO_PORTA_DATA_R, pin);
			break;
		case PORTB_ID:
			TOG_BIT(GPIO_PORTB_DATA_R, pin);
			break;
		case PORTC_ID:
			TOG_BIT(GPIO_PORTC_DATA_R, pin);
			break;
		case PORTD_ID:
			TOG_BIT(GPIO_PORTD_DATA_R, pin);
			break;
		case PORTE_ID:
			TOG_BIT(GPIO_PORTE_DATA_R, pin);
			break;
		case PORTF_ID:
			TOG_BIT(GPIO_PORTF_DATA_R, pin);
			break;
	}
}


