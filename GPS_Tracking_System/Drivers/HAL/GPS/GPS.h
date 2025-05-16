

#ifndef INC_GPS_H_
#define INC_GPS_H_


#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include "LIB/BIT_MATHS.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/UART/UART.h"
#include "MCAL/EEPROM/EEPROM.h"
#define M_PI 3.14159265358979323846
#define EARTH_RADIUS_KM 6371.0
#define DEG2RAD(deg) ((deg) * M_PI / 180.0)
#define STRING_NOT_OK 0
#define STRING_OK 1

typedef struct {
    char time[11];      // HHMMSS.ss
    char status;        // A = valid, V = invalid
    double latitude;    // Degrees
    char lat_dir;       // N/S
    double longitude;   // Degrees
    char lon_dir;       // E/W
    double speed;       // Knots
    char date[7];       // DDMMYY
} GPRMC_Data;

typedef struct {
    float lat;
    float lon;
} Point_t;

typedef struct {
    char* name;
    Point_t corners[4];  
} Region_t;


extern Region_t regions[];

extern volatile char str_uart5[100];
extern volatile uint8_t string_ready_uart5 ;
extern GPRMC_Data GPS_data;

void HAL_GPS_Receive_Handler(char c);
char* HAL_GPS_check_region(float current_lat, float current_lon);
uint32_t point_in_quad(Point_t p, Point_t quad[4]);
void HAL_GPS_Read_Data(GPRMC_Data *data);
void HAL_GPS_parseGPRMC(const char*sentence, GPRMC_Data *data);

void HAL_GPS_sendGPSData(uint8_t UART_SEL,float lat, float lon);

double convertToDegrees(char *rawValue);
double my_atof(const char *str);
uint8_t my_isdigit(char c);
void float_to_string(float number, char *str, int precision);
double HAL_GPS_CalculateDistance(double lat1, double lon1, double lat2, double lon2);
void HAL_GPS_SaveCoordinates(float lat, float lon, uint32_t block, uint8_t offset);
void HAL_GPS_LoadCoordinates(float* lat, float* lon, uint32_t block, uint8_t offset);
#endif /* INC_GPS_H_ */
