//
// Created by theo on 29/04/19.
//

#ifndef CTHREAD_ESCALONADOR_H
#define CTHREAD_ESCALONADOR_H

#include "support.h"
#include "cdata.h"
#include <ucontext.h>
#include "fifo_manager.h"

ucontext_t escalonador_context;
char escalonador_stack[STACK_SIZE];
struct s_TCB active_thread;

int escalonador();
int dispatcher();
int unblockCjoin();

#endif //CTHREAD_ESCALONADOR_H
