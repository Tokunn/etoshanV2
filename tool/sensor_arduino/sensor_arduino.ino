void setup() {
  Serial.begin(9600);
}

int command[] = {0x00, 0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08,
                 0x18, 0x10, 0x30, 0x20, 0x3F};

void loop() {
  for(int i = 0; i < 13; i++) {
    char str[20];
    //itoa(i+10, str, 10);
    //i = 0x0;
    sprintf(str, "%x", command[i]+0x10);
    Serial.println(str);
    delay(50);
  }
}
