#include "HAL/GPS/GPS.h"

Region_t regions[] = {
	 {
        "unknown location",
        {
            {0, 0}, // Corner 1
            {0, 0}, // Corner 2
            {0, 0}, // Corner 3
            {0, 0}  // Corner 4
        }
    }
	 ,
    {
        "    LIBRARY     ",
        {
            {30.065066, 31.280374}, // Corner 1
            {30.064942, 31.279779}, // Corner 2
            
            {30.065224, 31.279652},  // Corner 3
						{30.065403, 31.280224} // Corner 4
        }
    }
	/* ,
    {
        "     TEST    ",
        {
            
            {30.064256, 31.280366}, // Corner 1
            {30.063607, 31.278503},  // Corner 2
						{30.064421, 31.277900}, // Corner 3
            {30.064871, 31.279362} // Corner 4
        }
    }
		,
    {
        "     TEST    ",
        {
            
            {30.064235, 31.278477}, // Corner 1
            {30.063904, 31.278630},  // Corner 2
						{30.064139, 31.279357}, // Corner 3
            {30.064871, 31.279362} // Corner 4
        }
    }
		*/
		,
    {
        "HALL A,B,C,D&ARCH",//hall a,c
        {
            {30.063562, 31.281057}, // Corner 1
            {30.063311, 31.280386}, // Corner 2
            
            {30.064271, 31.279886},  // Corner 3
						{30.064583, 31.280599} // Corner 4
        }
    }
		,
    {
        "     LUBAN      ",///luban
        {
            
            {30.063354, 31.280439}, // Corner 1
            {30.062776, 31.278780},  // Corner 2
						{30.063209, 31.278640}, // Corner 3
            {30.063738, 31.280061} // Corner 4
        }
    }
		,
    {
        "   PLAYGROUND   ",
        {
            
            {30.063731, 31.280138}, // Corner 1
            {30.063235, 31.278670},  // Corner 2
						{30.063833, 31.278429}, // Corner 3
            {30.064324, 31.279878} // Corner 4
        }
    }
		,
    {
        "CREDIT BUILDING ",
        {
            
            {30.063152, 31.278726}, // Corner 1
            {30.062913, 31.278026},  // Corner 2
						{30.063595, 31.277796}, // Corner 3
            {30.063800, 31.278393} // Corner 4
        }
    }
		
		,
    {
        "     GATE 6    ",
        {
            
            {30.064582, 31.280640}, // Corner 1
            {30.064435, 31.280159},  // Corner 2
						{30.064742, 31.279933}, // Corner 3
            {30.065001, 31.280405} // Corner 4
        }
    }
		,
    {
        " MAIN BUILDING  ",
        {
            
            {30.064621, 31.280030}, // Corner 1
            {30.064071, 31.278212},  // Corner 2
						{30.065595, 31.277501}, // Corner 3
            {30.066120, 31.279350} // Corner 4
        }
    }
		,
    {
        "KARASANA BUILDING",
        {
            
            {30.064072, 31.277979}, // Corner 1
            {30.063930, 31.277590},  // Corner 2
						{30.064335, 31.277407}, // Corner 3
            {30.064456, 31.277763} // Corner 4
        }
    }
		,
    {
        "     GATE 2     ",
        {
            
            {30.064469, 31.277768}, // Corner 1
            {30.064352, 31.277404},  // Corner 2
						{30.064834, 31.277188}, // Corner 3
            {30.064945, 31.277564} // Corner 4
        }
    }
		,
    {
        " MECH WORKSHOPS ",
        {
            {30.064394, 31.280172}, // Corner 1
            {30.063641, 31.278012}, // Corner 2
            {30.063984, 31.277768}, // Corner 3
            {30.064744, 31.279881}  // Corner 4
        }
    }
		,
    {
        "      my home    ",
        {
            {30.296112, 31.738759}, // Corner 1
            {30.295930, 31.738478}, // Corner 2
            {30.295616, 31.738733}, // Corner 3
            {30.295886, 31.738976}  // Corner 4
        }
    }
};


volatile char str_uart5[100];
volatile uint8_t Index_uart5 = 0;
volatile uint8_t string_ready_uart5 = 0;
volatile uint8_t receiving_uart5 = 0; 
volatile uint8_t checksum_count = 0;

GPRMC_Data GPS_data;
void HAL_GPS_Receive_Handler(char c)
{
    if (c == '$') {
        receiving_uart5 = 1;
        Index_uart5 = 0;
        checksum_count = 0;
        str_uart5[Index_uart5++] = c;
    } 
    else if (receiving_uart5) {
        if (Index_uart5 < sizeof(str_uart5) - 1) {
            str_uart5[Index_uart5++] = c;

            if (c == '*') {
                checksum_count = 2;
            } 
            else if (checksum_count > 0) {
                checksum_count--;
                if (checksum_count == 0) {
                    str_uart5[Index_uart5] = '\0';
                    string_ready_uart5 = STRING_OK ;
                    receiving_uart5 = 0;
                }
            }
        } 
        else {
            // buffer overflow: reset
            Index_uart5 = 0;
            receiving_uart5 = 0;
            checksum_count = 0;
        }
    }
}


char* HAL_GPS_check_region(float current_lat, float current_lon) {
    uint32_t num_regions = sizeof(regions) / sizeof(regions[0]);
    uint32_t i = 1;
  	Point_t p ;
		p.lat=current_lat;
		p.lon=current_lon;
    for ( i = 1; i < num_regions; i++) {
        if (point_in_quad(p, regions[i].corners)) {
            return regions[i].name;
        }
    }
    return regions[0].name; // Unknown location
}


