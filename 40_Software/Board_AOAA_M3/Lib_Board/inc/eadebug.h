/*****************************************************************************
 *
 *   Copyright(C) 2011, Embedded Artists AB
 *   All rights reserved.
 *
 ******************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * Embedded Artists AB assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. Embedded Artists AB
 * reserves the right to make changes in the software without
 * notification. Embedded Artists AB also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 *****************************************************************************/
#ifndef __DEBUG_H
#define __DEBUG_H

#include "LPC17xx.h"
#include "board.h"
extern uint8_t g_dbbuf[];

#ifdef DEBUG

#define dbg(...) do {\
    sprintf((char*)g_dbbuf, __VA_ARGS__); \
    console_sendString(g_dbbuf); \
  } while(0);


#else
#define dbg(...)
#endif

#endif /* end __DEBUG_H */
/****************************************************************************
**                            End Of File
*****************************************************************************/
