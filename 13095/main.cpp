#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define DEBUG
#define MAXN 100020
using namespace std;
int n, q, l, r, idx; //var index error => https://blog.csdn.net/cyril_ki/article/details/109668100
int a[MAXN][12];

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> n){
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++){
            cin >> idx;
            a[i][idx]++;
            for(int j = 0; j < 10; j++) a[i][j] += a[i-1][j];
        }

        cin >> q;
        for(int i = 0; i < q; i++){
            cin >> l >> r;
            int ans = 0;
            for(int j = 0; j < 10; j++){
                if(a[r][j] - a[l-1][j] > 0) ans++;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
