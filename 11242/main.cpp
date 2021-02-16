#include <iostream>
//#include <algorithm>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 20000
using namespace std;
int F,R;
double f[MAXN], r[MAXN], num[MAXN];

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> F >> R && F){
        for(int i = 0; i < F; i++) cin >> f[i];
        for(int i = 0; i < R; i++) cin >> r[i];

        int cnt = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < F; j++){
                num[cnt++] = r[i] / f[j];
            }
        }
        sort(num, num + cnt);
        //for(int i = 0; i < cnt; i++ ) cout << num[i] << ' ';
        //cout << '\n';
        double d, dmax = 1;
        for(int i = 1; i < cnt; i++){
            if(num[i] / num[i-1] >= dmax){
                dmax = num[i] / num[i-1];
                //cout << "num is " << num[i] << ' ' << num[i+1] << '\n';
            }
        }
        cout << fixed << setprecision(2) << dmax << '\n';
    }
    return 0;
}
