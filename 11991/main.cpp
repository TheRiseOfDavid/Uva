#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
using namespace std;
int n, m, k, v, temp, cnt;
vector<int> num[MAXN];
std::unordered_map<int,int> record;

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> n >> m){
        for(int i = 0; i < MAXN; i++) num[i].clear();
        cnt = 0; record.clear();
        for(int i = 1; i <= n; i++){
            cin >> temp;
            if(!record.count(temp)) record[temp] = cnt++;
            num[record[temp]].push_back(i);
        }
        for(int i = 0; i < m; i++){
            cin >> k >> v;
            if(num[record[v]].size() < k) cout << "0\n";
            else cout << num[record[v]][k-1] << '\n';
        }
    }
    return 0;
}
