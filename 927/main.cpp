#include <iostream>
#include <bits/stdc++.h>
#define MAXN 10020
#define int long long
#define LOCAL
using namespace std;
int C, d, k, temp1, clen;
int c[MAXN], a[MAXN];

int solve(){
    int x = d, y = 0, p = 0 ;
    while(p < k){
        y++;
        p = y * (d + x) / 2;
        //cout << "p is" << p << '\n';
        x += d;

    }
    //cout << "y is " << y << '\n';
    int ans = c[0], cnt = y;
    for(int i = 1; i <= clen; i++ ){
        ans += c[i] * cnt;
        //cout << c[i] << ' ' << cnt << '\n';
        cnt *= y;
    }
    return ans;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> C;
    while(C--){
        cin >> clen;
        for(int i = 0; i <= clen; i++) cin >> c[i];
        cin >> d >> k;
        cout << solve() << '\n' ;
    }
    return 0;
}
