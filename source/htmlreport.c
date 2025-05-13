#include <stdio.h>

#define ARRAYSIZE 5

int main(void)
{
    double data[ARRAYSIZE] = {1.2, 2.3, 3.4, 4.5, 5.6} ;
    int i ;

    /* HTMLのヘッダー部分 */
    printf("<HTML>\n<HEAD>\n") ;
    printf("<TITLE>HTMLテスト</TITLE>\n") ;
    printf("</HEAD>\n") ;
    /* 文書の本体の開始 */
    printf("<BODY>\n") ;
    /* 見出しの表示 */
    printf("<H1>HTML作成プログラム</H1>\n") ;
    /* 表のヘッダー部分の開始 */
    printf("<TABLE border=1>\n") ;
    printf("<TR><TH>添字</TH><TH>値</TH></TR>\n") ;

    /* 表の本体部分の出力 */
    for (i = 0; i < ARRAYSIZE; i++) {
	/* 表の本体の１行出力 */
	printf("<TR><TD>%d</TD><TD>%.1f</TD></TR>\n", i, data[i]) ;
    }

    printf("</TABLE>\n") ; /* 表の終端 */
    printf("</BODY>\n") ; /* 文書本体の終端 */
    printf("</HTML>\n") ; /* HTMLの終端 */

    return 0 ;
}

