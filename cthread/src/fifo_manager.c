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

int flagFilasCreated = -1; //Caso seja -1 as filas nao foram inizializadas.

/*Retorna 0 se filas forem criadas com sucesso*/
int initializeFifos() {
    int a = CreateFila2(&fifoLow);
    int b = CreateFila2(&fifoMedium);
    int c = CreateFila2(&fifoHigh);
    return a + b + c;
}

int initFifosIfNeeded() {
    if (flagFilasCreated == -1) {
        int status = initializeFifos();
        if (status == 0) {
            flagFilasCreated = 0;
            printf("Filas criadas");
            return FUNCTION_SUCCESS;
        } else {
            printf("Erro ao criar filas.");
            return FUNCTION_ERROR;
        }
    } else {
        return 1;
    }
}

int addThreadToFifo(struct s_TCB *newThread) {
    int prio = newThread->prio;

    switch (prio) {
        case PRIORITY_HIGH:
            return AppendFila2(&fifoHigh, &newThread);
        case PRIORITY_MEDIUM:
            return AppendFila2(&fifoMedium, &newThread);
        case PRIORITY_LOW:
            return AppendFila2(&fifoLow, &newThread);
        default:
            return FUNCTION_ERROR;
    }
}

int createMainThreadIfNeeded() {
//TODO: salvar criar s_TCB da main thread caso necessario e adicionar na fila de baixa prioridade
    return 0;
}