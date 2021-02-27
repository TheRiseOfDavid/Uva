#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 220
using namespace std;
int cnt[MAXN];
vector<int> root[MAXN];
map<string, int> mp;
map<int, string> mp2;
int n, m, kase;

void topo(){
    deque<int> q;
    for(int i = 0; i < n; i++){
        if(cnt[i] == 0) q.push_back(i);
    }

    deque<int> ans;
    int now;
    while(ans.size() != n){
        if(q.empty()) break;
        sort(q.begin(), q.end());
        now = q.front(); q.pop_front();
        ans.push_back(now);
        for(auto it: root[now]){
            if(--cnt[it] == 0) q.push_back(it);
        }
    }

    if(n == ans.size()){
        cout << "Case #" << ++kase << ": Dilbert should drink beverages in this order:";
        for(auto it: ans) cout << ' ' << mp2[it];
        cout << ".\n\n";
    }

}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    string temp, temp2;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            root[i].clear();
            cnt[i] = 0;
            cin >> temp;
            mp[temp] = i;
            mp2[i] = temp;
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> temp >> temp2;
            root[mp[temp]].push_back(mp[temp2]);
            cnt[mp[temp2]]++;
        }
        topo();
    }

    return 0;
}
