//
// Created by theo on 25/04/19.
//

#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include "../include/defines.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"

/*Retorna 0 se filas forem criadas com sucesso*/
int initializeFifos() {
    int a = CreateFila2(&fifoLow);
    int b = CreateFila2(&fifoMedium);
    int c = CreateFila2(&fifoHigh);
    int d = CreateFila2(&fifoBlock);
    printf("Filas criadas %d", (a+b+c+d));
    return a + b + c + d;
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
 * NOT WORKING IDK WHY!
 * Its mandatory check if the fifo is not empty before call this function.
 * @param prio
 * @return s_TCB
 */
struct s_TCB getFromFifo(int prio) {
    /**
     * NOT WORKING! DO NOT USE IT.
     * AFTER GET THE FIRST ELEMENT ALL THE OTHER FIFOS BECOME EMPTY.
     */
    struct s_TCB thread;

    switch (prio) {
        case PRIORITY_HIGH:
            printf("PRIORITY_HIGH");
            FirstFila2(&fifoHigh);
            thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoHigh);
            FirstFila2(&fifoHigh);
            DeleteAtIteratorFila2(&fifoHigh);
            break;
        case PRIORITY_MEDIUM:
            printf("PRIORITY_MEDIUM");
            FirstFila2(&fifoMedium);
            thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoMedium);
            FirstFila2(&fifoHigh);
            DeleteAtIteratorFila2(&fifoMedium);
            break;
        default:
            printf("PRIORITY_LOW");
            FirstFila2(&fifoLow);
            thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoLow);
            FirstFila2(&fifoHigh);
            DeleteAtIteratorFila2(&fifoLow);
            break;
    }

    return thread;
}

void printFifosStatus() {
    printf("\nFifos status High: %d Medium: %d Low: %d\n", FirstFila2(&fifoHigh), FirstFila2(&fifoMedium), FirstFila2(&fifoLow));
}