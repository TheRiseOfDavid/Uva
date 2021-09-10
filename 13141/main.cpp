#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 90
using namespace std;
int f[MAXN];
int n;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL

    f[1] = 1, f[2] = 1;
    for(int i = 3; i < MAXN; i++){
        f[i] = f[i-1] + f[i-2];
    }

    while(cin >> n && n){
        cout << f[n] << "\n";
    }
    return 0;
}
