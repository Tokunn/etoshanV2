#include "../include/send_tire_speed_value.hpp"

#include <stdio.h>


/*----- initialize() -----*/
TireSpeedvalue::TireSpeedvalue() {
    fd = open(MOTOR_SERIAL_PORT, O_RDWR);
}


/*----- send_speed() -----*/
void TireSpeedvalue::send_speed(int speed) {
    char speed_char[7];
    //printf("\tGet int is %06d", speed);
    comv_speed_i2a(speed_char, &speed);
    send_serial(speed_char);
}


/*----- comv_speed_i2a() -----*/
void TireSpeedvalue::comv_speed_i2a(char* p_speed_char, int* p_speed) {
    sprintf(p_speed_char, "%06d", *p_speed);
    //printf("\tSend char is %s\n", p_speed_char);
}


/*----- send_serial() -----*/
void TireSpeedvalue::send_serial(char* p_speed_char) {
    p_speed_char[6] = '\n';
    write(fd, p_speed_char, 7);
}
