//
// Created by theolm on 5/7/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Esse teste cria 2 threads. Todas as threads fazem a mesma coisa,
 * printam 100 vezes uma letra no console, e a cada 5 prints dao um yield.
 * Como todos tem prioridade media vao ficar alterando entre si os prints.
 *
 * Em determinado momento uma Thread vai mudar sua prioridade para alta.
 * Esta thread deve executar ate seu termino, Isso mostra que a mudanca de prioridade
 * esta funcionando.
 */

void* funcA(void *arg) {
    int i;
    for(i = 0 ; i < 100 ; i++) {
        printf("A");

        if(i == 30) {
            csetprio(NULL, 0);
        }

        if(i%5 == 0 && i>0) {
            cyield();
        }
    }
}

void* funcB(void *arg) {
    int i;
    for(i = 0 ; i < 100 ; i++) {
        printf("B");
        if(i%5 == 0 && i > 0) {
            cyield();
        }
    }
}

int main(int argc, char *argv[]) {
    int a = ccreate(funcA, NULL, 1);
    int b = ccreate(funcB, NULL, 1);

    cyield();

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}