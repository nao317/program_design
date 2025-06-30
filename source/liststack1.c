#include <stdlib.h>
#include "liststack1.h"

STACK *newStack(void) {
    STACK *sp;
    sp = (STACK *)malloc(sizeof(STACK));
    if (sp != NULL) {
        sp -> root = NULL;
        sp -> num = 0;
    }
    return sp;
}

void stackPush(STACK *sp, int v) {
    /* ここにプログラムを記述しなさい */
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL) {
        return;
    }
    newNode -> value = v;
    newNode -> next = sp -> root;
    sp -> root = newNode;
    sp -> num++;
}

int stackPop(STACK *sp) {
    /* ここにプログラムを記述しなさい */
    if (sp -> root == NULL) {
        return -1;
    }
    NODE *topNode = sp -> root;
    int v = topNode -> value;
    sp -> root = topNode -> next;
    sp -> num--; /* ノード数の減算 */
    return v;
}

int stackElement(STACK *sp) {
    return sp -> num; /* 記録されているデータ */
}

int stackIsEmpty(STACK *sp) {
    /* ここにプログラムを記述しなさい */
    if (sp -> num == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int stackIsFull(STACK *sp) {
    /* ここにプログラムを記述しなさい */
    return FALSE;
}