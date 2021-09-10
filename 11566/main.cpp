#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
//#define DEBUG
//#define int long long
#define MAXN 100020
using namespace std;
int n, x, t, k;
int dp[12*2][12*100];
vector<pair<int,int>> item; //price value

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> n >> x >> t >> k && n){
        memset(dp, 0, sizeof(dp));
        item.clear();

        n++; //include me
        //careful int operator => chop
        int budget = (n * x) / (float) 1.1 - (n * t);

        for(int i = 0; i < k; i++){
            int value=0, sum=0, price;
            cin >> price;
            for(int j = 0; j < n; j++){
                cin >> value;
                sum += value;
            }
            item.push_back(make_pair(price, sum));
            item.push_back(make_pair(price, sum)); // 2(n+1)
        }

        for(int i = 0; i < item.size(); i++){
            int price = item[i].first;
            int value = item[i].second;
            for(int j = n*2; j > 0; j--){
                for(int k = budget; k >= price; k--){
                    dp[j][k] = max(dp[j][k], dp[j-1][k-price] + value);
                    dp[j][k] = max(dp[j][k], dp[j-1][k]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i <= n*2; i++) ans = max(ans, dp[i][budget]);
        cout << setprecision(2) << fixed << (double) ans / n << '\n';
    }
    return 0;
}
