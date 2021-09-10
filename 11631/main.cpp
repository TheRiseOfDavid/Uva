#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 200020
#define int long long
using namespace std;
int n, m;
int a, b, c;
int p[MAXN];

struct edge{
    int u, v, c; //a = another node, cost
    edge(){
        u = 0, v = 0, c = 0;
    }
    edge(int _u, int _v, int _c){
        u = _u, v = _v, c = _c;
    }
    bool operator < (const edge& other) const{
        return c < other.c;
    }
};
vector<edge> node;
vector<edge> remain;

int find_root(int x){
    //cout << "find_root " << x << "\n";
    if(p[x] != x) return p[x] = find_root(p[x]);
    return x;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> n >> m && (n+m) != 0){
        node.clear();
        remain.clear();
        for(int i = 0; i < n; i++) p[i] = i;

        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            node.push_back({a,b,c});
        }
        sort(node.begin(), node.end());

        for(edge it: node){
            //cout << it.u << " " << it.v << " " << it.c << "\n";
            //cout << p[3] << " " << p[4] << "\n";
            int pu = find_root(it.u);
            int pv = find_root(it.v);
            if(pu != pv) p[pv] = pu;
            else remain.push_back(it);

        }

        int ans = 0;
        for(edge it: remain) ans += it.c;
        cout << ans << "\n";


    }
    return 0;
}
