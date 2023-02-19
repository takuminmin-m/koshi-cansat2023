#include "./Light.h"


void setup()
{
	// デバック用シリアル通信は9600bps
	Serial.begin(9600);

	LIT_Init();			// 光センサを初期化

	Serial.println(F("Init done"));
	delay(300);
}

int m;
void loop()
{
	LIT_Print();			// 光センサの値を表示

	//delay(50);				// 50 ms 待つ
	Serial.print(ONM(200, 200));
  Serial.print(" ");
}

//O(NM)の負荷かける
int ONM(int n, int m){
	int k = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			k += i + j * i % 998244353;
		}
	}
	return k;
}