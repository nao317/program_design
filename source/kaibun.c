#include <stdio.h>
#include <string.h>
#include "simplestack.h"

#define MAXLINE 200

int main(void) {
    char buff[MAXLINE];
    int i, size;

    stackInit();

    while (fgets(buff, MAXLINE, stdin) != NULL) {
        size = strlen(buff);
        size--;
        for (i = 0; i < size/2; i++) {
            stackPush(buff[i]);
        }
        if ((size % 2) == 1) {
            i++;
        }
        for (i = size/2; i < size; i++) {
            if (stackPop() != buff[i]) {
                printf("回文ではありません\n");
                break;
            }
        }
    }
    return 0;
}