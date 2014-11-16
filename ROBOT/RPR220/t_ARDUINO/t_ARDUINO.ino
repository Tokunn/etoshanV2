#define PIN_SENSOR1 1


void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int sensor1_value = analogRead(PIN_SENSOR1);
    Serial.println(sensor1_value);
}
