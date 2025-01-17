#ifndef _CAN_HANDLER_H
#define _CAN_HANDLER_H

#include "lpc17xx_can.h"
#include "can_database.h"

void can_handler_init();
void can_handler_send(uint16_t id, uint8_t dlc, uint8_t *data);
void can_handler_receive(uint16_t *id, uint8_t *dlc, uint8_t *data);
void can_rx_int_callback();


#endif
