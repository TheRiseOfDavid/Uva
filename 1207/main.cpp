#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;


struct LCS{
    int step , max_len ;
}Dp[5000][5000];


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int intX , intY , Min_step , Max_len ;
    string strX , strY ;
    while(cin >> intX >> strX >> intY >> strY ){
        //init
        for(int i = 0 ; i <= intY ; i++){
            Dp[0][i].max_len = 0 ;
            Dp[0][i].step = i ;
        }
        for(int i = 0 ; i <= intX ; i++){
            Dp[i][0].max_len = 0 ;
            Dp[i][0].step = i ;
        }
        Max_len = 0 ;
        Min_step = 0 ;

        //lcs
        for(int i = 1 ; i <= intX ; i++){
            for(int j = 1 ; j <= intY ; j++){
                if(strX[i-1] == strY[j-1]){
                    Dp[i][j].max_len = Dp[i-1][j-1].max_len +1 ;
                    Dp[i][j].step = Dp[i-1][j-1].step ;

                    //debug
                    //cout << strX[i-1] << ' ' << strY[j-1] << ' ' << Dp[i][j].max_len << '\n' ;
                    //cout << strX[i-1] << ' ' << strY[j-1] << ' ' << Dp[i][j].step << '\n' ;
                }
                else{
                    Dp[i][j].max_len = max(Dp[i-1][j].max_len , Dp[i][j-1].max_len ) ;
                    Dp[i][j].step = min( min(Dp[i-1][j-1].step , Dp[i][j-1].step ) , Dp[i-1][j].step ) +1 ;
                }
            }
        }
        cout << Dp[intX][intY].step << '\n' ;
    }
    return 0;
}
