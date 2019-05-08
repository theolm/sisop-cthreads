//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>


/**
 *
 * Mesmo teste com a anterior, porem com uma thread a mais que printa G.
 * o normal seria uma sequencia de Gs no final, entretanto antes de dar o cwait
 * a tread3 muda sua prioridade para alta, assim aquando o semaforo sinalizar liberacao de recurso
 * a thread com maior prioridade (a que imprime G) vai ser desbloqueada primeiro.
 *
 */

csem_t csem;
void func1(void *arg) {
    cwait(&csem);
    int i = 0;
    for (i = 1; i <= 100; i++) {
        printf(". ", i);

        if (i == 90) {
            csignal(&csem);
        }

        if (i % 2 == 0 && i > 0) {
            cyield();
        }
    }
}

void func2(void *arg) {
    cwait(&csem);
    int i = 0;
    for (i = 1; i <= 100; i++) {
        printf("T ", i);
        if (i == 90) {
            csignal(&csem);
        }

        if (i % 2 == 0 && i > 0) {
            cyield();
        }
    }
}

void func3(void *arg) {
    csetprio(NULL, 0);
    cwait(&csem);
    int i = 0;
    for (i = 1; i <= 100; i++) {
        printf("G ", i);
        if (i == 90) {
            csignal(&csem);
        }

        if (i % 2 == 0 && i > 0) {
            cyield();
        }
    }
}

int main(int argc, char *argv[]) {

    //Inicia semaforo
    csem_init(&csem, 1);
    int func_1_tid = ccreate(func1, (void *)&csem, 1);
    int func_2_tid = ccreate(func2, (void *)&csem, 1);
    int func_3_tid = ccreate(func3, (void *)&csem, 1);
    cyield();

    
    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}