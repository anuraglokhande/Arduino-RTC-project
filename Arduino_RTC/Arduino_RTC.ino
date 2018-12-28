/**
Name of project : Adruino RTC
Date of start   : 28.12.2018
Aim of project  : To make RTC with setting functionality with UART
Version         : v0.2
*/

/* Updates      : v0.1
 * Date 28.12.2018        
 *              : UART basic communication added 
 *              : v0.2
 * Date 28.12.2018
 *              : RTC library is added and working fine with DS1307 for display clock
 *              : But NOT working for setting clock 
 */
/* libraries included */
#include <Wire.h>
#include "DS1307.h"

DS1307 clock;//define a object of DS1307 class

/* global declarattions */
const char var = 'a';
char receivedByte, byteRead = 0;
char flag1 = 0, flag2 = 0, flag3 = 0;
char sec, hr, mn;
void setup() {
  // put your setup code here, to run once:
  // initialize serial:
  Serial.begin(9600);
  clock.begin();
  clock.fillByYMD(2018,12,128);//Jan 19,2013
  clock.fillByHMS(5,38,30);//15:28 30"
  //clock.fillByYMD(2013,1,19);//Jan 19,2013
  //clock.fillByHMS(15,28,30);//15:28 30"
  //clock.fillDayOfWeek(SAT);//Saturday
  clock.setTime();//write time to the RTC chip
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  /*  check if data has been sent from the computer: */
  if (Serial.available()) 
  {
    /* read the most recent byte */
    flag1 = Serial.read();
    Serial.print("a");
    if(flag1 == 0)
    { 
      Serial.print("in");
      hr = Serial.read();
      mn = Serial.read();
      sec = Serial.read();
      clock.fillByHMS(hr,mn,sec);
      clock.setTime();
    }    
  }
  printTime();
}

/*Function: Display time on the serial monitor*/
void printTime()
{
  clock.getTime();
  Serial.print(clock.hour, DEC);
  Serial.print(":");
  Serial.print(clock.minute, DEC);
  Serial.print(":");
  Serial.print(clock.second, DEC);
  Serial.print("  ");
  Serial.print(clock.month, DEC);
  Serial.print("/");
  Serial.print(clock.dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(clock.year+2000, DEC);
  Serial.print(" ");

  Serial.println(" ");
}
