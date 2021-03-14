/*
*********************************************************************************************************
*
*	ģ������ : mainģ��
*	�ļ����� : main.h
*	��    �� : V1.0
*
*	Copyright (C), 2013-2014, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#ifndef _MAIN_H_
#define _MAIN_H_

/* ����LCD������� */
#define VER_INFO	"������STM32-V4������  (V1.0d)"

/* ���ڴ��ڴ�ӡ */
/* ���������������̷������� */
#define EXAMPLE_NAME	"999_STM32-V4�������Գ���"
#define EXAMPLE_DATE	"2015-08-09"
#define DEMO_VER	"1.0d"

/* ������״̬�ֶ���, MS = Main Status */
enum
{
	MS_MAIN_MENU = 0,	/* ������ */
	
	MS_HARDWARE_INFO,	/* Ӳ����Ϣ */
	MS_TEST_TOUCH,		/* �������Ͱ��� */
	MS_RADIO,			/* ������ */	
	MS_WM8978_REC,		/* WM8978¼���� */	
	MS_MEMS,			/* MEMS ���������ԣ�I2C�� ���������ǣ������ƣ���ѹ�� */		
	MS_ETH_WEB,			/* ��̫��DM9000��DM9161 WEB������ */
	
	MS_GPS,				/* GPS���� */
	MS_GPRS,			/* GPRSģ����� */	
	MS_MP3			,	/* MP3������״̬ */	
	MS_MASS_STORAGE,	/* SD����NANDģ��U�� */		
	MS_CAMERA,			/* ����ͷ */
	MS_OLED,			/* OLED��ʾ�� */
	
	MS_AD7606,			/* AD7606���ݲɼ�ģ����� */		
	MS_AD7705,			/* AD7705ģ�� */
	MS_ADS1256,			/* ADS1256ģ�� */
	MS_RS485,			/* RS485ͨ�� */
	MS_DAC8501,			/* DAC8501ģ�� */
	MS_DAC8562,			/* DAC8562ģ�� */
	MS_RA8875,			/* RA8875�ֿ�  */

	MS_CALIBRATION	,	/* У׼����״̬ */	

	MS_CAN,				/* CANͨ�� */	
	
	MS_DSO,				/* ʾ���� */
	MS_WIFI,			/* wifiģ�� */		
	
	MS_STEP_MOTO,		/* 5V���ٲ��������28BYJ48 5�� */	
	MS_AD9833,			/* AD9833���η�����ģ�� */
	
	MS_RESERVED			/* �����Ĺ���״̬ */
};

#endif

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/

