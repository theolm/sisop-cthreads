//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

void* func1(void *arg) {
    int i = 0;
    for (i =1; i <=100; i++ ) {
        printf("A\n");

        if(i%2 == 0) {
            cyield();
        }
    }
}

void* func2(void *arg) {
    int i = 0;
    for (i =1; i <=100; i++ ) {
        printf("B\n");
        if(i%2 == 0) {
            cyield();
        }
    }
}

int main(int argc, char *argv[]) {
    int a,b;
    ccreate(func1, (void *)&a, 2);
    ccreate(func2, (void *)&a, 2);
    cyield();
    cyield();
    cyield();

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}