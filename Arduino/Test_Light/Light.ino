#include "./Light.h"

Light_t light;



void LIT_Init() {
}

int  LIT_Get() {
	// たくさんとって平均してもいいかも？
	//  >> じゃあ平均します
	int n = 20;
	int value = 0;
	for(int i=0; i<n; i++){
		value += analogRead(PIN_LIT);
	}
	return value / n;
}

void LIT_Print() {
	int value = LIT_Get();
	Serial.print(F("Lit= "));
	Serial.print(value);
	Serial.println(F(""));
}
