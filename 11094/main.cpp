#include <iostream>
#include <bits/stdc++.h>
#define MAXN 25
#define BX 20
#define BY 20
#define LOCAL
using namespace std;
int N, M, X, Y;
char graph[MAXN][MAXN];
char land, water;
string s;

int dfs(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M) return 0;
    if(graph[x][y] != land) return 0;
    graph[x][y] = '`';
    int cnt = 1;
    cnt += dfs(x-1, y);
    cnt += dfs(x+1, y);

    if(y == M-1) cnt += dfs(x, 0);
    else cnt += dfs(x, y+1);

    if(y == 0) cnt += dfs(x,M-1);
    else cnt += dfs(x, y-1);
    return cnt;
}

void debug(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> N >> M){
        for(int i = 0; i < N; i++){
            cin >> s;
            for(int j = 0; j < M; j++) graph[i][j] = s[j];
        }

        int ans = 0;
        cin >> X >> Y;
        land = graph[X][Y];
        dfs(X, Y);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(graph[i][j] == land) ans = max(ans, dfs(i, j));
            }
        }
        //debug();
        cout << ans << '\n';
    }
    return 0;
}
