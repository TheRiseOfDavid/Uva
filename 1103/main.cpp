#include <bits/stdc++.h>
#define LOCAL
#define boardY 52 * 4
using namespace std;
int W, H, kase=0, space;
int graph[202][boardY + 20];
string word = "WAKJSD", ans, temp;
map<char,int> mp;

void dfs_white(int h, int w){
    if(h > H + 2|| w > boardY || h < 0 || w < 0) return;
    if(graph[h][w] != 0) return;
    graph[h][w] = 2;
    dfs_white(h + 1, w);
    dfs_white(h - 1, w);
    dfs_white(h, w + 1);
    dfs_white(h, w - 1);
}

void dfs_black(int h, int w){
    if(h > H + 2 || w > boardY || h < 0 || w < 0) return;
    if(graph[h][w] == 1){
        graph[h][w] = 2;
        dfs_black(h + 1, w);
        dfs_black(h - 1, w);
        dfs_black(h, w + 1);
        dfs_black(h, w - 1);
    }
    else if(graph[h][w] == 0){
        space++;
        //cout << "space is " << space << '\n';
        dfs_white(h, w);
    }
    //cout << "dfs_black " << h << ' ' << w << '\n';
}

void debug(){
    for(int i = 1; i < H + 2; i++){
        for(int j = 5; j <= (W + 1) * 4; j++) cout << graph[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> H >> W && H && W){
        memset(graph, 0, sizeof(graph));
        for(int i = 1; i <= H; i++){
            cin >> temp;
            for(int j = 0; j < W; j++){
                if(isdigit(temp[j])) space = temp[j] - '0';
                else space = temp[j] - 'a' + 10;
                for(int k = 0; k < 4; k++) graph[i][(j + 1) * 4 + 4 - k] = (int) 1 & (space >> k);
            }
        }
        dfs_white(0, 0);
        //debug();
        ans = "";
        for(int i = 0; i < 202; i++){
            for(int j = 0; j < boardY; j++){
                if(graph[i][j] == 1){
                    space = 0;
                    dfs_black(i, j);
                    ans += word[space];
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case " << ++kase << ": ";
        cout << ans << '\n';
    }
    return 0;
}
