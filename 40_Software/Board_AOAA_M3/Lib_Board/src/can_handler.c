/*
 * can_handler.c
 *
 *  Created on: 24.05.2015
 *      Author: Abhijeet
 */

#include "can_handler.h"
#include "lpc17xx_pinsel.h"

CAN_MSG_Type CAN_Rx_Msg;

void can_handler_init()
{

	PINSEL_CFG_Type PinCfg;

	/* Initialize CAN1 pin connect */
	PinCfg.Funcnum = 1;
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 0;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 1;
	PINSEL_ConfigPin(&PinCfg);

	CAN_Init(LPC_CAN1, BAUD_RATE);				//Initialize CAN with baud rate of 500 kbps
	CAN_IRQCmd (LPC_CAN1, CANINT_RIE, ENABLE);	//Configure RX Interrupt
	CAN_SetupCBS(CANINT_RIE, can_rx_int_callback);	//configure callback function for CAN RX Interrupt
}

void can_handler_send(uint16_t id, uint8_t dlc, uint8_t *data)
{
	CAN_MSG_Type CAN_Msg;
	CAN_Msg.id     		= id;
    CAN_Msg.len    		= dlc;

    CAN_Msg.format      = STD_ID_FORMAT;

    CAN_Msg.dataA[0]  	= *data++;
    CAN_Msg.dataA[1]  	= *data++;
    CAN_Msg.dataA[2]  	= *data++;
    CAN_Msg.dataA[3]  	= *data++;

    CAN_Msg.dataB[0]  	= *data++;
    CAN_Msg.dataB[1]  	= *data++;
    CAN_Msg.dataB[2]  	= *data++;
    CAN_Msg.dataB[3]  	= *data++;


	CAN_SendMsg(LPC_CAN1, &CAN_Msg);
}

void can_handler_receive(uint16_t *id, uint8_t *dlc, uint8_t *data)
{
	*id  	= CAN_Rx_Msg.id;
	*dlc 	= CAN_Rx_Msg.len;


	*data++	= CAN_Rx_Msg.dataA[0];
	*data++	= CAN_Rx_Msg.dataA[1];
	*data++	= CAN_Rx_Msg.dataA[2];
	*data++	= CAN_Rx_Msg.dataA[3];

	*data++	= CAN_Rx_Msg.dataB[0];
	*data++	= CAN_Rx_Msg.dataB[1];
	*data++	= CAN_Rx_Msg.dataB[2];
	*data++	= CAN_Rx_Msg.dataB[3];

}

void can_rx_int_callback()
{
	CAN_ReceiveMsg (LPC_CAN1, &CAN_Rx_Msg);
}
