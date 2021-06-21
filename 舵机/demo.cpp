#include <Servo.h>  //arduino Servo库
Servo myservo;

void setup()
{
  myservo.attach(9);//控制数字9
}
 
void loop()
{
  //0转向180
  for(int pos = 0;pos<=180;pos+=1){
    myservo.write(pos);
    delay(20);
  }
  //180转到0
  for(int pos = 180;pos>=0;pos-=1){
     myservo.write(pos);
     delay(20);
  }
  
}