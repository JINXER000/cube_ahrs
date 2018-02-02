#ifndef __MYIIC_H
#define __MYIIC_H
#include "sys.h" 


//IO��������
#define SDA_IN()  {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//PB9����ģʽ
#define SDA_OUT() {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} //PB9���ģʽ
#define IIC_SDA_Out() SDA_OUT() ;
#define  IIC_SDA_In() SDA_IN();
//IO��������	 
#define IIC_SCL    PBout(8) //SCL
#define IIC_SDA    PBout(9) //SDA	 
#define READ_SDA   PBin(9)  //����SDA 

//another  version from AHRS
#define IIC_SCL_H()      IIC_SCL=1;
#define IIC_SCL_L()     IIC_SCL=0;
#define IIC_SDA_H()      IIC_SDA=1;
#define IIC_SDA_L()      IIC_SDA=0;
#define IIC_SDA_Read()   READ_SDA

//IIC���в�������
//void IIC_Init(void);                //��ʼ��IIC��IO��				 
//void IIC_Start(void);				//����IIC��ʼ�ź�
//void IIC_Stop(void);	  			//����IICֹͣ�ź�
//void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
//u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
//u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
//void IIC_Ack(void);					//IIC����ACK�ź�
//void IIC_NAck(void);				//IIC������ACK�ź�



void IIC_GPIO_Init(void);
int IIC_WriteData(u8 dev_addr,u8 reg_addr,u8 data);
int IIC_ReadData(u8 dev_addr,u8 reg_addr,u8 *pdata,u8 count);


#endif





