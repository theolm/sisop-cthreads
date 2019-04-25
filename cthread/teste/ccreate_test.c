//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>

void* func1(void *arg) {
    int i;
    for (i =0; i <=10; i++ ) {
        printf("%d\n",i);
    }
}

int main(int argc, char *argv[]) {
    int i;
    int id1 = ccreate(func1, (void *)&i, 0);
    int id2 = ccreate(func1, (void *)&i, 0);
    int id3 = ccreate(func1, (void *)&i, 0);

    exit(0);
}