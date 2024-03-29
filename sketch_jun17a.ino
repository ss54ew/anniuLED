/*
按键控制 LED
按键控制LED的关闭与开启
按一下按钮，LED灯亮，再次按一下按钮，LED灭
*/

#define LED 13       //定义LED引脚为13
#define BUTTON 12    //定义按钮开关引脚为12
int val = 0;        //变量val用来储存按钮状态
int old_val = 0;    //暂存val变量的上一个时间单位

int state = 0;       //0表示LED关闭，1表示打开

void setup(){
  pinMode(LED, OUTPUT);     //设定LED引脚为输出状态
  pinMode (BUTTON,INPUT);   //设定按钮引脚为输入状态
}

void loop(){
  val = digitalRead(BUTTON); //读取按钮状态并储存
  //检查按钮的变化情况
  if((val == HIGH)&&(old_val == LOW)){
    state =1-state;
    delay(40);              //延时简单抗抖动
  }
  old_val = val;            //val下载已经是旧的了，让我们暂存一下

  if (state == 1){
    digitalWrite(LED,HIGH);  //开启LED灯
  }else{
    digitalWrite(LED,LOW);   //关闭LED灯
  }
}
