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


int escalonador() {
    while (1) {
        dispatcher();
    }
    return FUNCTION_SUCCESS;
}

int dispatcher() {

    if (FirstFila2(&fifoHigh) == 0) {
        printf("\nfifoHigh\n");
        active_thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoHigh);
        FirstFila2(&fifoHigh);
        DeleteAtIteratorFila2(&fifoHigh);
        printf("\nswap context -> active thread\n");
        swapcontext(&escalonador_context, &active_thread.context);
        printf("\nafter swap lol\n");
        printf("\nactive_thread high\n");
    } else if (FirstFila2(&fifoMedium) == 0) {
        printf("\nfifoMedium\n");
        active_thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoMedium);
        FirstFila2(&fifoMedium);
        DeleteAtIteratorFila2(&fifoMedium);
        printf("\nswap context -> active thread\n");
        swapcontext(&escalonador_context, &active_thread.context);
        printf("\nafter swap\n");
        printf("\nctive_thread medium\n");
    } else if (FirstFila2(&fifoLow) == 0) {
        printf("\nfifoLow\n");
        active_thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoLow);
        FirstFila2(&fifoLow);
        DeleteAtIteratorFila2(&fifoLow);
        printf("\nswap context -> active thread\n");
        swapcontext(&escalonador_context, &active_thread.context);
        printf("\nafter swap\n");
        printf("\nctive_thread low\n");
    }

    return FUNCTION_SUCCESS;
}


