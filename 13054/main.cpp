#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
using namespace std;
int c, n, h, ta, tb, kase=0;
int num[MAXN];

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> c;
    while(c--){
        cin >> n >> h >> ta >> tb;
        for(int i = 0; i < n; i++) cin >> num[i];
        sort(num, num+n);

        int L=0, R=n-1, ans=0;

        while(R > L){
            if(ta * 2 > tb && num[R] + num[L] < h){
                R--;
                L++;
                ans += tb;
            }
            else{
                R--;
                ans += ta;
            }
        }
        if(R == L) ans += ta;

        cout << "Case " << ++kase << ": " << ans << '\n';
    }

    return 0;
}
