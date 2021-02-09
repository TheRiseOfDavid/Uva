#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
using namespace std;
int t, f, hs;
int num[MAXN], cnt[MAXN];
string n1, n2;
unordered_map<string, int> record;

int find_root(int i){
    if(num[i] != i) return num[i] = find_root(num[i]);
    return num[i];
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    for(int i = 0; i < MAXN; i++){
        num[i] = i;
        cnt[i] = 1;
    }
    while(t--){
        cin >> f;
        hs = 0; record.clear();
        for(int i = 0; i < f; i++){
            num[i] = i;
            cnt[i] = 1;
        }
        for(int i = 0; i < f; i++){
            cin >> n1 >> n2;
            if(!record.count(n1)) record[n1] = hs++;
            if(!record.count(n2)) record[n2] = hs++;
            int rx, ry;
            rx = find_root(num[record[n1]]);
            ry = find_root(num[record[n2]]);
            if(rx != ry){
                num[ry] = num[rx];
                cnt[rx] += cnt[ry];
                cnt[ry] = 0;
            }
            cout << cnt[rx] << '\n';
        }
    }
    return 0;
}
