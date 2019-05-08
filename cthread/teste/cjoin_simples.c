//
// Created by theolm on 5/7/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Esse teste cria 1 thread que printa 5 letras A e da um yield.
 * Essa thread tem prioridade baixa entao vai trocar de execucao com a main.
 * A main vai dar cjoin na Thread 1.
 *
 * Se o cjoin funcionar vai aparecer 100 caracteres A na tela em sequencia.
 * Se der erro a main thread vai terminar.
 *
 * Caso o cjoin funcione, vamos tentar mais um cjoin da main na thread 1.
 * Isso deve resultar num erro, visto que a thread 1 ja tera terminado quando o segundo cjoin for chamado.
 */

void* funcA(void *arg) {
    int i;
    for(i = 0 ; i < 100 ; i++) {
        printf("A");
        if(i%5 == 0) {
            cyield();
        }
    }
}

int main(int argc, char *argv[]) {
    int a = ccreate(funcA, NULL, 2);

    cyield();

    if(cjoin(a) != 0) {
        printf("\nErro ao executar cjoin\n");
    } else {
        if(cjoin(a) != 0) {
            printf("\nErro ao executar segundo cjoin\n");
        }
    }

    cyield();
    cyield();
    cyield();

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}