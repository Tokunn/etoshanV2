int sensor_pin[6] = {0, 1, 2, 3, 4, 5};

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int sensor_value[6];
    for (int i = 0; i < 6; i++) {
        sensor_value[i] = analogRead(sensor_pin[i]);
        Serial.print(sensor_value[i]);
        Serial.print(' ');
    }
    Serial.println(' ');
    delay(100);
}
