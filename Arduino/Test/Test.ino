#include "./SD.h"
#include "./Camera2.h"
#include "./BarometerThermohygrometer.h"
#include "./DCMotor.h"
#include "./IMU.h"
#include "./Light.h"
#include "./Servo.h"
#include "./GPS.h"
#include "./XBee.h"


uint16_t loop_count = 0;
double pitch = 90;
double diff_x = 0;
double diff_y = 0;

void setup()
{
	// Wire(Arduino-I2C)の初期化
	Wire.begin();
	// デバック用シリアル通信は9600bps
	Serial.begin(9600);

	//SD_Init();			// これは絶対最初に初期化！
	//CAM2_Init();		// SDの後！
	//BTH_Init();
	DCM_Init();
	IMU_Init();
	//LIT_Init();
	SRV_Init();
	//GPS_Init();
	//XBEE_Init();

	Serial.println(F("Init done"));
  SRV_SetPosition(100);
  SRV_Run();
	delay(3000);
  IMU_UpdateAll();
  IMU_Calibration();
}

void loop()
{
	IMU_UpdateAll();
	//IMU_PrintAcc();
	//IMU_PrintGyr();
	//IMU_PrintMag();
	//GPS_Update();
	//GPS_Print();
	//LIT_Print();
	//BTH_Update();
	//BTH_Print();
	//XBEE_Test();


  double x = IMU_CalMagX();
  double y = IMU_CalMagY();

  // double pitch = asin((y + 500) / 600) / 3.14159 * 180;
  // pitch = pitch + 360;
  // if(x < -500){
  //   pitch = 540 - pitch;
  // }
  // while(pitch >= 360){
  //   pitch -= 360;
  // }

  if (y < -15) {
    int d = 1;
    if (y < -150) {
      d = 2;
    }
    pitch += d;
  } else if (y > 15) {
    int d = 1;
    if (y > 150) {
      d = 2;
    }
    pitch -= d;
  }
  // Serial.println(pitch);
  // Serial.println("");

  if(pitch > 180)pitch = 180;
  if(pitch < 1)pitch = 1;
  SRV_SetPosition(180 - pitch);
  SRV_Run();

/*
	if (loop_count % 10 == 3) {
		CAM2_TakePic();
	}
	SD_Write(String(loop_count));

	Serial.println(loop_count);
	if (loop_count % 10 == 0) {
		Serial.println(F("Move Up!"));
		for(uint8_t pos = 0; pos <= 180; pos = pos + 30) {
			Serial.print(F("pos:"));
			Serial.println(pos);
			SRV_SetPosition(pos);
			SRV_Run();
			delay(500);
		}
	}
	if (loop_count % 10 == 5) {
		Serial.println(F("Move Down!"));
		for(uint8_t pos = 180; pos > 0; --pos) {
			Serial.print(F("pos:"));
			Serial.println(pos);
			SRV_SetPosition(pos);
			SRV_Run();
			delay(20);
		}
	}

	// DCは一旦含んでいない（基本的に使わないと考えているため）
*/
	loop_count++;
  // if (1) {
  //   Serial.print("X : ");
  //   Serial.println(IMU_GetMagX());
  //   Serial.print("Y : ");
  //   Serial.println(IMU_GetMagY());
  //   Serial.print("Z : ");
  //   Serial.println(IMU_GetMagZ());
  // }
}

void IMU_Calibration() {
  for (int i=0; i<3; i++) {
    SRV_SetPosition(4+i*86);
    SRV_Run();
    delay(1000);
    for (int j=0; j<10; j++) {
      diff_x += IMU_GetMagX();
      diff_y += IMU_GetMagY();
      delay(10);
    }
  };
  diff_x /= 20;
  diff_y /= 20;
}

double IMU_CalMagX() {
  return IMU_GetMagX() - diff_x;
}

double IMU_CalMagY() {
  return IMU_GetMagY() - diff_y;
}
