//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>




void func1(void *arg) {
    csem_t csem = *(csem_t *) arg;

    cwait(&csem);
    int i = 0;
    for (i = 1; i <= 100; i++) {
        printf(". ", i);
        if (i % 2 == 0 && i > 0) {
            cyield();
        }
    }
    csignal(&csem);
}

void func2(void *arg) {
    //cwait(&csem);
    int i = 0;
    for (i = 1; i <= 100; i++) {
        printf("T ", i);

        if (i == 90) {
            //csignal(&csem);
        }

        if (i % 2 == 0 && i > 0) {
            cyield();
        }
    }
}

//void *func2(void *arg) {
//    int i = 0;
//    for (i = 1; i <= 100; i++) {
//        printf("B");
//        if (i % 2 == 0 && i > 0) {
//            cyield();
//        }
//    }
//}


int main(int argc, char *argv[]) {

    //Inicia semaforo
    csem_t csem = *(csem_t *) malloc(sizeof(csem_t));
    csem_init(&csem, 1);

    int func_1_tid = ccreate(func1, (void *)&csem, 1);
    int func_2_tid = ccreate(func1, (void *)&csem, 1);
    
    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}