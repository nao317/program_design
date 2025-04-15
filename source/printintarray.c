#include <stdio.h>

#define ARRAYSIZE 10

int main(void)
{
    int i ;
    int iarray[ARRAYSIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ;

    for (i = 0; i < ARRAYSIZE; i++) {
	printf("iarray[%d]: %d\n", i, iarray[i]) ;
    }

    return 0 ;
}

