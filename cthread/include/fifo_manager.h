//
// Created by theo on 25/04/19.
//

#ifndef CTHREAD_FIFO_MANAGER_H
#define CTHREAD_FIFO_MANAGER_H
#include "support.h"
#include "cdata.h"
#include <ucontext.h>

FILA2 fifoLow;
FILA2 fifoMedium;
FILA2 fifoHigh;

/**
 * Return -1 if error
 * Return 0 if created fifos
 * Return 1 if fifos was already created
 * @return
 */
int initFifosIfNeeded();
int addThreadToFifo(struct s_TCB* newThread);
int createMainThreadIfNeeded();


#endif //CTHREAD_FIFO_MANAGER_H
