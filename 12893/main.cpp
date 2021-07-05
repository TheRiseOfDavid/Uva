#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int t, n;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL

    cin >> t;
    while(t--){
        cin >> n;
        int cnt = 0;
        while(n){
            cnt += n & 1;
            n >>= 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}
