//
// Created by theo on 29/04/19.
//

#ifndef CTHREAD_ESCALONADOR_H
#define CTHREAD_ESCALONADOR_H

#include "support.h"
#include "cdata.h"
#include <ucontext.h>
#include "fifo_manager.h"

ucontext_t dispatcher_context;
char dispatcher_stack[SIGSTKSZ];
struct s_TCB active_thread;

int dispatcher();
int initDispatcher();



#endif //CTHREAD_ESCALONADOR_H
