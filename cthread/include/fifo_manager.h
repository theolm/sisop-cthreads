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
FILA2 fifoBlock;

/**
 * Return -1 if error
 * Return 0 if created fifos
 * Return 1 if fifos was already created
 * @return
 */
int initializeFifos();
int addThreadToFifo(void *newThread, int prio);
int addToBlockFifo(void *newThread);
void printFifosStatus();
struct s_TCB getFromFifo(int prio);
int searchForTid(PFILA2 fifo, int tid);

#endif //CTHREAD_FIFO_MANAGER_H
