#include "./Camera2.h"
#include "./IMU.h"
#include "./Light.h"
#include "./Servo.h"


uint16_t loop_count = 0;

void setup()
{
	// Wire(Arduino-I2C)の初期化
	Wire.begin();
	// デバック用シリアル通信は9600bps
	Serial.begin(9600);

//	SD_Init();			// これは絶対最初に初期化！
//	CAM2_Init();		// SDの後！
	IMU_Init();
//	LIT_Init();
	SRV_Init();

	Serial.println(F("Init done"));
	delay(300);
}

void loop()
{
	IMU_UpdateAll();
//	IMU_PrintAcc();
//	IMU_PrintGyr();
//	LIT_Print();

//	if (loop_count % 10 == 3) {
//		CAM2_TakePic();
//	}
//	SD_Write(String(loop_count));
  int x = IMU_GetMagX();
  int y = IMU_GetMagY();

  Serial.print("X = " + x);
  Serial.print(" ");
  Serial.println("Y = " + y);
	Serial.println(" Loops = " + loop_count);
	loop_count++;
}
