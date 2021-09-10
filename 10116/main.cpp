#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN
using namespace std;
string maze[20];
int visit[20][20];
int r, c, go;

int dfs(int x, int y, int step){
    //cout << x << " " << y << "\n";
    if(x < 0 || x >= r || y < 0 || y >= c){
        cout << step << " step(s) to exit\n";
        return 0;
    }
    if(visit[x][y] != -1){
        cout << visit[x][y] << " step(s) before a loop of " << step - visit[x][y] << " step(s)\n";
        return 0;
    }


    visit[x][y] = step;

    if(maze[x][y] == 'N') dfs(x-1, y, step+1);
    else if(maze[x][y] == 'S') dfs(x+1, y, step+1);
    else if(maze[x][y] == 'W') dfs(x, y-1, step+1);
    else if(maze[x][y] == 'E') dfs(x, y+1, step+1);
    return 0;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> r >> c >> go && (r + c + go) != 0){
        for(int i = 0; i < r; i++) cin >> maze[i];
        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= c; j++) visit[i][j] = -1;
        }
        dfs(0,go-1,0);
    }
    return 0;
}
