#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 10020
using namespace std;
int t, n, a, b, ans;
int visit[MAXN];
vector<int> node[MAXN];

int dfs(int root){

    int cnt = 0, flag = 0;
    visit[root] = 1;
    for(int i = 0; i < node[root].size(); i++){
        if(visit[node[root][i]]) continue;
        flag = 1;
        cnt += dfs(node[root][i]);
    }
    cnt += flag;
    //if(cnt > 0) cout << "root " << root << "\n";
    return cnt;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){

        ans = 0;
        cin >> n;
        for(int i = 0; i <= n; i++) node[i].clear();
        for(int i = 0; i < n-1; i++){
            cin >> a >> b;
            node[a].push_back(b);
            node[b].push_back(a);
        }
        ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            memset(visit, 0, sizeof(visit));
            //cout << "i dfs " << i << " " << dfs(i) << "\n";
            ans = min(dfs(i), ans);
        }

        if(ans == 1) ans++;
        cout << ans << "\n";
    }

    return 0;
}
