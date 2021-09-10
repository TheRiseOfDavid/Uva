#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 220
using namespace std;
int dp[MAXN];
int s[MAXN], t[MAXN];
int n, money;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> t[i];

    cin >> money;
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = money; j >= s[i]; j--){
            dp[j] = max(dp[j], dp[j - s[i]] + t[i]);
        }
    }
    cout << dp[money] << "\n";
    return 0;
}
