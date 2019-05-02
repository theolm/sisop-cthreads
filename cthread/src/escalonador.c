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


int dispatcher() {
    getcontext(&dispatcher_context);
    printf("\nDispatcher run\n");

    int high = FirstFila2(&fifoHigh);
    int medium = FirstFila2(&fifoMedium);
    int low = FirstFila2(&fifoLow);

    printf("\nhigh: %d medium: %d low: %d\n", high, medium, low);

    if (high == 0) {
        printf("\nfifoHigh\n");
        struct s_TCB thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoHigh);
        DeleteAtIteratorFila2(&fifoHigh);
        setcontext(&thread.context);
    }
    if (medium == 0) {
        printf("\nfifoMedium\n");
        struct s_TCB thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoMedium);
        DeleteAtIteratorFila2(&fifoMedium);
        setcontext(&thread.context);
    }
    if (low == 0) {
        printf("\nfifoLow\n");
        struct s_TCB thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoLow);
        DeleteAtIteratorFila2(&fifoLow);
        setcontext(&thread.context);
    }


    printf("\nend dispatcher\n");
    return 0;
}


