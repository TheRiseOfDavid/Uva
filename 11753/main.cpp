#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 0x3f3f3f
using namespace std;
int t, n, k, kase=0;
vector<int> num;
int ans_d;

void dfs(int L, int R, int d){
    //cout << "num L R " << num[L] << ' ' << num[R] << '\n';
    if(L >= R ){
        ans_d = min(d, ans_d);
        return;
    }
    if(d > k){
        ans_d = min(k+1, ans_d);
        return;
    }
    if(num[L] == num[R]) dfs(L+1, R-1, d);
    if(num[L] != num[R]){
        dfs(L+1, R, d+1);
        dfs(L, R-1, d+1);
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    cin >> t;
    while(t--){
        num.clear();
        cin >> n >> k;
        int temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            num.push_back(temp);
        }

        ans_d = MAXN;
        dfs(0, num.size()-1, 0);

        //cout << "ans_d " << ans_d << '\n';
        cout << "Case " << ++kase << ": ";
        if(ans_d == 0) cout << "Too easy\n";
        else if(ans_d <= k) cout << ans_d << "\n";
        else if(ans_d > k) cout << "Too difficult\n";
    }


    return 0;
}
