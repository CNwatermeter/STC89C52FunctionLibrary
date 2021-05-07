#include <reg52.h>
typedef unsigned char u8; //代表8位正数
typedef unsigned int u16; //代表16位正数
#define GPIO_DIG P0 //宏定义数码管端口
sbit beep = P1^5; //定义制蜂鸣器
sbit SLA = P2^2;
sbit SLB = P2^3;
sbit SLC = P2^4; //定义译码管ABC三个输入
sbit K3 = P3^2;
sbit K4 = P3^3;
u8 code SMG[]={ //在ROM中存储数码管段码的数组
  0x3f,0x06,0x5b,0x4f,
  0x66,0x6d,0x7d,0x07,
  0x7f,0x6f,0x77,0x7c,
  0x39,0x5e,0x79,0x71,
};

void delay(u16 time); //延时函数
void DigDisplay(long num); //动态数码管显示函数

long count = 0;
int main(void){ //主函数
  IE = 0x85;
  IT0 = 1;
  IT1 = 1;
  while(1){
    DigDisplay(count);
  }
}

void EX_INTO() interrupt 0
{delay(100);
if(K3 == 0)count++;}

void EX_INT1() interrupt 2
{delay(100);
if(K4 == 0)count--;}

void delay(u16 time){ //延时函数
  while(time--);
}
void DigDisplay(long num){ //动态数码管显示函数
  long LED = 10; //LED是要显示的数码管的位数，同时作为除数求num长度
  u8 numlong = 1; //数字长度
  if(num > 99999999){ //数字超长则触发蜂鸣器警报
  while(1){beep = ~beep;delay(100);}}
  while(num / LED){ //求数字长度
    LED *= 10;
    numlong ++;} 
  for(LED = 8; LED > 8 - numlong; LED--){ //每次扫描循环执行8次
    //为了让高于输入数字位数的数码管不显示，因此我们要将数字长度带入循环，使得刷新完输入数字所在位数即停止，那么未扫描到的数码管就会不显示数字
    switch(LED){
        case(1): SLA = 1;SLB = 1;SLC = 1;break;
        //要显示第1位也就是要让如图LED8输出为0低电平，以下以此类推
        case(2): SLA = 0;SLB = 1;SLC = 1;break;
        case(3): SLA = 1;SLB = 0;SLC = 1;break;
        case(4): SLA = 0;SLB = 0;SLC = 1;break;
        case(5): SLA = 1;SLB = 1;SLC = 0;break;
        case(6): SLA = 0;SLB = 1;SLC = 0;break;
        case(7): SLA = 1;SLB = 0;SLC = 0;break;
        case(8): SLA = 0;SLB = 0;SLC = 0;break;
    }
    GPIO_DIG = SMG[num % 10]; //第几个数码管显示数字几
    num /= 10; //数字减位
    delay(100); //间隔一段时间扫描
    GPIO_DIG = 0x00; //消隐
  }
}