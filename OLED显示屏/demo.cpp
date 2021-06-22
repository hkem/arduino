#include <Wire.h>  //Wire库
#include <Adafruit_GFX.h>  //Adafruit_GFX库
#include <Adafruit_SSD1306.h>  //Adafruit_SSD1306库

#define OLED_RESET  4
Adafruit_SSD1306 display(128, 64, &Wire,OLED_RESET);//初始化构造器 屏幕宽度，屏幕高度，iic默认 &Wire，复位引脚
void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);//初始化 oled电压，oled通信地址
  display.setTextColor(WHITE);//开像素点发光
  display.clearDisplay();//清屏
  
  display.setTextSize(1); //设置字体大小  
  display.setCursor(35, 10);//设置显示位置
  display.println("10000");

  display.setTextSize(2);//设置字体大小  
  display.setCursor(15, 30);//设置显示位置
  display.println("OLED TEST");
  
  display.display(); // 开显示
  
  //参考博客：https://blog.csdn.net/qq_41477556/article/details/112311181
}
 
void loop()
{
  
}