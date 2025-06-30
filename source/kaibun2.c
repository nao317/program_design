#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

#define MAXLINE 200

int main(void) {
    char buff[MAXLINE];
    int i, size;
    int flag;

    while(fgets(buff, MAXLINE, stdin) != NULL) {
        size = strlen(buff);
        if (buff[size - 1] == '\n') {
            buff[size - 1] = '\0';
            size--;
        }
        STACK *sp = newStack();
        if(sp == NULL) {
            fprintf(stderr, "error\n");
            exit(1);
        }

        flag = TRUE;

        for (i = 0; i < size / 2; i++) {
            stackPush(sp, (int)buff[i]);
        }

        if (size % 2 == 1) {
            i++;
        }

        for (; i < size; i++) {
            if (stackPop(sp) != (int)buff[i]) {
                flag = FALSE;
                break;
            }
        }

        if (flag) {
            printf("回文です\n");
        } else {
            printf("回文ではありません\n");
        }
        
        free(sp);
    }
    return 0;
}
