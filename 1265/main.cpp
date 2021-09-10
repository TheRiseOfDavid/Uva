#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 5020
#define INF 0x3f3f3f
#define int long long
using namespace std;
int t, n, m;
int a, b, c;
int p[MAXN], length[MAXN];
vector<pair<int,int> > edges[MAXN];

struct edge{
    int u, v, c; //u,v 分別為邊的節點， c 是成本
    edge(): u(0), v(0), c(0) {}
    edge(int u, int v, int c): u(u), v(v), c(c) {}

    bool operator < (const edge& other) const{
        return c > other.c;
    }
};
vector<edge> node;

int find_root(int x){
    //cout << "find_root " << x << "\n";
    if(p[x] != x) return p[x] = find_root(p[x]);
    return x;
}

int check(int x){
    int inedge = INF, outedge = 0; //inedge = inside edge, outedge = outside edge
    for(int i = 1; i <= n; i++){
        if(x != find_root(i)) continue;

        for(auto it: edges[i]){
            if(find_root(it.first) == x) inedge = min(inedge, it.second);
            else outedge = max(outedge, it.second);
        }
    }

    //cout << "x inedge outedge " << x << " " << inedge << " " << outedge << "\n";
    return inedge > outedge;
}

int32_t main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n >> m;
        node.clear();
        for(int i = 1; i <= n; i++){
            p[i] = i; //init disjoint set
            edges[i].clear();
            length[i] = 1;
        }

        for(int i = 0; i < m; i++){
            cin >> a >> b >> c; //輸入邊、成本
            node.push_back({a,b,c});
            edges[a].push_back({b,c});
            edges[b].push_back({a,c});
        }
        sort(node.begin(), node.end()); //排序，這邊排序方式為遞增

        int ans = 0;
        for(edge it: node){
            //cout << it.u << " " << it.v << " " << it.c << "\n";
            int pu = find_root(it.u); //判斷邊的節點們是否都在同個 set
            int pv = find_root(it.v);
            if(find_root(pu) != find_root(pv)){
                p[pv] = pu;
                length[pu] += length[pv];

                //cout << "len pu " << length[pu] << "\n";
                if(check(pu)) ans += length[pu];
            }

        }

        cout << ans << "\n";
    }
}

