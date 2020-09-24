#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int c[100], n;
bool G[30][30];
bool dfs(int v) {
    for (int u = 0; u < v; ++u)
        if (G[u][v] && c[u] == c[v])
            return false;
    if (v == n - 1) return true;
    for (int i = 0; i < 3; ++i) {
        c[v + 1] = i;
        if (dfs(v + 1)) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int T, a, b, m, i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(G, 0, sizeof G);
        for (i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            G[a][b] = G[b][a] = true;
        }

        if (dfs(0)) puts("Y");
        else puts("N");
    }
    return 0;
}
