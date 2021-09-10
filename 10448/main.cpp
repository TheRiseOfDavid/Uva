#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
//#define int long long
#define MAXN 60
#define MAXN_cost 100020
#define INF 0x3f3f3f3f
using namespace std;
int t, n, m, q;
int id1, id2, cost;
int from, to, require_cost;
int visit[MAXN];
int dp[MAXN][MAXN_cost];
struct edge{
    int node, cost;
};
vector<edge> road[MAXN]; //first = node, second = cost
vector<int> travel_cost;


int dfs(int root){
    //cout << "root to " << root << ' ' << to << '\n';
    if(root == to) return 1;
    if(visit[root]) return 0;

    visit[root] = 1;
    for(int i = 0; i < road[root].size(); i++){
        if(dfs(road[root][i].node)){
            require_cost -= road[root][i].cost;
            travel_cost.push_back(road[root][i].cost);
            return 1;
        }
    }
    return 0;
}

int coin_change(){
    //if(from == to) return -1;
    //cout << "fron to require_cost " << from << ' ' << to << ' ' << require_cost << "\n";
    int connected = dfs(from);
    //cout << "connected status " << connected << "\n";
    //cout << "required cost " << require_cost << "\n";
    //if(connected == 0) return -1;
    if(require_cost == 0) return travel_cost.size();
    if(require_cost < 0 || require_cost % 2 == 1) return -1;
    travel_cost.erase(travel_cost.begin());
    if(travel_cost.size() == 0) return -1;

    //cout << "start dp " << '\n';
    //for(int i = 0; i < travel_cost.size(); i++) cout << travel_cost[i] << ' ';
    //cout << '\n';
    require_cost /= 2;
    dp[0][0] = 0;
    for(int i = 0; i < travel_cost.size(); i++){
        for(int j = 0; j <= require_cost; j++){
            if(j - travel_cost[i] >= 0) dp[i][j] = min(dp[i][j], dp[i][j - travel_cost[i]]+1);
            //if(j - travel_cost[i] >= 0) cout << j << " " << dp[i][j] << '\n';
            if(i > 0) dp[i][j] = min(dp[i-1][j], dp[i][j]);
        }
    }

    //cout << "travel_cost.size()-1 " << travel_cost.size()-1 << '\n';
    //cout << dp[travel_cost.size()-1][require_cost] << ' ' << INF << '\n';
    if(dp[travel_cost.size()-1][require_cost] == INF) return -1;
    return travel_cost.size() + dp[travel_cost.size()-1][require_cost] * 2 + 1;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i <= n; i++) road[i].clear();
        for(int i = 0; i < m; i++){
            cin >> id1 >> id2 >> cost;
            road[id1].push_back({id2, cost});
            road[id2].push_back({id1, cost});
        }

        cin >> q;
        for(int i = 0; i < q; i++){
            travel_cost.clear();
            memset(visit, 0, sizeof(visit));
            memset(dp, INF, sizeof(dp));

            cin >> from >> to >> require_cost;
            int ans = coin_change();
            if(ans == -1) cout << "No" << "\n";
            else cout << "Yes " << ans << "\n";
        }

        if(t != 0) cout << "\n";
    }

    return 0;
}
