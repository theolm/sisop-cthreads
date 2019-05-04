//
// Created by theo on 29/04/19.
//

#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <stdlib.h>
#include <bits/sigstack.h>
#include "../include/defines.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"
#include "../include/escalonador.h"
#include "../include/setup_lib.h"


int dispatcher() {
    while (1) {
        printf("\nDispatcher Loop ini\n");

        if (FirstFila2(&fifoHigh) == 0) {
            printf("\nfifoHigh\n");
            active_thread = getFromFifo(PRIORITY_HIGH);
            printf("\nactive_thread high\n");
        } else if (FirstFila2(&fifoMedium) == 0) {
            printf("\nfifoMedium\n");
            active_thread = getFromFifo(PRIORITY_MEDIUM);
            printf("\nctive_thread medium\n");
        } else if (FirstFila2(&fifoLow) == 0) {
            printf("\nfifoLow\n");
            active_thread = getFromFifo(PRIORITY_LOW);
            printf("\nctive_thread low\n");
        } else {
            printf("\nTenta por main\n");
            swapcontext(&dispatcher_context, &main_thread.context);
            printf("\nafter swap main\n");
        }

        printf("\nswap context -> active thread\n");
        swapcontext(&dispatcher_context, &active_thread.context);
        printf("\nafter swap\n");
        printf("\nloop end dispatcher\n");
    }
    return 0;
}


