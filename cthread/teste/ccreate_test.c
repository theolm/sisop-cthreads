//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

void* func1(void *arg) {
    int i = 0;
    for (i =0; i <=6; i++ ) {
        if(i%2 == 0) {
            printf("%d\n",i);
            //cyield();
        }
    }
}

int main(int argc, char *argv[]) {
    int a;
    ccreate(func1, (void *)&a, 2);
    ccreate(func1, (void *)&a, 2);
    ccreate(func1, (void *)&a, 2);
    ccreate(func1, (void *)&a, 2);

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}