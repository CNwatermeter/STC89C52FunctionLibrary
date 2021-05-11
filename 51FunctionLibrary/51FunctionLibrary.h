/*
你可以直接调用该文件直接使用其中的函数，这样会省去不少事情
你也可以直接将需要的函数复制到你的代码中去，但是前提是需要你能够大致看懂其中的内容
对我在函数中使用到的变量进行重定义，修改为你自己的变量
*/

typedef unsigned char u8; //代表8位正数
typedef unsigned int u16; //代表16位正数

//函数名：简单延时函数
//功能：这是最初用到的函数，其原理就是让CPU执行一段无意义的减法来消耗时间
//其延时的时间并不精确，且与单片机型号以及使用的晶振相关，常用于不精确的延时
//其延时的时间大约等于：12/晶振频率*输入变量delaytime
//输入：延时时间（机器周期）：delaytime
//输出：无
void delay(u16 delaytime){
  while(delaytime --);
}
//函数名：准精确延时函数-毫秒
//功能：延时函数的加强版，输入晶振频率和需要延时的时间（毫秒），无需计算
//其延时的时间大约等于输入变量delaytimems毫秒
//输入：延时时间（毫秒）：delaytimems
//      晶振频率（MHz取整）：CrystalOscillator
//输出：无
void delayms(u16 delaytimems,u8 CrystalOscillator){
  u16 delaytimems2 = 12 * 100 / CrystalOscillator * delaytimems;
  while(delaytimems2 --);
}

//函数名：无源蜂鸣器函数
//功能：
//输入：频率，占空比
//输出：无
/*sbit beep = P1^5;
void beeping(u16 BeepFrequency,u8 BeepDutyCycle){
  u16 DelayHigh ; 
  u16 DelayLow;

  beep = 1;
  delay(100);
  beep = 0;
  delay(100);  
}*/