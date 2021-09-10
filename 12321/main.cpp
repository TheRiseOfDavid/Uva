#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 100020
using namespace std;
int G, L, x, r;
vector<pair<int,int> > gas;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> L >> G, L > 0 && G > 0){
        gas.clear();
        for(int i = 0; i < G; i++){
            cin >> x >> r;
            gas.push_back({x-r, x+r});
        }
        sort(gas.begin(), gas.end());

        int coverage = 0, temp_coverage = 0, eliminated = G, i = 0;
        while(L > coverage){
            temp_coverage = coverage;
            for(; i < G && gas[i].first <= coverage; i++){
                if(gas[i].second > temp_coverage) temp_coverage = gas[i].second;
            }
            if(coverage == temp_coverage) break;
            coverage = temp_coverage;
            eliminated--;
        }

        if(coverage < L) cout << "-1\n";
        else cout << eliminated << "\n";

    }

    return 0;
}
