#include <wiringPi.h>
#include <stdio.h>

#define LedPin 0

int main(void) {
	if(wiringPiSetup() == -1) {
//failure notification message
		printf("setup wiringPi failed !\n");
		return -1;
	}

	pinMode (LedPin, OUTPUT);
	while(1) {
		digitalWrite(LedPin, LOW); //Led On
		printf("led on\n");
		delay(1000); //wait 1 sec

		digitalWrite(LedPin, HIGH); //Led Off
		printf("led off\n");
		delay(1000); //wait 1 sec
	}
	return 0;
}

