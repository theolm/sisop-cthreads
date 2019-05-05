
#include <stdio.h>
#include <string.h>
#include <ucontext.h>
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

int saveMain = -1;
int ccreate(void *(*start)(void *), void *arg, int prio) {
    if (isInit == -1) {
        isInit = 0;
        initLibrary();
    }

    int status = 0;

    /*Contexto e estrutura da thead nova*/
    struct s_TCB *new_thread = (struct s_TCB *)malloc(sizeof(struct s_TCB));

    new_thread->tid = Random2(); //Inicia i id da thread
    getcontext(&new_thread->context);

    new_thread->context.uc_link = &escalonador_context; //Salva thread de retorno (uc_link)
    new_thread->context.uc_stack.ss_sp = new_thread->stack; //Stack da thread
    new_thread->context.uc_stack.ss_size = sizeof(new_thread->stack);
    new_thread->prio = prio; //Salva prioridade na estrutura


    makecontext(&new_thread->context, (void (*)(void)) start, 1);

    addThreadToFifo(new_thread, prio);

    saveMainThread();
    swapcontext(&main_thread.context, &escalonador_context);
    printf("Continuou main");

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

    int control = -1;

    struct s_TCB *thread = (struct s_TCB *)malloc(sizeof(struct s_TCB));
    thread->prio = active_thread.prio;
    thread->tid = active_thread.tid;
    thread->context.uc_stack.ss_sp = thread->stack;
    thread->context.uc_stack.ss_size = sizeof(thread->stack);

    getcontext(&thread->context);

    if(control == -1) {
        control = 0;
        addThreadToFifo(thread, thread->prio);
        setcontext(&escalonador_context);
    }

    return FUNCTION_SUCCESS;
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