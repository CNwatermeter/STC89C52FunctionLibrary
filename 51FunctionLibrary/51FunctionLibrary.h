/*
�����ֱ�ӵ��ø��ļ�ֱ��ʹ�����еĺ�����������ʡȥ��������
��Ҳ����ֱ�ӽ���Ҫ�ĺ������Ƶ���Ĵ�����ȥ������ǰ������Ҫ���ܹ����¿������е�����
�����ں�����ʹ�õ��ı��������ض��壬�޸�Ϊ���Լ��ı���
*/

typedef unsigned char u8; //����8λ����
typedef unsigned int u16; //����16λ����

//������������ʱ����
//���ܣ���������õ��ĺ�������ԭ�������CPUִ��һ��������ļ���������ʱ��
//����ʱ��ʱ�䲢����ȷ�����뵥Ƭ���ͺ��Լ�ʹ�õľ�����أ������ڲ���ȷ����ʱ
//����ʱ��ʱ���Լ���ڣ�12/����Ƶ��*�������delaytime
//���룺��ʱʱ�䣨�������ڣ���delaytime
//�������
void delay(u16 delaytime){
  while(delaytime --);
}
//��������׼��ȷ��ʱ����-����
//���ܣ���ʱ�����ļ�ǿ�棬���뾧��Ƶ�ʺ���Ҫ��ʱ��ʱ�䣨���룩���������
//����ʱ��ʱ���Լ�����������delaytimems����
//���룺��ʱʱ�䣨���룩��delaytimems
//      ����Ƶ�ʣ�MHzȡ������CrystalOscillator
//�������
void delayms(u16 delaytimems,u8 CrystalOscillator){
  u16 delaytimems2 = 12 * 100 / CrystalOscillator * delaytimems;
  while(delaytimems2 --);
}

//����������Դ����������
//���ܣ�
//���룺Ƶ�ʣ�ռ�ձ�
//�������
/*sbit beep = P1^5;
void beeping(u16 BeepFrequency,u8 BeepDutyCycle){
  u16 DelayHigh ; 
  u16 DelayLow;

  beep = 1;
  delay(100);
  beep = 0;
  delay(100);  
}*/