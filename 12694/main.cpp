#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int n, s, f;
vector<pair<int,int>> meet;

int compare(pair<int,int> x, pair<int,int> y){
    return x.second < y.second;
}

int solve(){
    int end = 0, ans = 0;
    for(auto it: meet){
        if(end <= it.first){
            //cout << it.first << ' ' << it.second << '\n';
            end = it.second;
            ans++;
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    while(n--){
        meet.clear();
        while(cin >> s >> f && (s+f!=0)) meet.push_back({s,f});
        sort(meet.begin(), meet.end(), compare);
        cout << solve() << '\n';
    }

    return 0;
}
