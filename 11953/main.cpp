#include <iostream>
#include <bits/stdc++.h>
#define MAXN 120
#define LOCAL
using namespace std;
int T, N, kase = 0;
char graph[MAXN][MAXN];
string s;

int dfs(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N) return 0;
    if(graph[x][y] == '.') return 0;
    int cnt = 0;
    if(graph[x][y] == 'x') cnt += 1;
    graph[x][y] = '.';
    cnt += dfs(x-1, y);
    cnt += dfs(x+1, y);
    cnt += dfs(x, y-1);
    cnt += dfs(x, y+1);
    return cnt;
}

void debug(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << graph[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> s;
            for(int j = 0; j < N; j++) graph[i][j] = s[j];
        }

        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(graph[i][j] != '.'){
                    if(dfs(i, j) != 0) ans++;
                }
            }
        }
        cout << "Case " << ++kase << ": ";
        cout << ans << '\n';
    }

    return 0;
}
