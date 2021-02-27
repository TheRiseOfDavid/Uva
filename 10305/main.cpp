#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 120
using namespace std;
int n, m, a, b;
int cnt[MAXN];
vector<int> root[MAXN], ans;

void topo(){
    deque<int> q;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0) q.push_back(i);
    }

    int now;
    ans.clear();
    while(ans.size() != n){
        if(q.empty()) break;
        now = q.front(); q.pop_front();
        ans.push_back(now);
        for(auto it: root[now]){
            cnt[it]--;
            if(cnt[it] == 0) q.push_back(it);
        }
    }
    if(ans.size() == n){
        cout << ans[0];
        for(int i = 1; i < ans.size(); i++) cout << ' ' << ans[i];
        cout << '\n';
    }
}

int main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> n >> m && n + m != 0){
        for(int i = 1; i <= n; i++) root[i].clear();
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            root[a].push_back(b);
            cnt[b]++;
        }
        topo();
    }

}


