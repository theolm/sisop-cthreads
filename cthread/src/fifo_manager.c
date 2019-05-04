//
// Created by theo on 25/04/19.
//

#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <bits/sigstack.h>
#include "../include/defines.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"

FILA2 fifoLow;
FILA2 fifoMedium;
FILA2 fifoHigh;

/*Retorna 0 se filas forem criadas com sucesso*/
int initializeFifos() {
    int a = CreateFila2(&fifoLow);
    int b = CreateFila2(&fifoMedium);
    int c = CreateFila2(&fifoHigh);
    printf("Filas criadas %d", (a+b+c));
    return a + b + c;
}

int addThreadToFifo(void *newThread, int prio) {
    switch (prio) {
        case PRIORITY_HIGH:
            return AppendFila2(&fifoHigh, newThread);
        case PRIORITY_MEDIUM:
            return AppendFila2(&fifoMedium, newThread);
        case PRIORITY_LOW:
            return AppendFila2(&fifoLow, newThread);
        default:
            return FUNCTION_ERROR;
    }
}

/**
 * Its mandatory check if the fifo is not empty before call this function.
 * @param prio
 * @return s_TCB
 */
struct s_TCB getFromFifo(int prio) {
    struct s_TCB thread;

    switch (prio) {
        case PRIORITY_HIGH:
            //FirstFila2(&fifoHigh);
            thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoHigh);
            DeleteAtIteratorFila2(&fifoHigh);
            break;
        case PRIORITY_MEDIUM:
            //FirstFila2(&fifoMedium);
            thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoMedium);
            DeleteAtIteratorFila2(&fifoMedium);
            break;
        default:
            //FirstFila2(&fifoLow);
            thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoLow);
            DeleteAtIteratorFila2(&fifoLow);
            break;
    }

    return thread;
}