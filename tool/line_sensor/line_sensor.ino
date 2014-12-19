#include "line_sensor.h"

#define SENS_NUM   6  //センサの個数
#define DIV_VAL  900  //センサのしきい値

line_sensor sensors[SENS_NUM];
void setup(){
  Serial.begin(9600);

  //センサ初期化
  sensors[0] = line_sensor(A0,DIV_VAL);
  sensors[1] = line_sensor(A1,DIV_VAL);
  sensors[2] = line_sensor(A2,DIV_VAL);
  sensors[3] = line_sensor(A3,DIV_VAL);
  sensors[4] = line_sensor(A4,DIV_VAL);
  sensors[5] = line_sensor(A5,DIV_VAL);
}

void loop(){

  //ラインの有無をビット形式で表示する
  for(int i = 0;i < SENS_NUM;i++){
    Serial.print(sensors[i].line_find());
  }

//  //センサ値を得る(デバッグ用)
//  for(int i = 0;i < SENS_NUM;i++){
//    sensors[i].line_find();
//    Serial.print(sensors[i].rtnSensVal());
//    Serial.print(" ");
//  }

  Serial.println("");
//  delay(500);
}

