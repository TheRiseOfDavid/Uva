#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int n, k, ans, component;

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    while(cin >> n >> k){
        ans = 0;
        component = 0;
        while(n){
            ans += n;
            component += n;
            n = component / k;
            component %= k;
        }
        cout << ans << '\n';
    }
    return 0;
}
