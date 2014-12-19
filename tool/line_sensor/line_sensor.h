#include <arduino.h>

#ifndef LINE_SENSOR_ONCT2014_USATAN
#define LINE_SENSOR_ONCT2014_USATAN

#define LINE_ON  true
#define LINE_OFF !LINE_ON

class line_sensor{

  private:
    //変数
    int pin;      //センサのピン番号
    int div_val;  //しきい値
    int dst_val;  //距離

  public:
    //関数

    //コンストラクタ
    line_sensor();
    line_sensor(int p_pin, int p_div_val);

    boolean line_find();  //ラインがあるかないか返す

    //デバッグ用
    int rtnSensVal();

};

  //コンストラクタ
  line_sensor::line_sensor(){};
  line_sensor::line_sensor(int p_pin, int p_div_val){
     pin     = p_pin;
     div_val = p_div_val;
   }
  
  //ラインがあるかないか返す
  boolean line_sensor::line_find(){
    dst_val = analogRead(pin);
    if(dst_val > div_val)//しきい値より大きい
      return LINE_ON;
    else                         //しきい値以下
      return LINE_OFF;
  };

  //センサ値を得る(デバッグ用)
  int line_sensor::rtnSensVal(){
    return dst_val;
  }

#endif

