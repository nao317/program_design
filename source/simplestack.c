#include "simplestack.h"

#define MAXSTACK 100

typedef struct stack {
    int data[MAXSTACK];
    int index;
} STACK;

STACK stk;

void stackInit(void) {
    stk.index = 0;
}

void stackPush(int v) {
    stk.data[stk.index++] = v;
}

int stackPop(void) {
    return stk.data[--stk.index];
}

int stackElement(void) {
    return stk.index;
}

int stackIsEmpty(void) {
    if (stk.index <= 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int stackIsFull(void) {
    if (stk.index >= MAXSTACK) {
        return TRUE;
    } else {
        return FALSE;
    }
}