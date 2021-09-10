#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 50020
#define int long long
using namespace std;
int t, n, kase = 0;
int a, b, cnt;
vector<int> edge[MAXN];
int visit[MAXN], flag[MAXN];

void dfs(int root){
    if(visit[root]) return;
    visit[root] = 1;
    for(int it : edge[root]){
        dfs(it);
        cnt++;
    }
    visit[root] = 0;
    flag[root] = 1; //avoid loop
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) edge[i].clear();

        for(int i = 0; i < n; i++){
            cin >> a >> b;
            edge[a].push_back(b);
        }

        memset(visit, 0, sizeof(visit));
        memset(flag, 0, sizeof(flag));
        int ans = 0, ans_cnt = 0;

        for(int i = 1; i <= n; i++){
            if(flag[i]) continue;
            cnt = 0;
            dfs(i);
            if(ans_cnt < cnt){
                ans = i;
                ans_cnt = cnt;
            }
        }
        cout << "Case " << ++kase << ": " << ans << "\n";

    }
    return 0;
}
