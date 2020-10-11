#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define N 110
#define M 40
#define INF 1 << 30
using namespace std;
int n , m , dp[N] , val[N] , cost ;

int max_safe(){
    for(int i = 0 ; i < N ; i++)
        dp[i] = 0 ;
    dp[0] = INF ;

    for(int i = 0 ; i < m ; i++){
        for(int j = n ; j > 0 ; j--){
            for(int k = 1 ; k <= j && val[i] >= k ; k++){
                dp[j] = max(dp[j] , min(dp[j-k] , val[i] / k ));
            }
        }
    }
    return dp[n] ;
}

int min_cost(){
    if(cost==0) return 0 ;
    for(int i = 0 ; i <= n ; i++)
        dp[i] = INF ;
    dp[0] = 0 ;

    for(int i = 0 ; i < m ; i++){
        for(int j = n ; j > 0 ; j--){
            for(int k = min(j , val[i] / cost ) ; k > 0 ; k--){
                dp[j] = min(dp[j] , dp[j-k] + val[i]);
                //debug
                //cout << j << ' ' << dp[j] << ' ' << dp[j-k] + val[i] << '\n' ;
            }

        }
    }
    return dp[n] ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    while(cin >> n >> m && (n || m) ){
        for(int i = 0 ; i < m ; i++)
            cin >> val[i] ;
        cost = max_safe() ;
        cout << cost << ' ' << min_cost() << '\n' ;

    }

    return 0;
}
