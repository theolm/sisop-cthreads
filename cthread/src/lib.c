
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
    struct s_TCB *new_thread = (struct s_TCB *) malloc(sizeof(struct s_TCB));

    new_thread->tid = Random2(); //Inicia i id da thread
    getcontext(&new_thread->context);

    new_thread->context.uc_link = &escalonador_context; //Salva thread de retorno (uc_link)
    new_thread->context.uc_stack.ss_sp = new_thread->stack; //Stack da thread
    new_thread->context.uc_stack.ss_size = sizeof(new_thread->stack);
    new_thread->prio = prio; //Salva prioridade na estrutura
    new_thread->cjoin_tid = -1;

    makecontext(&new_thread->context, (void (*)(void)) start, 1, arg);

    status += addThreadToFifo(new_thread, prio);

    if (status == 0) {
        return new_thread->tid;
    } else {
        return FUNCTION_ERROR;
    }
}

/**
 * tid: Na versão 2019/01, deixar sempre esse campo
 * como NULL
 **/
int csetprio(int tid, int prio) {
    active_thread.prio = prio;
    return FUNCTION_SUCCESS;
}

int cyield(void) {
    struct s_TCB *thread = (struct s_TCB *) malloc(sizeof(struct s_TCB));
    thread->prio = active_thread.prio;
    thread->tid = active_thread.tid;
    thread->cjoin_tid = -1;
    thread->context.uc_stack.ss_sp = thread->stack;
    thread->context.uc_stack.ss_size = sizeof(thread->stack);

    int control = -1;
    getcontext(&thread->context);

    int status = 0;

    if (control == -1) {
        control = 0;
        status += addThreadToFifo(thread, thread->prio);
        setcontext(&escalonador_context);
    }

    if (status == 0) {
        return FUNCTION_SUCCESS;
    } else {
        return FUNCTION_ERROR;
    }
}

int cjoin(int tid) {
    if (searchForTid(&fifoBlock, tid) == 0) {
        return FUNCTION_ERROR;
    }

    if (searchForTid(&fifoHigh, tid) != 0 && searchForTid(&fifoMedium, tid) != 0 && searchForTid(&fifoLow, tid) != 0) {
        return FUNCTION_ERROR;
    }

    struct s_TCB *thread = (struct s_TCB *) malloc(sizeof(struct s_TCB));
    thread->prio = active_thread.prio;
    thread->tid = active_thread.tid;
    thread->context.uc_stack.ss_sp = thread->stack;
    thread->context.uc_stack.ss_size = sizeof(thread->stack);
    thread->cjoin_tid = tid;

    int control = -1;

    getcontext(&thread->context);

    if (control == -1) {
        control = 0;
        addToBlockFifo(thread);
        setcontext(&escalonador_context);
    }

    return FUNCTION_SUCCESS;
}

int csem_init(csem_t *sem, int count) {
    FILA2 fila = *(FILA2 *) malloc(sizeof(FILA2));
    int status = CreateFila2(&fila);

    sem->fila = &fila;
    sem->count = count;

    if (status == 0) {
        return FUNCTION_SUCCESS;
    } else {
        return FUNCTION_ERROR;
    }
}

/**
 *
 * @param sem : Pointer to the semaphore
 * @return 0 if the semaphore have resource, 1 if the thread have to wait (block), -1 for any error.
 */
int cwait(csem_t *sem) {
    if (sem->count > 0) {
        sem->count = sem->count - 1;
        return FUNCTION_SUCCESS;
    }

    struct s_TCB *thread = (struct s_TCB *) malloc(sizeof(struct s_TCB));
    thread->prio = active_thread.prio;
    thread->tid = active_thread.tid;
    thread->cjoin_tid = -1;
    thread->context.uc_stack.ss_sp = thread->stack;
    thread->context.uc_stack.ss_size = sizeof(thread->stack);

    int control = -1;
    getcontext(&thread->context);

    if (control == -1) {
        control = 0;
        AppendFila2(sem->fila, thread);
        setcontext(&escalonador_context);
    }

    return 1;
}

int csignal(csem_t *sem) {
    if(FirstFila2(sem->fila) != 0) {
        sem->count++;
        return FUNCTION_SUCCESS;
    }

    struct s_TCB *unblock_thread = (struct s_TCB *) malloc(sizeof(struct s_TCB));

    if (pointToFirstWithPrio(sem->fila, PRIORITY_HIGH) == 0) {
        unblock_thread = (struct s_TCB *) GetAtIteratorFila2(sem->fila);
    } else if (pointToFirstWithPrio(sem->fila, PRIORITY_MEDIUM) == 0) {
        unblock_thread = (struct s_TCB *) GetAtIteratorFila2(sem->fila);
    } else if (pointToFirstWithPrio(sem->fila, PRIORITY_LOW) == 0) {
        unblock_thread = (struct s_TCB *) GetAtIteratorFila2(sem->fila);
    } else {
        return FUNCTION_ERROR;
    }

    DeleteAtIteratorFila2(sem->fila);
    addThreadToFifo(unblock_thread, unblock_thread->prio);
    sem->count++;
    return FUNCTION_SUCCESS;
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