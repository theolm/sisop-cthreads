//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

void* func1(void *arg) {
    int i;
    for (i =0; i <=5; i++ ) {
        printf("%1\n",i);
    }
}

void* func2(void *arg) {
    int i;
    for (i =0; i <=5; i++ ) {
        printf("2\n");
    }
}

void* func3(void *arg) {
    int i;
    for (i =0; i <=5; i++ ) {
        printf("3\n");
    }
}

int main(int argc, char *argv[]) {
    int i;
    ccreate(func1, (void *)&i, 0);
    printf("\nacabou 1 create!\n");

    ccreate(func2, (void *)&i, 1);
    printf("\nacabou 2 create!\n");

    ccreate(func3, (void *)&i, 0);
    printf("\nacabou 3 create!\n");

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}