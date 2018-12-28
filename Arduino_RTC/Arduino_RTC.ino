/**
Name of project : Adruino RTC
Date of start   : 28.12.2018
Aim of project  : To make RTC with setting functionality with UART
Version         : v0.1
*/

/* Updates      : v0.1
 * Date 28.12.208        
 *              : UART basic communication added
 */

/* global declarattions */
const char var = 'a';
char receivedByte, byteRead = 0;
 
void setup() {
  // put your setup code here, to run once:
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(var);
  delay(1000);
  /*while (Serial.available())
  {
  receivedByte = (char)Serial.read();
  }
  */

  /*  check if data has been sent from the computer: */
  if (Serial.available()) {
    /* read the most recent byte */
    byteRead = Serial.read();
    /*ECHO the value that was read, back to the serial port. */
    Serial.write(byteRead);
    byteRead = Serial.read();
    Serial.write(byteRead);
    
  }
  //receivedByte = (char)Serial.read();
  //Serial.println(receivedByte);

}
