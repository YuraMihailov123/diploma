#include <Multiservo.h>

#define pinX1 A1       // ось X джойстика
#define pinY1 A0       // ось Y джойстика
#define pinY2 A2
#define pinX2 A3

Multiservo multiservo1;
Multiservo multiservo2;
Multiservo multiservo3;
Multiservo multiservo4;

int X1;
int Y1; 
int X2;
int Y2;

int angle = 90;

void setup() {
   pinMode(pinX1, INPUT); // указываем пин для джойстика
   pinMode(pinY1, INPUT);  // указываем пин для джойстика
   pinMode(pinX2, INPUT);
   pinMode(pinY2, INPUT);

   Serial.begin(9600);
   
   multiservo1.attach(0);
   multiservo2.attach(1);
   multiservo3.attach(2);
   multiservo4.attach(3);
}
 
void loop() {
   X1 = analogRead(pinX1);      // считываем значение оси X
   Y1 = analogRead(pinY1);      // считываем значение оси Y
   X2 = analogRead(pinX2);
   Y2 = analogRead(pinY2);
   
   X1 = map(X1, 0, 1023, 0, 180); // переводим значение X в новый диапазон
   Y1 = map(Y1, 0, 1023, 60, 150);  // переводим значение Y в новый диапазон
   X2 = map(X2, 0, 1023, -1, 1);
   Y2 = map(Y2, 0, 1023, 0, 180);

   //angle+=X2;
   //if(angle<180 && angle>=0){
   multiservo1.write(Y1);                      // поворачиваем первый серво
   multiservo2.write(Y1); 
   //}// поворачиваем второй серво
   multiservo3.write(X1);
   multiservo4.write(Y2);
   Serial.println(X2);
   delay(15);
}
