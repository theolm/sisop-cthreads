//
// Created by theo on 09/04/19.
//
//Criar as estruturas necessarias para o codio neste arquivo.

#ifndef CTHREAD_STRUCTS_H
#define CTHREAD_STRUCTS_H
#include <bits/sigstack.h>

struct cThread {
    ucontext_t thread_context; //Contexto da thread
    int tid; //identificador da thread
    int priority;
    char stack[SIGSTKSZ];
};

#endif //CTHREAD_STRUCTS_H
