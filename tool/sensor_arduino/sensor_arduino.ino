void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i <= 63; i++) {
    char str[20];
    //itoa(i+10, str, 10);
    //i = 0x0;
    sprintf(str, "%x", i+0x10);
    Serial.println(str);
    delay(500);
  }
}
