
const int trigpin = 3;//提高电平
const int echopin = 2;//接收脉冲信号电脚
float cm; // 距离值
void setup()
{
  Serial.begin(9600);//设定串口
  pinMode(trigpin,OUTPUT);//输出
  pinMode(echopin,INPUT);//输入
}
 
void loop()
{
  //先执行低低电平
  digitalWrite(trigpin, LOW);
  delayMicroseconds(8);
  //先执行高电平 持续10微秒
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  //执行低电平
  digitalWrite (trigpin, LOW);
  /**
  58也很好理解，声音在干燥、摄氏 20度的空气中的传播速度大约为343米/秒，合34,300厘米/秒。或者，我们作一下单位换算，34,300除以1,000,000厘米/微秒。即为：0.0343厘米/微秒，再换一个角度，1/（0.0343 厘米/微秒）即：29.15 微秒/厘米。这就意味着，每291.5微秒表示10CM的距离。1厘米就是29.15微秒。但是发送后到接收到回波，声音走过的是2倍的距离呀。
  所以实际距离就是1厘米，对应58.3微秒。实际上整个测距过程是测的发出声波到收到回波的时间，你的程序里的第一个distance实际上是时间us。所以换成距离cm，要除以58。当然除以58.3可能更精确。所以程序中用 pulseIn(EcoPin, HIGH) / 58.00获取测得的距离。 
   */
  cm=pulseIn(echopin, HIGH)/58.0;
  cm=(int (cm*100.0))/100.0;//取小数点后2位
  //串口输出
  Serial.print("Distance:");
  Serial.print(cm);
  Serial.println("cm");
  delay(500);
}