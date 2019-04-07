
#include <stdio.h>
#include <string.h>
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


int ccreate (void* (*start)(void*), void *arg, int prio) {
    return FUNCTION_NOT_IMPLEMENTED;
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

int cidentify (char *name, int size) {
    char members[] = "Theodoro Loureiro Mota - 173230\nRui Cardozo - 120211\nFabio Petkowicz - 118627";
    int members_size = sizeof(members) / sizeof(members[0]);

    if(size < members_size) {
        return FUNCTION_ERROR;
    } else {
        strncpy (name, members, size);
        return FUNCTION_SUCCESS;
    }
}


