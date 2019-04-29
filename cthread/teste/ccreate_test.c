//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>

void* func1(void *arg) {
    int i;
    for (i =0; i <=10; i++ ) {
        printf("%d\n",i);
    }
}

int main(int argc, char *argv[]) {
    int i;
    ccreate(func1, (void *)&i, 0);
    printf("\nacabou 1 create!\n");
    ccreate(func1, (void *)&i, 0);
    printf("\nacabou 2 create!\n");
    //int id2 = ccreate(func1, (void *)&i, 0);
    //int id3 = ccreate(func1, (void *)&i, 0);

    exit(0);
}