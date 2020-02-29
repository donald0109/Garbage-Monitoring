
/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sesores).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    ---------------------
 * | HC-SC04 | Arduino |    | 3 pins  | Arduino |
 * ---------------------    ---------------------
 * |   Vcc   |   5V    |    |   Vcc   |   5V    |
 * |   Trig  |   12    | OR |   SIG   |   13    |
 * |   Echo  |   13    |    |   Gnd   |   GND   |
 * |   Gnd   |   GND   |    ---------------------
 * ---------------------
 * Note: You need not obligatorily use the pins defined above
 * 
 * By default, the distance returned by the distanceRead()
 * method is in centimeters, to get the distance in inches,
 * pass INC as a parameter.
 * Example: ultrasonic.distanceRead(INC)
 *
 * created 3 Apr 2014
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 23 Jan 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 03 Mar 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 *
 * This example code is released into the MIT License.
 */

#include <Ultrasonic.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(9,8,4,5,6,7);
/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(2, 3);
#define trigPin 3
#define echoPin 2
void setup() {
 lcd.begin(16,2); 
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.println("********************************************************* Welcome To Pancake Garbage Monitoring System*****************************************************************");
  Serial.println("  ********         *          *        *  *********           *          *      *  ********* ");
  Serial.println("  *      *        * *         **       *  *                  * *         *     *   *         ");
  Serial.println("  *      *       *   *        * *      *  *                 *   *        *    *    *         ");
  Serial.println("  *      *      *     *       *  *     *  *                *     *       *   *     *         ");
  Serial.println("  ********     *       *      *   *    *  *               *       *      * *       *******   ");
  Serial.println("  *           ***********     *    *   *  *              ***********     * *       *         ");
  Serial.println("  *          *           *    *     *  *  *             *           *    *   *     *         ");
  Serial.println("  *         *             *   *      * *  *            *             *   *    *    *         ");
  Serial.println("  *        *               *  *       **  *           *               *  *     *   *         ");
  Serial.println("  *       *                 * *        *  *********  *                 * *      *  ********* ");
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print("  BIN-ID: 0007");
  int duration, distance;
   digitalWrite(trigPin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH) / 2;
 distance = duration / 29.1;
 Serial.print(distance);
 int n=(45-distance)*2.222;
 lcd.setCursor(0,1);
  if(n>100)
  {   
    lcd.print("PCT:");
    lcd.print(100);   
    lcd.print("%  LVL:CR");
  
  }
  
  else if(n<0)
  {
    lcd.print("PCT: ");
    lcd.print(0);   
    lcd.print("%   LVL:LW");
  }
  else if(n>=90)
  {
    lcd.print("PCT: ");
    lcd.print(n);   
    lcd.print("%  LVL:CR");
  }
  else if(n>=60)
  {
    lcd.print("PCT: ");
    lcd.print(n);   
    lcd.print("%  LVL:HG");
  }
  else if(n>=40)
  {
    lcd.print("PCT: ");
    lcd.print(n);   
    lcd.print("%  LVL:MD");
  }
  else if(n<=9)
  {
    lcd.print("PCT: ");
    lcd.print(n);   
    lcd.print("%   LVL:LW");
  }
  else
  {
    lcd.print("PCT: ");
    lcd.print(n);   
    lcd.print("%  LVL:MD");  
  }
 Serial.println("The level of the garbage is : ");
 
 Serial.print(n);
 Serial.println(" %");
 delay(500);
}
