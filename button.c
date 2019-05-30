#include <wiringPi.h>
#include <stdio.h>

#define LedPin 0
#define LedOutput 1

void INOUT(char* ledstate)
{
pinMode(LedPin, OUTPUT);
if (ledstate == "OUTPUT")
{
digitalWrite(LedOutput, HIGH);
}
else if (ledstate == "INPUT")
{
digitalWrite(LedOutput, LOW);
}
else
printf("Error Led Output");
} 

int main(void) {
if(wiringPiSetup() == -1) {
//failure notification message
printf("setup wiringPi failed !\n");
return -1;
}

pinMode (LedPin, INPUT);
INOUT("INPUT");

while(1) {
if (0 == digitalRead(LedPin)){
delay(10);
if (0 == digitalRead(LedPin)){
INOUT("OUTPUT");
printf("Button Pressed\n");
}
}
else if (1 == digitalRead(LedPin)){
delay(10);
if (1 == digitalRead(LedPin)){
while(!digitalRead(LedPin));
INOUT("INPUT");
}
}
}
return 0;
}

