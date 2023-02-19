#include "./BarometerThermohygrometer.h"

void setup()
{
	// Wire(Arduino-I2C)の初期化
	Wire.begin();
	// デバック用シリアル通信は9600bps
	Serial.begin(9600);

	// 初期化
	BTH_Init();

	Serial.println(F("Init done"));
	delay(300);
}

void loop()
{

	BTH_Update();		// センサの値をアップデート
	BTH_Print();		// アップデートした値を表示

  if(BTH_GetHumidity() > 90){
    Serial.println("Arduinoは防水ではありません!!");
  }

  if(BTH_GetTemperature() > 25){
    Serial.println("[???]That's illegal!");
  }

	delay(1000);		// 1000 ms 待つ
}
