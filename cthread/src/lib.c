
#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <bits/sigstack.h>
#include "../include/structs.h"
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"

#define FUNCTION_SUCCESS 0
#define FUNCTION_ERROR -1
#define FUNCTION_NOT_IMPLEMENTED -1
#define PRIORITY_HIGH 0
#define PRIORITY_MEDIUM 1
#define PRIORITY_LOW 2
#define TID_MAIN_THREAD 0 /*A main thread tem prioridade baixa*/


int flagFilasCreated = -1; //Caso seja -1 as filas nao foram inizializadas.

FILA2 fifoLow;
FILA2 fifoMedium;
FILA2 fifoHigh;

/***
 * FUNCOES AUXILIARES.
 * PASSAR PARA ARQUIVO SEPARADO DEPOIS.
***/

/*Retorna 0 se filas forem criadas com sucesso*/
int initializeFifos() {
    int a = CreateFila2(&fifoLow);
    int b = CreateFila2(&fifoMedium);
    int c = CreateFila2(&fifoHigh);
    return a + b + c;
}

/***
 * FUNCOES DA CTHREADS.H
***/

int ccreate(void *(*start)(void *), void *arg, int prio) {
    if (flagFilasCreated == -1) {
        int status = initializeFifos();
        if (status == 0) {
            flagFilasCreated = 0;
            printf("Filas criadas");
        } else {
            printf("Erro ao criar filas.");
            return FUNCTION_ERROR;
        }
    }

    ucontext_t main_context; //Contexto da mainThread usada para o uc_link (quando thread terminar/return volta para main)
    struct cThread new_thread; //Estrutura da thread que sera posta na fila.... possivelmente tera que ser alterada ao longo do desenvolvimento.

     new_thread.tid = Random2(); //Inicia i id da thread
    getcontext(&new_thread.thread_context);

    new_thread.thread_context.uc_link = &main_context; //Salva thread de retorno (uc_link)
    new_thread.thread_context.uc_stack.ss_sp = new_thread.stack; //Stack da thread
    new_thread.thread_context.uc_stack.ss_size = sizeof(new_thread.stack);
    new_thread.priority = prio; //Salva prioridade na estrutura

    makecontext(&new_thread.thread_context, (void (*)(void)) start, 0);

    //TODO: falta adicionar na fila correta.

    return new_thread.tid;

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

