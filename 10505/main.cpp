#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 300
using namespace std;
vector<int> edge[MAXN];
int visit[MAXN];
int t, n, cnt, enemy;
int color[2], flag;

void dfs(int root, int status){
    //cout << "root " << root << "\n";
    if(visit[root] == -1) visit[root] = status;
    else{
        flag &= (visit[root] == status);
        return;
    }

    //cout << "root status " << root << " " << visit[root] << "\n";
    color[status]++;
    for(int i = 0; i < edge[root].size(); i++){
        dfs(edge[root][i], 1-status);
    }
    return;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            visit[i] = -1;
            edge[i].clear();
        }

        for(int i = 1; i <= n; i++){
            cin >> cnt;
            for(int j = 0; j < cnt; j++){
                cin >> enemy;
                if(enemy > n) continue;
                edge[i].push_back(enemy);
                edge[enemy].push_back(i);
                //cout << "i enemy " << i << " " << enemy << "\n";
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            memset(color, 0, sizeof(color));
            if(visit[i] == -1){
                flag = 1;
                dfs(i, 0);
                if(flag == 1) ans += max(color[0], color[1]);
            }

            //cout << "max " << max(color[0], color[1]) << "\n";
        }
        cout << ans << "\n";
    }

    return 0;
}
