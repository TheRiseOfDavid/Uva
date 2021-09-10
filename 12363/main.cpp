#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
//#define DEBUG
#define int long long
#define MAXN 100020
using namespace std;
vector<int> edge[MAXN];
int visit[MAXN], ancestor[MAXN];
int depth[MAXN], low[MAXN];
int r, c, q, cnt;
int a, b;

int find_root(int x){
    if(ancestor[x] != x) return ancestor[x] = find_root(ancestor[x]);
    return ancestor[x];
}

void find_bridge(int root, int past){
    visit[root] = 1;
    depth[root] = low[root] = cnt++;
    for(int node: edge[root]){
        if(node == past) continue;
        if(visit[node]) low[root] = min(low[root], depth[node]);
        else{
            find_bridge(node, root);
            low[root] = min(low[root], low[node]);
            if(low[node] > depth[root]){
                int fa_node = find_root(node);
                int fa_root = find_root(root);
                //cout << "fa " << fa_node << " " << fa_root << "\n";
                ancestor[fa_node] = fa_root;
            }
        }
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    while(cin >> r >> c >> q && (r+c+q) != 0){
        for(int i = 1; i <= r; i++){
            edge[i].clear();
            ancestor[i] = i;
        }
        memset(visit, 0, sizeof(visit));
        memset(depth, 0, sizeof(depth));

        for(int i = 0; i < c; i++){
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);

        }

        cnt = 1;
        for(int i = 1; i <= r; i++){
            if(!visit[i]) find_bridge(i, -1);
        }

#ifdef DEBUG
        for(int i = 1; i <= r; i++){
            cout << "ancestor " << i << " " << ancestor[i] << "\n";
        }
        for(int i = 1; i <= r; i++){
            cout << "low " << i << " " << low[i] << "\n";
        }
#endif

        while(q--){
            cin >> a >> b;
            int fa_a = find_root(a);
            int fa_b = find_root(b);
            if(fa_a == fa_b) cout << "Y\n";
            else cout << "N\n";
        }
        cout << "-\n";
    }
    return 0;
}
