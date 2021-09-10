#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN
#define int long long
using namespace std;
int n, num;
priority_queue<int, vector<int>, greater<int> > q;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL


    while(cin >> n && n){
        while(!q.empty()) q.pop(); //clear

        for(int i = 0; i < n; i++){
            cin >> num;
            q.push(num);
        }

        int ans = 0, a, b;
        while(q.size() != 1){
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            q.push(a+b);
            ans += a+b;
        }
        cout << ans << '\n';

    }

    return 0;
}
