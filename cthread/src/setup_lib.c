//
// Created by theo on 01/05/19.
//

#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <stdlib.h>
#include "../include/defines.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"
#include "../include/setup_lib.h"
#include "../include/escalonador.h"

int flagFifos = -1;
int flagEscalonador = -1;

int initLibrary() {
    if (flagFifos == -1) {
        flagFifos = 0;
        initializeFifos();
    }

    if (flagEscalonador == -1) {
        flagEscalonador = 0;
        initEscalonador();
    }

    return FUNCTION_SUCCESS;
}

int saveMainThread() {
    main_thread.tid = 0;
    main_thread.context.uc_stack.ss_sp = main_thread.stack; //Stack da thread
    main_thread.context.uc_stack.ss_size = sizeof(main_thread.stack);
    main_thread.prio = PRIORITY_LOW;
    AppendFila2(&fifoLow, &main_thread);
    return FUNCTION_SUCCESS;
}

int initEscalonador() {
    printf("\ninit Escalonador\n");
    getcontext(&escalonador_context);
    escalonador_context.uc_stack.ss_sp = escalonador_stack;
    escalonador_context.uc_stack.ss_size = sizeof(escalonador_stack);
    makecontext(&escalonador_context, (void (*)(void)) escalonador, 1);
    return FUNCTION_SUCCESS;
}