//
// Created by theo on 01/05/19.
//

#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <stdlib.h>
#include <bits/sigstack.h>
#include "../include/defines.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"
#include "../include/setup_lib.h"
#include "../include/escalonador.h"

int flagFifos = -1;
int flagDispatcher = -1;

int initLibrary() {
    if (flagFifos == -1) {
        flagFifos = 0;
        initializeFifos();
    }

    //Nao precisa
//    if (flagMain == -1) {
//        flagMain = 0;
//        initMain();
//    }

    if (flagDispatcher == -1) {
        flagDispatcher = 0;
        initDispatcher();
    }

    return FUNCTION_SUCCESS;
}


/*Acho que nao precisa de init main... sempre que a main for bloqueada ou ir pra fila de aptos tem que salvar o contexto dela antes de por na fila -> saveMainThread*/
int initMain() {
//    printf("\ninitMain\n");
//
//    struct s_TCB main_thread;
//    main_thread.tid = 0;
//    getcontext(&main_thread.context);
//
//    main_thread.context.uc_stack.ss_sp = main_thread.stack; //Stack da thread
//    main_thread.context.uc_stack.ss_size = sizeof(main_thread.stack);
//    main_thread.prio = PRIORITY_LOW;
//
//    AppendFila2(&fifoLow, &main_thread);
//    printf("\nAdicionou mainThread na fila de baixa prioridade!\n");

    return FUNCTION_SUCCESS;
}

int endMain() {
    exit(0);
}

int saveMainThread() {
    struct s_TCB main_thread;
    main_thread.tid = 0;
    main_thread.context.uc_link = &endMain;
    main_thread.context.uc_stack.ss_sp = main_thread.stack; //Stack da thread
    main_thread.context.uc_stack.ss_size = sizeof(main_thread.stack);
    main_thread.prio = PRIORITY_LOW;
    getcontext(&main_thread.context);
    AppendFila2(&fifoLow, &main_thread);
    return FUNCTION_SUCCESS;
}

int initDispatcher() {
    printf("\ninitDispatcher\n");
    getcontext(&dispatcher_context);

    dispatcher_context.uc_stack.ss_sp = dispatcher_stack;
    dispatcher_context.uc_stack.ss_size = sizeof(dispatcher_stack);
    makecontext(&dispatcher_context, (void (*)(void)) dispatcher, 1);

    return FUNCTION_SUCCESS;
}