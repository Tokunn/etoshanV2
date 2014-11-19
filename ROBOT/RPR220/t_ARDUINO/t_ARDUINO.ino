#include <EEPROM.h>
#include "sensor_RPR220.h"


int sensor_pin[6] = {0, 1, 2, 3, 4, 5};
int LED_sw1_pin = 7;
int LED_sw2_pin = 8;
int sw1_pin = 10;
int sw2_pin = 11;


void setup()
{
    pinMode(LED_sw1_pin, OUTPUT);
    pinMode(LED_sw2_pin, OUTPUT);
    pinMode(sw1_pin, INPUT);
    pinMode(sw2_pin, INPUT);

    digitalWrite(LED_sw1_pin, HIGH);
    digitalWrite(LED_sw1_pin, HIGH);

    Serial.begin(9600);
    RPR220 sensors;
}

void loop()
{
    int sensor_value;
    RPR220 sensors;
    sensors.set_threshold(sw1_pin, sw2_pin);
    sensor_value = sensors.get_binary();
    //Serial.println(sensor_value);
    delay(100);
}
