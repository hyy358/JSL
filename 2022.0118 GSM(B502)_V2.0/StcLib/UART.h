
#ifndef __UART_H
#define __UART_H	 

#include	"config.h"

#define	UART1	1
//#define	UART2	2
#define	UART3	3

#ifdef MP3_MODULE
#define	UART4	4
#endif

#ifdef UART1
#define	COM_TX1_Lenth	200
#define	COM_RX1_Lenth	512
#endif
#ifdef UART2
#define	COM_TX2_Lenth	128
#define	COM_RX2_Lenth	128
#endif
#ifdef UART3
#define	COM_TX3_Lenth	128
#define	COM_RX3_Lenth	128
#endif
#ifdef UART4
#define	COM_TX4_Lenth	128
#define	COM_RX4_Lenth	128
#endif

#define	UART_ShiftRight	0		//ͬ����λ���
#define	UART_8bit_BRTx	(1<<6)	//8λ����,�ɱ䲨����
#define	UART_9bit		(2<<6)	//9λ����,�̶�������
#define	UART_9bit_BRTx	(3<<6)	//9λ����,�ɱ䲨����

#define	UART1_SW_P30_P31	0
#define	UART1_SW_P36_P37	(1<<6)
#define	UART1_SW_P16_P17	(2<<6)
#define	UART1_SW_P43_P44	(3<<6)
#define	UART2_SW_P10_P11	0
#define	UART2_SW_P46_P47	1
#define	UART3_SW_P00_P01	0
#define	UART3_SW_P50_P51	2
#define	UART4_SW_P02_P03	0
#define	UART4_SW_P52_P53	4


#define	TimeOutSet1		50
#define	TimeOutSet2		50
#define	TimeOutSet3		50
#define	TimeOutSet4		50

#define	BRT_Timer1	1
#define	BRT_Timer2	2
#define	BRT_Timer3	3
#define	BRT_Timer4	4

typedef struct
{ 
	u8	id;				//���ں�

	u8	TX_read;		//���Ͷ�ָ��
	u8	TX_write;		//����дָ��
	u8	B_TX_busy;		//æ��־

	u16	RX_Cnt;			//�����ֽڼ���
	u8	RX_TimeOut;		//���ճ�ʱ
	u8	B_RX_OK;		//���տ����
} COMx_Define; 

typedef struct
{ 
	u8	UART_Mode;			//ģʽ,         UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	u8	UART_BRT_Use;		//ʹ�ò�����,   BRT_Timer1,BRT_Timer2
	u32	UART_BaudRate;		//������,       ENABLE,DISABLE
	u8	Morecommunicate;	//���ͨѶ����, ENABLE,DISABLE
	u8	UART_RxEnable;		//��������,   ENABLE,DISABLE
	u8	BaudRateDouble;		//�����ʼӱ�, ENABLE,DISABLE
	u8	UART_Interrupt;		//�жϿ���,   ENABLE,DISABLE
	u8	UART_Polity;		//���ȼ�,     PolityLow,PolityHigh
	u8	UART_P_SW;			//�л��˿�,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17,UART1_SW_P43_P44
} COMx_InitDefine; 

#ifdef UART1
extern	COMx_Define	COM1;
extern	u8	xdata TX1_Buffer[COM_TX1_Lenth];	//���ͻ���
extern	u8 	xdata RX1_Buffer[COM_RX1_Lenth];	//���ջ���
#endif
#ifdef UART2
extern	COMx_Define	COM2;
extern	u8	xdata TX2_Buffer[COM_TX2_Lenth];	//���ͻ���
extern	u8 	xdata RX2_Buffer[COM_RX2_Lenth];	//���ջ���
#endif
#ifdef UART3
extern	COMx_Define	COM3;
extern	u8	xdata TX3_Buffer[COM_TX3_Lenth];	//���ͻ���
extern	u8 	xdata RX3_Buffer[COM_RX3_Lenth];	//���ջ���
#endif
#ifdef UART4
extern	COMx_Define	COM4;
extern	u8	xdata TX4_Buffer[COM_TX4_Lenth];	//���ͻ���
extern	u8 	xdata RX4_Buffer[COM_RX4_Lenth];	//���ջ���
#endif

u8	UART_Configuration(u8 UARTx, COMx_InitDefine *COMx);
#ifdef UART1
void TX1_write2buff(u8 dat);	//д�뷢�ͻ��壬ָ��+1
void PrintString1(u8 *puts);
void Uart1Clear(void);
#endif
#ifdef UART2
void TX2_write2buff(u8 dat);	//д�뷢�ͻ��壬ָ��+1
void PrintString2(u8 *puts);
#endif
#ifdef UART3
void TX3_write2buff(u8 dat);	//д�뷢�ͻ��壬ָ��+1
void PrintString3(u8 *puts);
void Uart3Clear(void);
#endif
#ifdef UART4
void TX4_write2buff(u8 dat);	//д�뷢�ͻ��壬ָ��+1
void Uart4SendBuf(u8 *buf,u8 len);
void Uart4Clear(void);
#endif

void UartTask(void);//1ms
//void COMx_write2buff(COMx_Define *COMx, u8 dat);	//д�뷢�ͻ��壬ָ��+1
//void PrintString(COMx_Define *COMx, u8 *puts);

#endif
