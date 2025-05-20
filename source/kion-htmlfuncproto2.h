/* ファイルの内容を構造体の配列に記録しデータ数を返す */
int readfile(char [], struct kisyou [], int) ;
/* HTMLによる気温表の出力 */
void html_report(struct kisyou [], int) ;
/* 配列で渡された気温の平均値を求めて返す */
double kion_heikin(double [], int) ;
/* 配列で渡された気温の最大値を求めて返す */
double kion_max(double [], int) ;
/* 配列で渡された気温の最小値を求めて返す */
double kion_min(double [], int) ;