uint32_t point_in_quad(Point_t p, Point_t quad[4]) {
   /* uint32_t i, j;
    uint32_t inside = 0;
    for (i = 0, j = 3; i < 4; j = i++) {
        if (((quad[i].lat > p.lat) != (quad[j].lat > p.lat)) &&
            (p.lon < (quad[j].lon - quad[i].lon) * (p.lat - quad[i].lat) / (quad[j].lat - quad[i].lat) + quad[i].lon)) {
            inside = !inside;
        }
    }
    return inside;
		*/
 uint32_t i;
	Point_t a ;
   Point_t b ;
	float cross;
    for (i = 0; i < 4; i++) {
         a = quad[i];
         b = quad[(i + 1) % 4];
        cross = (b.lon - a.lon) * (p.lat - a.lat) - (b.lat - a.lat) * (p.lon - a.lon);
        if (cross > 0) {
            return 0; 
        }
    }
    return 1;

}


void HAL_GPS_parseGPRMC( const char*sentence, GPRMC_Data *data) {
    char temp[120];
	  int field = 0;
  	char *token =0;
    strcpy(temp, sentence);

    token = strtok(temp, ",");
    
    if (strcmp(token, "$GPRMC") != 0) {
            return;
        }

    while (token != NULL) {
        switch (field) {
            case 1: strncpy(data->time, token, 10); data->time[10] = '\0'; break;
            case 2: data->status = token[0];
            if (token[0]=='V') {return;} break;
            case 3: data->latitude = convertToDegrees(token); break;
            case 4: data->lat_dir = token[0]; break;
            case 5: data->longitude = convertToDegrees(token); break;
            case 6: data->lon_dir = token[0]; break;
            case 7: data->speed = my_atof(token); break;
            case 8: strncpy(data->date, token, 6); data->date[6] = '\0'; return;
        }
        token = strtok(NULL, ",");
        field++;
    }
}





void HAL_GPS_sendGPSData(uint8_t UART_SEL,float lat, float lon) {
    char buffer[50];
    sprintf(buffer, "%f, %f\r\n",lat, lon );
    MCAL_UART_TX_STRING(UART_SEL ,buffer);
   
 
}




double convertToDegrees(char *rawValue) {
    double val = my_atof(rawValue);
    int deg = (int)(val / 100);
    double min = val - (deg * 100);
    return deg + (min / 60.0);
}

double my_atof(const char *str) {
    double result = 0.0;
    double fraction = 1.0;
    int sign = 1;

    // Skip leading whitespace
    while (*str == ' ' || *str == '\t') {
        str++;
    }

    // Handle optional + or -
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Integer part
    while (my_isdigit(*str)) {
        result = result * 10.0 + (*str - '0');
        str++;
    }

    // Fractional part
    if (*str == '.') {
        str++;
        while (my_isdigit(*str)) {
            fraction /= 10.0;
            result += (*str - '0') * fraction;
            str++;
        }
    }

    return result * sign;
}


uint8_t my_isdigit(char c) {
    return (c >= '0' && c <= '9');
}


void float_to_string(float number, char *str, int precision) {
    int int_part = (int)number;
    float fraction = number - (float)int_part;
    int i = 0;
    // Handle negative numbers
    if (number < 0) {
        *str++ = '-';
        int_part = -int_part;
        fraction = -fraction;
    }

    // Convert integer part
    sprintf(str, "%d", int_part);
		
    while (*str) str++; // Move to end of current string
if(precision==0)
		{
			*str = '\0'; // Null terminator
			return;
		}
    *str++ = '.'; // Decimal point

    // Convert fractional part
    for ( i = 0; i < precision; i++) {
			 int digit;
        fraction *= 10;
        digit = (int)fraction;
        *str++ = '0' + digit;
        fraction -= digit;
    }

    *str = '\0'; // Null terminator
}




double HAL_GPS_CalculateDistance(double lat1, double lon1, double lat2, double lon2)
{		
	  double dlat;
		double dlon;
	  double a;
		double c;
		double distance;
    lat1 = DEG2RAD(lat1);
    lon1 = DEG2RAD(lon1);
    lat2 = DEG2RAD(lat2);
    lon2 = DEG2RAD(lon2);

     dlat = lat2 - lat1;
     dlon = lon2 - lon1;

     a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = EARTH_RADIUS_KM * c;

    return distance; // KM
}


void HAL_GPS_SaveCoordinates(float lat, float lon, uint32_t block, uint8_t offset)
{
    uint32_t lat_raw, lon_raw;
    memcpy(&lat_raw, &lat, sizeof(float));
    memcpy(&lon_raw, &lon, sizeof(float));

    MCAL_EEPROM_Write(block, offset, lat_raw);
    MCAL_EEPROM_Write(block, offset + 1, lon_raw);
}

void HAL_GPS_LoadCoordinates(float* lat, float* lon, uint32_t block, uint8_t offset)
{
    uint32_t lat_raw, lon_raw;
    MCAL_EEPROM_Read(block, offset, &lat_raw);
    MCAL_EEPROM_Read(block, offset + 1, &lon_raw);

    memcpy(lat, &lat_raw, sizeof(float));
    memcpy(lon, &lon_raw, sizeof(float));
}
