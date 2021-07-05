#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAXN = 120;
int t, q, n, m;
int direct[4][2] = {{0,1},{+1,0},{0,-1},{-1,0}};
string graph[MAXN];

int isValid(int x, int y){
    if(x >= 0 && x < m && y >= 0 && y < n) return 1;
    return 0;
}

int find_square(int x, int y){//position distance
    int d = 1;
    int root_char = graph[x][y];
    int flag = 1;

    while(flag){
        d += 2;
        int nowX = x-(d/2), nowY = y-(d/2);

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < d-1; j++){
                nowX += direct[i][0];
                nowY += direct[i][1];
                //cout << "nowX nowY " << nowX << ' ' << nowY << ' ' << isValid(nowX,nowY) << '\n';

                if(!isValid(nowX,nowY) || graph[nowX][nowY] != root_char){
                    flag = 0;
                    break;
                }
                //cout << "graph char " << graph[nowX][nowY] << '\n';

            }
            if(flag == 0) break;
        }
    }
    return d-2;

}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> m >> n >> q;
        for(int i = 0; i < m; i++) cin >> graph[i];

        cout << m << ' ' << n << ' ' << q << '\n';
        int x, y;
        while(q--){
            cin >> x >> y;
            cout << find_square(x, y) << '\n';
        }
    }
    return 0;
}
