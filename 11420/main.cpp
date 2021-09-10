#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 70
using namespace std;
int dp[MAXN][MAXN][2];
int n, s;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    for(int i = 2; i < MAXN-2; i++){
        dp[i][0][0] = dp[i-1][0][0] + dp[i-1][1][1];
        for(int j = 1; j <= i; j++){
            dp[i][j][0] = dp[i-1][j+1][1] + dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1];
        }
    }

    while(cin >> n >> s && n >= 0 && s >= 0){
        cout << dp[n][s][0] + dp[n][s][1] << "\n";
    }
    return 0;
}
