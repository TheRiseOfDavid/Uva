#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1000020
#define int long long
using namespace std;
int t, n, kase = 0;
int height[MAXN], width[MAXN];
int lis[MAXN], lds[MAXN];

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    cin >> t;
    while(t--){
        memset(lis, 0, sizeof(lis));
        memset(lds, 0, sizeof(lds));
        cin >> n;
        for(int i = 0; i < n; i++) cin >> height[i];
        for(int i = 0; i < n; i++) cin >> width[i];


        for(int i = 0; i < n; i++){
            lis[i] = width[i];
            lds[i] = width[i];
            for(int j = 0; j < i; j++){
                if(height[i] > height[j]) lis[i] = max(lis[i], lis[j] + width[i]);
                if(height[i] < height[j]) lds[i] = max(lds[i], lds[j] + width[i]);
            }
        }

        int ans_lis = 0, ans_lds = 0;
        for(int i = 0; i < n; i++){
            ans_lis = max(ans_lis, lis[i]);
            ans_lds = max(ans_lds, lds[i]);
        }

        if(ans_lis >= ans_lds)
            cout << "Case " << ++kase << ". Increasing (" << ans_lis << "). Decreasing (" << ans_lds << ").\n";
        else
            cout << "Case " << ++kase << ". Decreasing (" << ans_lds << "). Increasing (" << ans_lis << ").\n";
    }
    return 0;
}
