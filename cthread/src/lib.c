
#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <bits/sigstack.h>
#include <stdlib.h>
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"
#include "../include/defines.h"
#include "../include/escalonador.h"
#include "../include/setup_lib.h"


/***
 * FUNCOES DA CTHREADS.H
***/
int isInit = -1;

int teste() {
    int i;
    for (i =0; i <=5; i++ ) {
        printf("TESTE\n");
    }
}

int ccreate(void *(*start)(void *), void *arg, int prio) {
    if (isInit == -1) {
        isInit = 0;
        initLibrary();
    }

    int status = 0;

    /*Contexto e estrutura da thead nova*/
    struct s_TCB new_thread;

    new_thread.tid = Random2(); //Inicia i id da thread
    getcontext(&new_thread.context);

    new_thread.context.uc_link = &dispatcher_context; //Salva thread de retorno (uc_link)
    new_thread.context.uc_stack.ss_sp = new_thread.stack; //Stack da thread
    new_thread.context.uc_stack.ss_size = sizeof(new_thread.stack);
    new_thread.prio = prio; //Salva prioridade na estrutura

    makecontext(&new_thread.context, (void (*)(void)) start, 1);

    //TESTE --------------
    struct s_TCB teste_thread;

    teste_thread.tid = Random2(); //Inicia i id da thread
    getcontext(&teste_thread.context);

    teste_thread.context.uc_link = &dispatcher_context; //Salva thread de retorno (uc_link)
    teste_thread.context.uc_stack.ss_sp = teste_thread.stack; //Stack da thread
    teste_thread.context.uc_stack.ss_size = sizeof(teste_thread.stack);
    teste_thread.prio = prio; //Salva prioridade na estrutura

    makecontext(&teste_thread.context, (void (*)(void)) teste, 1);
    //------------

    switch (prio) {
        case PRIORITY_HIGH:
            AppendFila2(&fifoHigh, &new_thread);
            AppendFila2(&fifoHigh, &teste_thread);
            break;
        case PRIORITY_MEDIUM:
            AppendFila2(&fifoMedium, &new_thread);
            break;
        case PRIORITY_LOW:
            AppendFila2(&fifoLow, &new_thread);
            break;
    }


    int saveMain = -1;
    saveMainThread();

    if (saveMain == -1) {
        saveMain = 0;
        dispatcher();
    }

    return status;
}

/**
 * tid: Na versão 2019/01, deixar sempre esse campo
 * como NULL
 **/
int csetprio(int tid, int prio) {
    return FUNCTION_NOT_IMPLEMENTED;
}


int cyield(void) {
    return FUNCTION_NOT_IMPLEMENTED;
}

int cjoin(int tid) {
    return FUNCTION_NOT_IMPLEMENTED;
}

int csem_init(csem_t *sem, int count) {
    return FUNCTION_NOT_IMPLEMENTED;
}

int cwait(csem_t *sem) {
    return FUNCTION_NOT_IMPLEMENTED;
}

int csignal(csem_t *sem) {
    return FUNCTION_NOT_IMPLEMENTED;
}

int cidentify(char *name, int size) {
    char members[] = "Theodoro Loureiro Mota - 173230\nRui Cardozo - 120211\nFabio Petkowicz - 118627";
    int members_size = sizeof(members) / sizeof(members[0]);

    if (size < members_size) {
        return FUNCTION_ERROR;
    } else {
        strncpy(name, members, size);
        return FUNCTION_SUCCESS;
    }
}