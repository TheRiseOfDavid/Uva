#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t, repeat, kase;

int josephus(int n, int k){
    int s = 0;
    for(int i = 2; i <= n; i++) s = (s+k) % i;
    return s+1;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        kase++;
        int n, survivor=-1;
        cin >> n;
        repeat = 0;

        while(1){
            survivor = josephus(n,2);
            if(survivor == n) break;
            n = survivor;
            repeat++;
        }

        cout << "Case " << kase << ": " << repeat << " " << n << '\n';
    }
    return 0;
}
