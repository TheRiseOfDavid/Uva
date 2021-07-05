#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t, n, k, kase;

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n >> k;
        int survivor = 0;
        for(int i = 2; i <= n; i++) survivor = (survivor + k) % i;
        survivor++;
        cout << "Case " << ++kase << ": " << survivor << '\n';
    }
    return 0;
}
