
#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <bits/sigstack.h>
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"
#include "../include/defines.h"

/***
 * FUNCOES DA CTHREADS.H
***/
int ccreate(void *(*start)(void *), void *arg, int prio) {
    int status = 0;

    status = status - initFifosIfNeeded();
    status = status - createMainThreadIfNeeded();

    /*Contexto da mainThread usada para o uc_link -> para onde voltar quando acabar o processo??? escalonador?*/
    ucontext_t main_context;

    /*Contexto e estrutura da thead nova*/
    struct s_TCB new_thread;

    new_thread.tid = Random2(); //Inicia i id da thread
    getcontext(&new_thread.context);

    new_thread.context.uc_link = &main_context; //Salva thread de retorno (uc_link)
    new_thread.context.uc_stack.ss_sp = new_thread.stack; //Stack da thread
    new_thread.context.uc_stack.ss_size = sizeof(new_thread.stack);
    new_thread.prio = prio; //Salva prioridade na estrutura

    makecontext(&new_thread.context, (void (*)(void)) start, 0);

    status = status - addThreadToFifo(&new_thread);

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

