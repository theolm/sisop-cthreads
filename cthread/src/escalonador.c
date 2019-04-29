//
// Created by theo on 29/04/19.
//

#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <bits/sigstack.h>
#include "../include/defines.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"
#include "../include/escalonador.h"

int dispatcher() {
    printf("\nDispatcher\n");

    int high = FirstFila2(&fifoHigh);
    int medium = FirstFila2(&fifoMedium);
    int low = FirstFila2(&fifoLow);

    struct s_TCB thread = *(struct s_TCB*) GetAtIteratorFila2(&fifoHigh);
    setcontext(&thread.context);

    if (high == 0) {
        printf("\nfifoHigh\n");
        struct s_TCB thread = *(struct s_TCB*) GetAtIteratorFila2(&fifoHigh);
        setcontext(&thread.context);
    } else if (medium == 0) {
        printf("\nfifoMedium\n");
    } else if (low == 0) {
        printf("\nfifoLow\n");
    }

    return 0;
}

