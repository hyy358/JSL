#ifndef __RFIDCARD_H__
#define __RFIDCARD_H__
#include "config.h"

#define CARD_BUF_LEN 9

extern volatile uint8_t CardRt;

extern uint8_t CardCode[5];
extern bool CardReadOK;
extern bool CardGetOk;
void CardReadInit(void);
void CardIrq(void);
void CardMsTask(void);
void CheckRfidCard(void);
#endif
