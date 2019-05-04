//
// Created by theo on 01/05/19.
//

#ifndef CTHREAD_SETUP_LIB_H
#define CTHREAD_SETUP_LIB_H

int initLibrary();
int initMain();
int saveMainThread();

ucontext_t main_context;
struct s_TCB main_thread;

#endif //CTHREAD_SETUP_LIB_H
