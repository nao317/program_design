#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplestack.h"

#define MAXLINE 200

int main(void) {
    char buff[MAXLINE];
    int i, size;
    int isPalindrome;

    while (fgets(buff, MAXLINE, stdin) != NULL) {
        size = strlen(buff);

        if (buff[size - 1] == '\n') {
            buff[size - 1] = '\0';
            size--;
        }

        stackInit();
        isPalindrome = TRUE;

        for (i = 0; i < size / 2; i++) {
            stackPush((int)buff[i]);
        }

        if (size % 2 == 1) {
            i++;  // skip center char
        }

        for (; i < size; i++) {
            if (stackPop() != (int)buff[i]) {
                isPalindrome = FALSE;
                break;
            }
        }

        if (isPalindrome) {
            printf("回文です\n");
        } else {
            printf("回文ではありません\n");
        }
    }

    return 0;
}
