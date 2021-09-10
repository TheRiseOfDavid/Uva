#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
//#define DEBUG
#define MAXN 1200
#define int long long
using namespace std;
vector<int> edge[MAXN];
vector<pair<int,int> > bridge;
int visit[MAXN], depth[MAXN], low[MAXN];
int n, m, a, b;

void find_bridge(int root, int past, int cnt){
    visit[root] = 1; //��ܨ��X�L
    depth[root] = low[root] = cnt; //�޿��ҩ� 2.1

    for(int node: edge[root]){ //���_�M�a
        //�]���O�L�V��A�]�����V�P�� edge ���O bridge
        if(node == past) continue;
        if(visit[node]) low[root] = min(low[root], depth[node]); //�޿��ҩ� 2.2
        else{
            //���i�� DFS�A���U���L�� node ���S����k�^�촿�g����L���`�I
            find_bridge(node, root, cnt+1);

            low[root] = min(low[root], low[node]); //�޿��ҩ� 2.3

            if(low[node] > depth[root]){  //�޿��ҩ� 2.4
                //if(node < root) swap(node, root); //error
                bridge.push_back({min(node, root), max(node, root)});
            }
        }
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> n >> m && (n+m) != 0){
        bridge.clear();
        memset(visit, 0, sizeof(visit));
        memset(depth, 0, sizeof(depth));
        memset(low, 0, sizeof(low));
        for(int i = 0; i < n; i++) edge[i].clear();

        for(int i = 0; i < m; i++){
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(int i = 0; i < n; i++){
            if(!visit[i]) find_bridge(i,-1, 0);
        }

        sort(bridge.begin(), bridge.end());
        cout << bridge.size();
        for(auto b: bridge){
            cout << " " << b.first << " " << b.second;
        }
        cout << "\n";

#ifdef DEBUG
        for(int i = 0; i < n; i++){
            cout << "i depth low " << i << " " << depth[i] << " " << low[i] << "\n";
        }
        for(int n: edge[8]) cout << n << " ";
        cout << "\n";
#endif
    }
    return 0;
}
