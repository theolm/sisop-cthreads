
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

ucontext_t test_thread;
char test_stack[SIGSTKSZ];
int teste() {
    int i;
    for (i =0; i <=5; i++ ) {
        printf("TESTE\n");
    }
}

//int addTestThreads() {
//    int prio = PRIORITY_LOW;
//
//    struct s_TCB test1;
//    getcontext(&test1.context);
//    test1.context.uc_link = &dispatcher_context; //Salva thread de retorno (uc_link)
//    test1.context.uc_stack.ss_sp = test1.stack; //Stack da thread
//    test1.context.uc_stack.ss_size = sizeof(test1.stack);
//    test1.prio = prio; //Salva prioridade na estrutura
//    makecontext(&test1.context, (void (*)(void)) teste, 1);
//
////    struct s_TCB test2;
////    test2.context.uc_link = &dispatcher_context; //Salva thread de retorno (uc_link)
////    test2.context.uc_stack.ss_sp = test1.stack; //Stack da thread
////    test2.context.uc_stack.ss_size = sizeof(test1.stack);
////    test2.prio = prio; //Salva prioridade na estrutura
////    makecontext(&test2.context, (void (*)(void)) teste, 1);
////
////    struct s_TCB test3;
////    test3.context.uc_link = &dispatcher_context; //Salva thread de retorno (uc_link)
////    test3.context.uc_stack.ss_sp = test1.stack; //Stack da thread
////    test3.context.uc_stack.ss_size = sizeof(test1.stack);
////    test3.prio = prio; //Salva prioridade na estrutura
////    makecontext(&test3.context, (void (*)(void)) teste, 1);
//
//
//    //addThreadToFifo(&test1, prio);
//    //addThreadToFifo(&test2, prio);
//    //addThreadToFifo(&test3, prio);
//
//    return FUNCTION_SUCCESS;
//}

int saveMain = -1;
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

    new_thread.context.uc_link = &escalonador_context; //Salva thread de retorno (uc_link)
    new_thread.context.uc_stack.ss_sp = new_thread.stack; //Stack da thread
    new_thread.context.uc_stack.ss_size = sizeof(new_thread.stack);
    new_thread.prio = prio; //Salva prioridade na estrutura

    makecontext(&new_thread.context, (void (*)(void)) start, 1);

    addThreadToFifo(&new_thread, prio);

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

    getcontext(&active_thread.context);
    if(control == -1) {
        control = 0;
        addThreadToFifo(&active_thread, active_thread.prio);
        dispatcher();
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