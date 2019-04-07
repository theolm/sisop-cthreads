//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Iniciou main, teste de nomes dos integrantes\n\n");

    char integrantes[100];

    int result = cidentify(integrantes, 100);

    if(result == 0) {
        printf("%s\n", integrantes);
    } else if (result == -1){
        printf("Erro ao executar cidentify. Verificar tamanho do array de destino.");
    } else if(result == -9) {
        printf("Funcao nao implementada.");
    } else {
        printf("Erro nao especificado.");
    }

    printf("\n%d\n", result);

    exit(0);
}