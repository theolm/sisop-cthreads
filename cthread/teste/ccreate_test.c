//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>

void* func0(void *arg) {
    printf("Eu sou a thread ID0 imprimindo %d\n", *((int *)arg));
    return;
}

void* func1(void *arg) {
    printf("Eu sou a thread ID1 imprimindo %d\n", *((int *)arg));
}

int main(int argc, char *argv[]) {
    int	id0, id1;
    int i;

    id0 = ccreate(func0, (void *)&i, 0);
    id1 = ccreate(func1, (void *)&i, 0);

    printf("Eu sou a main apos a criacao de ID0 = %d e ID1 = %d\n", id0, id1);

    exit(0);
}