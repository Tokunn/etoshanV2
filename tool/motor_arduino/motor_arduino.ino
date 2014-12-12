/*----- setup() -----*/
void setup() {
    Serial.begin(9600);
    for (int i = 0; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }
}


/*----- recive_serial() -----*/
void recive_serial(char *p_recive_data) {
    for (int i = 0; i < 6; i++) {
        p_recive_data[i] = Serial.read();
    }
}


/*----- loop() -----*/
void loop() {
    char recive_data[10];
    if (Serial.available() >= 6) {
        recive_serial(recive_data);
        for (int i = 0; i <= 6; i++) {
            if (recive_data[i] == '0') {
                digitalWrite(i+2, LOW);
            }
            if (recive_data[i] == '1') {
                digitalWrite(i+2, HIGH);
            }
        }
    }
}
