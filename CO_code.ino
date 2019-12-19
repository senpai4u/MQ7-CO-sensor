/*  
 MQ-7 cheater  
 Uses PWM and an N-Channel MosFET to trick an ICSTATION MQ-7 CO detector  
 into measuring CO according to the datasheet of the manufaturer.  
 */  
 #include "MQ7.h"
 int sensorPin = A0;  // select the input pin for the CO sensor  
 int sensorValue = 0; // variable to store the value coming from the sensor  
 // Initial setup  
 void setup() {  
  // initialize digital pin LED_BUILTIN as an output  
  pinMode(LED_BUILTIN, OUTPUT);  
  // initialize the serial port  
  Serial.begin(9600);  
 }  
 // the loop function runs over and over again forever  
 void loop() {  
  analogWrite(LED_BUILTIN, 255);  // turn the heater fully on  
  delay(60000);            // heat for 60 second  
 // now reduce the heating power  
  analogWrite(LED_BUILTIN, 72);  // turn the heater to approx 1,4V  
  delay(90000);            // wait for 90 seconds  
 // we need to read the sensor at 5V, but must not let it heat up. So hurry!  
   digitalWrite(LED_BUILTIN, HIGH);  
  delay (50); //don't know how long to wait without heating up too much. Getting an analog read apparently takes 100uSec  
   // read the value from the sensor:  
  sensorValue = analogRead(sensorPin);  
  for (int i = 0; i <= 10; i++)(
  Serial.println(sensorValue));
 }
