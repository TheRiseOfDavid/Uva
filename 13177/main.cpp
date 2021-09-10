#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
//#define DEBUG
#define int long long
#define MAXN 100020
using namespace std;
int p, n;
int num[MAXN];

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> p >> n){
        int L=1, R=0; // L can't min(num[i])
        for(int i = 0; i < n; i++){
            cin >> num[i];
            //L = min(num[i], L);
            R = max(num[i], R);
        }

        int ans = 0;
        while(L <= R){
            int mid = (L+R) / 2, required = 0;
            for(int i = 0; i < n; i++) required += (num[i] + mid - 1) / mid;
            #ifdef DEBUG
                cout << "L R required " << L << ' ' << R << ' ' << required << '\n';
            #endif // DEBUG
            if(required <= p){
                ans = mid;
                R = mid-1;
            }
            else L = mid+1;
        }
        cout << ans << '\n';
    }

    return 0;
}
