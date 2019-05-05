//
// Created by theo on 07/04/19.
//

#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>
#include <stdlib.h>


int func_1_tid = -1;
int func_2_tid = -1;

void* func1(void *arg) {
    int i = 0;
    for (i =1; i <=20; i++ ) {
        printf("A\n");
        if(i%3 == 0) {
            cyield();
        }
    }
}

void* func2(void *arg) {
    cjoin(func_1_tid);
}

int main(int argc, char *argv[]) {
    int a,b;
    func_1_tid = ccreate(func1, (void *)&a, 2);
    func_2_tid = ccreate(func2, (void *)&a, 2);

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}