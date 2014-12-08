#include "../include/send_tire_speed_value.hpp"


/*----- initialize() -----*/
TireSpeedvalue::TireSpeedvalue() {
    fd = open(MOTOR_SERIAL_PORT, O_RDWR);
}


/*----- send_speed() -----*/
void send_speed(int speed) {
    char speed_char[7];
    comv_speed_i2a(speed_char, &speed);
    send_speed(speed_char);
}


/*----- comv_speed_i2a() -----*/
void comv_speed_i2a(char* p_speed_char, int* p_speed) {
    // TODO i2a
}


/*----- send_serial() -----*/
void send_serial(char* p_speed_char) {
    // TODO Send serial
}
