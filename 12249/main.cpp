#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAXN = 15;
int t, n, kase=0;
string scenes[MAXN];
int used[MAXN];
int ans;

void dfs(string merge_scene, int count_recursive){
    if(count_recursive >= n){
        //cout << merge_scene << '\n';
        int len = merge_scene.length();
        ans = min(len, ans);
        return;
    }
    for(int i = 0; i < n; i++){
        if(used[i]) continue;

        int k = min(scenes[i].length(), merge_scene.length());
        while(k > 0){
            string substrA = merge_scene.substr(merge_scene.length()-k,k);
            string substrB = scenes[i].substr(0,k);
            if(substrA == substrB){
                //cout << substrA << ' ' << substrB << '\n';
                break;
            }
            k--;
        }
        used[i] = 1;
        string temp = merge_scene + scenes[i].substr(k, scenes[i].length()-k); //indice 0
        dfs(temp, count_recursive+1);
        used[i] = 0;
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> scenes[i];
            used[i] = 0;
        }
        ans = 0x3f3f3f;
        dfs("",0);
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
    return 0;
}
