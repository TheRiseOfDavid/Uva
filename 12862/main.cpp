#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 100020
using namespace std;
int f, n;
vector<pair<int, int> > nodes[MAXN]; //first 2nd node, second weights
int pal[MAXN];
int a, b, c, l;
int max_weights, ans;

int dfs(int root, int weights){
    int visited_friend = 0;
    if(pal[root] == 1){
        max_weights = max(weights, max_weights);
        visited_friend++;
    }

    for(int i = 0; i < nodes[root].size(); i++){
        int node = nodes[root][i].first, weight = nodes[root][i].second;
        int visit_friend = dfs(node, weights+weight);
        visited_friend += visit_friend;
        if(visit_friend) ans += weight;
    }

    //cout << "root visit_friend " << root << " " << visited_friend << "\n";
    return visited_friend;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    while(cin >> f >> n){
        for(int i = 0; i <= f; i++) nodes[i].clear();
        for(int i = 0; i < f-1; i++){
            cin >> a >> b >> c;
            nodes[a].push_back(make_pair(b, c));
        }

        memset(pal, 0, sizeof(pal));
        for(int i = 0; i < n; i++){
            cin >> l;
            //cout << "l " << l << "\n";
            pal[l] = 1;

        }
        max_weights = 0, ans = 0;
        dfs(1,0);
        //cout << "ans " << ans << "\n";
        cout << ans - max_weights << "\n";

    }
    return 0;
}
