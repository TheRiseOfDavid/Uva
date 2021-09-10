#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 10020
using namespace std;
int t, n, m, a, b, kase=1, cnt;
vector<int> edge[MAXN];
int stk[MAXN], in_stk[MAXN];
int visit[MAXN];
int lead[MAXN], low[MAXN];
int follow[MAXN];
int stk_index;

void scc(int root){
    if(visit[root]) return;

    visit[root] = low[root] = cnt++;
    stk[++stk_index] = root;
    in_stk[root] = 1;

    for(auto it: edge[root]){
        scc(it);
        if(in_stk[it]) low[root] = min(low[it], low[root]);
    }

    if(visit[root] == low[root]){
        int it;
        do{
            it = stk[stk_index--];
            in_stk[it] = 0;
            lead[it] = root;
        }while(it != root);
    }
}

void isfollow(int root){
    for(auto it: edge[root]){
        if(lead[it] != it) follow[it]++;
        if(lead[root] != lead[it]) follow[lead[it]]++; //如果可以從 A強通道走道 B 強通道，就刪掉 B 強通道的開燈點
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            edge[i].clear();
        }

        for(int i = 1; i <= m; i++){
            cin >> a >> b;
            edge[a].push_back(b);
        }

        memset(visit, 0, sizeof(visit));
        for(int i = 1; i <= n; i++){
            if(visit[i]) continue;
            stk_index = -1; cnt = 1;
            scc(i);
        }
        //cout << "banana\n";


        memset(follow, 0, sizeof(follow));
        for(int i = 1; i <= n; i++) isfollow(i);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!follow[i] && lead[i] == i) ans++;
        }

        //for(int i = 1; i <= n; i++) cout << i << " " << group[i] << "\n";
        cout << "Case " << kase++ << ": " << ans << "\n";

    }
    return 0;
}
