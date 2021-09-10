#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 100020
using namespace std;
int t;
int c[5];
int d[5];
int q, v;
int dp[MAXN];

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < 4; i++) cin >> c[i];
        cin >> q;

        dp[0] = 1;
        for(int i = 0; i < 4; i++){
            for(int j = c[i]; j < MAXN; j++){
                dp[j] += dp[j - c[i]];
            }
        }

        while(q--){
            for(int i = 0; i < 4; i++) cin >> d[i];
            cin >> v;

            int ans = 0;
            for(int i = 0; i <= 16-1; i++){
                int x = v, flag = 1;
                for(int j = 0; j < 4; j++){
                    if(i & (1 << j)){
                        flag = -flag;
                        x -= c[j] * (d[j]+1);
                    }
                }
                if(x >= 0) ans += flag * dp[x];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
