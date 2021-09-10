#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define LOCAL
#define DEBUG
#define MAXN 100020
using namespace std;
int t, n, num[MAXN];
string formula;

pair<int,int> process(){
    pair<int,int> x;
    bool post = true; //post true plus, false subtract
    stack<bool> status;
    for(int i = 0; i < formula.length(); i++){
        if(formula[i] == 'x'){
            bool op = post; //operator true plus, false subtract
            if(i != 0 && formula[i-1] == '-') op = !op;
            if(op) x.first++;
            else x.second++;
        }

        if(formula[i] == '('){
            if(i != 0 && formula[i-1] == '-'){
                post = !post;
                status.push(false);
            }
            else status.push(true);
        }
        if(formula[i] == ')'){
            if(status.top() == false) post = !post;
            status.pop();
        }
    }
    return x;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> formula >> n;
        for(int i = 0; i < n; i++) cin >> num[i];
        sort(num, num+n);
        pair<int,int> x = process();

        int ans = 0;
        for(int i = 0; i < x.second; i++) ans -= num[i];
        for(int i = 0; i < x.first; i++) ans += num[n-i-1];
        cout << ans << '\n';
    }
    return 0;

}
