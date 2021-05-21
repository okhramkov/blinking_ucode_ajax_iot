/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== empty.c ========
 */

/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/TRNG.h>
#include <ti/drivers/UART2.h>

#include "ti_drivers_config.h"


#define LENGTH_BYTES 1

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    /* 1 second delay */
    int32_t delay = 1;

    TRNG_Handle trng_handle;
    uint8_t arr [LENGTH_BYTES];
    char chck[32];

    UART2_Handle uart;
    UART2_Params uart_params;


    /* Call driver init functions */
    GPIO_init();
    TRNG_init();




//  True random number generator
    trng_handle = TRNG_open(0, NULL);

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Turn on user LED */
    GPIO_write(CONFIG_GPIO_0, CONFIG_GPIO_LED_ON);

    UART2_Params_init(&uart_params);
    uart_params.baudRate = 115200;
    uart = UART2_open(CONFIG_UART2_0, &uart_params);

    if (uart) {
        UART2_write(uart, "Hello\n\r", sizeof("Hello\n\r"), NULL);
    }
    else {
        while(1);
    }

    while (1) {
        TRNG_getRandomBytes(trng_handle, arr, LENGTH_BYTES);


        delay = arr[0] % 10 + 1;

        memset(chck, 0, 32);
        sprintf(chck, "TRNG: %d\n\r delay: %d\n\r", arr[0], delay);
        UART2_write(uart, chck, 32, NULL);

        sleep(delay);
        GPIO_toggle(CONFIG_GPIO_0);
    }
}
