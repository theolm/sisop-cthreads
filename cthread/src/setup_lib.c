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
int flagMainThread = -1;

int initLibrary() {
    if (flagFifos == -1) {
        flagFifos = 0;
        initializeFifos();
    }

    if (flagEscalonador == -1) {
        flagEscalonador = 0;
        initEscalonador();
    }

    if(flagMainThread == -1) {
        flagMainThread = 0;
        initMainThread();
    }

    return FUNCTION_SUCCESS;
}

int initMainThread() {
    active_thread.tid = 0;
    active_thread.cjoin_tid = -1;
    active_thread.context.uc_stack.ss_sp = active_thread.stack; //Stack da thread
    active_thread.context.uc_stack.ss_size = sizeof(active_thread.stack);
    active_thread.prio = PRIORITY_LOW;

    int control = -1;
    getcontext(&active_thread.context);

    if(control == -1) {
        control = 0;
        setcontext(&active_thread.context);
    }

    return FUNCTION_SUCCESS;
}

int initEscalonador() {
    getcontext(&escalonador_context);
    escalonador_context.uc_stack.ss_sp = escalonador_stack;
    escalonador_context.uc_stack.ss_size = sizeof(escalonador_stack);
    makecontext(&escalonador_context, (void (*)(void)) escalonador, 1);
    return FUNCTION_SUCCESS;
}