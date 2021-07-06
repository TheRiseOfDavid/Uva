#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1000020
using namespace std;
int t, n, k, kase = 0;
int profit[MAXN]

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> profit[i];
            profit *= -1;
        }
        int y;
        for(int i = 0; i < n; i++){
            cin >> y;
            profit[i] += y;
        }
        sort(profit, profit+n);

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(k && profit[i] < 0){
                k--;
                continue;
            }
            ans += profit[i];
        }

        if(ans > 0) cout << "Case " << ++kase << ": " << ans << '\n';
        else cout << "Case " << ++kase << ": No Profit" << '\n';
    }
    return 0;
}
