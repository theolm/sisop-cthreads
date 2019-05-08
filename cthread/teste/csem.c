//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Esse teste cria duas threads de media prioridade, A primeira printa 100 . e a segunda 100 T.
 * Sem semaforo a execucao ficaria ..TT..TT..TT
 *
 * Para Esse teste cada funcao pede um recurso do semaforo csem. Ele tem apenas 1 recurso. Logo
 * A segunda thread deve ficar bloqueada esperando recurso liberar. A func1 libera esse recurso quando contar 90
 * Logo ela deve imprimir ainda 10 .. alternando com a thread 2.
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
    csignal(&csem);
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

int main(int argc, char *argv[]) {

    //Inicia semaforo
    csem_init(&csem, 1);
    int func_1_tid = ccreate(func1, (void *)&csem, 1);
    int func_2_tid = ccreate(func2, (void *)&csem, 1);
    cyield();

    
    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}