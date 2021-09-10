#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1020
#define int long long
using namespace std;
string a, b;
map<string, int> name;
vector<int> edge[MAXN];
vector<int> rev_edge[MAXN];
vector<int> path;
int visit[MAXN];
int group[MAXN];
int t, p, cnt;

void dfs1(int root){
    if(visit[root]) return;
    visit[root] = 1;

    for(auto it: edge[root]){
        dfs1(it);
    }
    path.push_back(root);
}

void dfs2(int root, int ancestor){
    if(visit[root]) return ;

    visit[root] = 1;
    group[root] = ancestor;
    for(auto it: rev_edge[root]){
       dfs2(it, ancestor);
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> p >> t && (t+p)!=0){
        cin.ignore();
        name.clear();
        cnt = 1;
        for(int i = 0; i < p; i++){
            edge[cnt].clear();
            rev_edge[cnt].clear();

            getline(cin, a);
            name[a] = cnt++;
        }


        for(int i = 0; i < t; i++){
            getline(cin, a);
            getline(cin, b);
            edge[name[a]].push_back(name[b]);
            rev_edge[name[b]].push_back(name[a]);
        }

        memset(visit, 0, sizeof(visit));
        path.clear();

        for(int i = 1; i < cnt; i++){
            if(!visit[i]) dfs1(i);
        }

        int ans = 0;
        memset(visit, 0, sizeof(visit));
        memset(group, 0, sizeof(group));
        for(int i = path.size()-1; i >= 0; i--){
            if(!visit[path[i]]){
                dfs2(path[i], path[i]);
                ans++;
            }
        }

        //for(int i = 1; i < cnt; i++){
        //    cout << i << " " << group[i] << "\n";
        //}
        cout << ans << "\n";

    }
    return 0;
}
