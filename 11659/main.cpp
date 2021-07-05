#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAXN = 25;
int n, a, x, y;
int say_wrong[MAXN], say_correct[MAXN];

int bit_count(int x){
    int cnt = 0;
    while(x){
        if(x & 1) cnt += 1;
        x >>= 1;
    }
    return cnt;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> n >> a && (n+a!=0)){
        memset(say_correct, 0, sizeof(say_correct));
        memset(say_wrong, 0, sizeof(say_wrong));
        for(int i = 0; i < a; i++){
            cin >> x >> y;
            if(y > 0) say_correct[x] |= 1 << y-1;
            if(y < 0) say_wrong[x] |= 1 << -y-1;
        }

        int limit = 1 << n;
        int max1 = 0;
        for(int i = 0; i < limit; i++){
            int necessary_informants = i;
            int flag = 1;
            for(int j = 1; j <= n; j++){
                int necessary_informant = necessary_informants & (1 << j-1);
                int is_wrong = ( ((say_wrong[j] & i) != 0) || ((say_correct[j] & i) != say_correct[j]));

                if(necessary_informant && is_wrong){
                    /*
                    cout << "i is " << i << '\n';
                    cout << "necessary_informant " << necessary_informant << '\n';
                    cout << "j is " << j << '\n';
                    cout << "debug " << say_wrong[j] << ' ' << say_correct[j] << '\n';
                    cout << "info " << ((say_wrong[j] & i) != 0) << ' ' << ((say_correct[j] & i) != say_correct[j]) << '\n';
                    cout << "is_wrong " << is_wrong << '\n';
                    */

                    flag = 0;
                    break;
                }
            }
            if(flag){
                //cout << "i is " << i << '\n';
                max1 = max(bit_count(necessary_informants), max1);
            }
        }
        cout << max1 << '\n';
    }
    return 0;
}
