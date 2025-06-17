
#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 100
#define MAXLINE 100

int main(void)
{
    int point[MAXDATA][2];
    char buff[MAXLINE];
    int n = 1, i;
    
    while (fgets(buff, MAXLINE, stdin) != NULL) {
	if (sscanf(buff, "%d %d", &point[n][0], &point[n][1]) != 2) {
        fprintf(stderr, "エラー (%d)：  %s", n, buff);
        exit(2);
	}
	
	n++;
    }
    
    for (i = 0; i < n; ++i)
	printf("x = %d, y = %d\n", point[i][0], point[i][1]);

    return 0 ;
}
