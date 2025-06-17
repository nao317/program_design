#include <stdio.h>
#include "simplestack.h"

int main(void) {
    stackInit();
    printf("Element %d\n", stackElement());
    stackPush(1);
    stackPush(2);
    stackPush(4);
    stackPush(8);
    printf("Element %d\n", stackElement());
    while (!stackIsEmpty()) {
        printf("%d\n", stackPop());
    }
    printf("Element %d\n", stackElement());
    return 0;
}