#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1010
using namespace std;
int dp[MAXN][MAXN] = {} ;
string strA , strB ;
int n , m ;

int lcs(){
    n = strA.length();
    m = strB.length();
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;
    for(int j = 0 ; j <= m ; j++) dp[j][0] = 0 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(strA[i-1] == strB[j-1]) dp[i][j] = dp[i-1][j-1]+1 ;
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return dp[n][m] ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int t ;
    cin >> t ;
    cin.ignore();
    while(t--){
        getline(cin,strA);
        strB = strA ;
        reverse(strB.begin() , strB.end());
        cout << lcs() << '\n' ;
    }

    return 0;
}
