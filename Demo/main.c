#include <reg52.h>
typedef unsigned char u8; //����8λ����
typedef unsigned int u16; //����16λ����
#define GPIO_DIG P0 //�궨������ܶ˿�
sbit beep = P1^5; //�����Ʒ�����
sbit SLA = P2^2;
sbit SLB = P2^3;
sbit SLC = P2^4; //���������ABC��������
sbit K3 = P3^2;
sbit K4 = P3^3;
u8 code SMG[]={ //��ROM�д洢����ܶ��������
  0x3f,0x06,0x5b,0x4f,
  0x66,0x6d,0x7d,0x07,
  0x7f,0x6f,0x77,0x7c,
  0x39,0x5e,0x79,0x71,
};

void delay(u16 time); //��ʱ����
void DigDisplay(long num); //��̬�������ʾ����

long count = 0;
int main(void){ //������
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

void delay(u16 time){ //��ʱ����
  while(time--);
}
void DigDisplay(long num){ //��̬�������ʾ����
  long LED = 10; //LED��Ҫ��ʾ������ܵ�λ����ͬʱ��Ϊ������num����
  u8 numlong = 1; //���ֳ���
  if(num > 99999999){ //���ֳ����򴥷�����������
  while(1){beep = ~beep;delay(100);}}
  while(num / LED){ //�����ֳ���
    LED *= 10;
    numlong ++;} 
  for(LED = 8; LED > 8 - numlong; LED--){ //ÿ��ɨ��ѭ��ִ��8��
    //Ϊ���ø�����������λ��������ܲ���ʾ���������Ҫ�����ֳ��ȴ���ѭ����ʹ��ˢ����������������λ����ֹͣ����ôδɨ�赽������ܾͻ᲻��ʾ����
    switch(LED){
        case(1): SLA = 1;SLB = 1;SLC = 1;break;
        //Ҫ��ʾ��1λҲ����Ҫ����ͼLED8���Ϊ0�͵�ƽ�������Դ�����
        case(2): SLA = 0;SLB = 1;SLC = 1;break;
        case(3): SLA = 1;SLB = 0;SLC = 1;break;
        case(4): SLA = 0;SLB = 0;SLC = 1;break;
        case(5): SLA = 1;SLB = 1;SLC = 0;break;
        case(6): SLA = 0;SLB = 1;SLC = 0;break;
        case(7): SLA = 1;SLB = 0;SLC = 0;break;
        case(8): SLA = 0;SLB = 0;SLC = 0;break;
    }
    GPIO_DIG = SMG[num % 10]; //�ڼ����������ʾ���ּ�
    num /= 10; //���ּ�λ
    delay(100); //���һ��ʱ��ɨ��
    GPIO_DIG = 0x00; //����
  }
}