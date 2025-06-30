#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "liststack1.h"
#define MAXLINE 200

int main(void)
{
    char buff[MAXLINE];
    int i, j, size;
    int flag;
    flag = TRUE;
    STACK *stk;

    stk = newStack();

    while (fgets(buff, MAXLINE, stdin) != NULL) {
        for (i = 0, j = 0; buff[i] != '\0'; i++) {
            if (isalnum((unsigned char)buff[i])) {
                buff[j++] = toupper((unsigned char)buff[i]);
            }
        }
        buff[j] = '\0';

        size = strlen(buff);
        flag = TRUE;
        for (i = 0; i < size / 2; i++) {
            stackPush(stk, buff[i]);
        }
        if ((size % 2) == 1) {
            i++;
        }

        for (; i < size; i++) {
            int popped = stackPop(stk);
            if (popped != buff[i]) {
                while (!stackIsEmpty(stk)) {
                    stackPop(stk);
                }
                printf("回文ではありません\n");
                flag = FALSE;
                break;
            }
        }

        if (flag) {
            printf("回文です\n");
        }
    }

    return 0;
}
