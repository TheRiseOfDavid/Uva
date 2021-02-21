#include <iostream>
#include <bits/stdc++.h>
#define MAXN 120
#define LOCAL
using namespace std;
int graph[MAXN][MAXN];
int cnt = 0, M, a, b, flag = 1;
string temp;

void dfs(int x, int y){
    if(x < 0 || y < 0 || x > 100 || y > 100) return;
    if(graph[x][y] == 0) return;
    graph[x][y] = 0;
    cnt++;
    //cout << "cnt x y " << cnt << ' ' << x << ' ' << y << '\n';
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}

void print(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++) cout << graph[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    cin >> M;
    while(M--){
        cin >> a >> b;
        cin.ignore();
        memset(graph, 0, sizeof(graph));
        int i = 0;
        while(getline(cin,temp) && temp != ""){
            //cout << temp << '\n';
            for(int j = 0; j < temp.length(); j++) graph[i][j] = (temp[j] - '0') ^ 1;
            //in my code 1 is water, 0 is land
            i++;
        }
        cnt = 0;
        //print();
        dfs(a-1, b-1);
        if(flag == 1 ){
            cout << cnt << '\n';
            flag = 0;
        }
        else cout << "\n" << cnt << '\n';

    }
    return 0;
}
