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
    for (i =1; i <=1000; i++ ) {
        printf("A\n", i);
        if(i%5 == 0) {
            cyield();
        }
    }
}

void* func2(void *arg) {
    int i = 0;
    for (i =1; i <=1000; i++ ) {
        printf("B\n", i);
        if(i%5 == 0) {
            cyield();
        }
    }
}




csem_t csem;
int main(int argc, char *argv[]) {
    int a,b;
    func_1_tid = ccreate(func1, (void *)&a, 2);
    func_2_tid = ccreate(func2, (void *)&b, 2);
    cjoin(func_1_tid);
    cjoin(func_2_tid);
    //csem = *(csem_t *)malloc(sizeof(csem_t));
    //csem_init(&csem, 5);

    printf("\n-------------- FINAL DA MAIN -----------------\n");
    exit(0);
}