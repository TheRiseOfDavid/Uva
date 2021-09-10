#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 120
using namespace std;
int n, m, s;
int x, y, ans;
int visit[MAXN][MAXN];
string graph[MAXN];
string line, direct, pillars;
map<string, string> L;
map<string, string> R;

void walk(char cmd){
    int flag = 0;
    if(cmd == 'F'){
        if(direct == "N" && graph[x-1][y] != '#') x = x-1;
        if(direct == "S" && graph[x+1][y] != '#') x = x+1;
        if(direct == "O" && graph[x][y-1] != '#') y = y-1;
        if(direct == "L" && graph[x][y+1] != '#') y = y+1;
        if(!visit[x][y] && graph[x][y] == '*') ans++;
        visit[x][y] = 1;
    }
    else if(cmd == 'D') direct = R[direct];
    else if(cmd == 'E') direct = L[direct];
    //cout << "cmd x y graph " << cmd << " " << x << " " << y << " " << direct << "\n";
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    L["N"] = "O"; L["O"] = "S"; L["S"] = "L", L["L"] = "N";
    R["N"] = "L"; R["L"] = "S"; R["S"] = "O", R["O"] = "N";

    while(cin >> n >> m >> s && (n+m+s) != 0){
        memset(visit, 0, sizeof(visit));
        pillars = "";
        for(int i = 0; i <= m+1; i++) pillars += "#";

        graph[0] = pillars;
        for(int i = 1; i <= n; i++){
            cin >> line;
            graph[i] = "#" + line + "#";
            for(int j = 1; j <= m; j++){
                if(graph[i][j] == 'N' || graph[i][j] == 'S' || graph[i][j] == 'L' || graph[i][j] == 'O'){
                    x = i;
                    y = j;
                    direct = graph[i][j];
                }
            }
        }
        graph[n+1] = pillars;

        ans = 0;
        cin >> line;
        for(int i = 0; i < line.length(); i++){
            walk(line[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
