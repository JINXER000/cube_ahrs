#ifndef __MYIIC_H
#define __MYIIC_H
#include "sys.h" 


//IO方向设置
#define SDA_IN()  {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//PB9输入模式
#define SDA_OUT() {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} //PB9输出模式
#define IIC_SDA_Out() SDA_OUT() ;
#define  IIC_SDA_In() SDA_IN();
//IO操作函数	 
#define IIC_SCL    PBout(8) //SCL
#define IIC_SDA    PBout(9) //SDA	 
#define READ_SDA   PBin(9)  //输入SDA 

//another  version from AHRS
#define IIC_SCL_H()      IIC_SCL=1;
#define IIC_SCL_L()     IIC_SCL=0;
#define IIC_SDA_H()      IIC_SDA=1;
#define IIC_SDA_L()      IIC_SDA=0;
#define IIC_SDA_Read()   READ_SDA

//IIC所有操作函数
//void IIC_Init(void);                //初始化IIC的IO口				 
//void IIC_Start(void);				//发送IIC开始信号
//void IIC_Stop(void);	  			//发送IIC停止信号
//void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
//u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
//u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
//void IIC_Ack(void);					//IIC发送ACK信号
//void IIC_NAck(void);				//IIC不发送ACK信号



void IIC_GPIO_Init(void);
int IIC_WriteData(u8 dev_addr,u8 reg_addr,u8 data);
int IIC_ReadData(u8 dev_addr,u8 reg_addr,u8 *pdata,u8 count);


#endif





