#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 2000
using namespace std;
int t, n;
int num[MAXN];

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> num[i];
        //sort(num, num+n);

        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(num[i] > sum){
                ans++;
                sum += num[i];
            }
            else sum = sum - num[i-1] + num[i];
        }

        cout << ans << '\n';

    }
    return 0;
}
