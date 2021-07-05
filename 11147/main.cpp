#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 2000
using namespace std;
int sum[MAXN], num[MAXN];
int t, n, kase=0;

void dfs(int L, int R){
    if(L > R) return;

    int root = L, min_diff = INT32_MAX, max_left = INT32_MIN;
    for(int i = L; i <= R; i++){
        if(i != R && num[i] == num[i+1]) continue;
        int left_tree = (i == 0 ? 0 : sum[i-1]) - (L == 0 ? 0 : sum[L-1]);
        int right_tree = sum[R] - sum[i];

        int diff = abs(right_tree - left_tree);
        int left = left_tree;
        if(diff < min_diff){
            root = i;
            min_diff = diff;
            max_left = left;
        }
        if(diff == min_diff && left > max_left){
            root = i;
            min_diff = diff;
            max_left = left;
        }
    }

    cout << num[root];
    if(L != R ){
        cout << "(";
        dfs(L, root-1);
        if(root != L && root != R) cout << ",";
        dfs(root+1, R);
        cout << ")";
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> num[i];
        sort(num, num+n);

        cout << "Case #" << ++kase << ": ";
        sum[0] = num[0];
        for(int i = 0; i < n; i++) sum[i] = sum[i-1] + num[i];
        dfs(0, n-1);
        cout << '\n';
    }
    return 0;
}
