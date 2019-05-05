//
// Created by theo on 29/04/19.
//

#include <stdio.h>
#include <string.h>
#include <ucontext.h>
#include <stdlib.h>
#include "../include/defines.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/fifo_manager.h"
#include "../include/escalonador.h"
#include "../include/setup_lib.h"


int escalonador() {
    while (1) {
        unblockCjoin();
        dispatcher();
    }
    return FUNCTION_SUCCESS;
}

int dispatcher() {
    if (FirstFila2(&fifoHigh) == 0) {

        active_thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoHigh);
        FirstFila2(&fifoHigh);
        DeleteAtIteratorFila2(&fifoHigh);
        swapcontext(&escalonador_context, &active_thread.context);

    } else if (FirstFila2(&fifoMedium) == 0) {

        active_thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoMedium);
        FirstFila2(&fifoMedium);
        DeleteAtIteratorFila2(&fifoMedium);
        swapcontext(&escalonador_context, &active_thread.context);

    } else if (FirstFila2(&fifoLow) == 0) {

        active_thread = *(struct s_TCB *) GetAtIteratorFila2(&fifoLow);
        FirstFila2(&fifoLow);
        DeleteAtIteratorFila2(&fifoLow);
        swapcontext(&escalonador_context, &active_thread.context);

    }

    return FUNCTION_SUCCESS;
}


int unblockCjoin() {
    if(FirstFila2(&fifoBlock) == 0) {
        struct s_TCB *block_thread = (struct s_TCB *)malloc(sizeof(struct s_TCB));
        block_thread = (struct s_TCB *) GetAtIteratorFila2(&fifoBlock);

        if(searchForTid(&fifoHigh, block_thread->cjoin_tid) != 0 && searchForTid(&fifoMedium, block_thread->cjoin_tid) != 0 && searchForTid(&fifoLow, block_thread->cjoin_tid) != 0) {
            addThreadToFifo(block_thread, block_thread->prio);
            DeleteAtIteratorFila2(&fifoBlock);
            return FUNCTION_SUCCESS;
        }

        while(NextFila2(&fifoBlock) == 0) {
            block_thread = (struct s_TCB *) GetAtIteratorFila2(&fifoBlock);
            if(searchForTid(&fifoHigh, block_thread->cjoin_tid) != 0 && searchForTid(&fifoMedium, block_thread->cjoin_tid) != 0 && searchForTid(&fifoLow, block_thread->cjoin_tid) != 0) {
                addThreadToFifo(block_thread, block_thread->prio);
                DeleteAtIteratorFila2(&fifoBlock);
                return  FUNCTION_SUCCESS;
            }
        }

        return FUNCTION_ERROR;
    } else {
        return FUNCTION_ERROR;
    }

}


