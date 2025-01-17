#ifndef __CAN_HANDLER_H
#define __CAN_HANDLER_H

#include "lpc11xx.h"


void can_handler_init();
void can_handler_send(uint32_t msg_id, uint32_t dlc, uint32_t *data);
void can_handler_receive();

#endif
