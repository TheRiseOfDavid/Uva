#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 15
using namespace std;
int graph[MAXN][MAXN] ;
int record[MAXN][MAXN] ;
int direct[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int south_wall[MAXN] ;
int sx , sy , N , M , ex , ey ;
int a , kase = 0 , flag = 0 ;

int isboard(int x , int y , int i ){

    if(x + direct[i][0] > N || x + direct[i][0] < 1 )
        return 0 ;
    if(y + direct[i][1] > M || y + direct[i][1] < 1 )
        return 0 ;
    //cout << x + direct[i][0] << ' ' << y + direct[i][1] << ' ' << N << ' ' << M  << '\n' ;
    return 1 ;
}

void dfs(int x , int y ){
    int ox , oy   ;
    ox = x ;
    oy = y ;
    if (x == ex && y == ey) {
        flag = 1 ;
        return ;
    }
    if(isboard(x,y,0) ){ //west
        x = ox + direct[0][0] ;
        y = oy + direct[0][1] ;
        if(record[x][y] == 0 && (graph[x][y] == 2 || graph[x][y] == 0)){
            record[x][y] = record[ox][oy] + 1 ;
            //cout << x << ' ' << y << " west" << '\n' ;
            dfs(x,y);
            if(flag) return ;
            record[x][y] = -1 ;
        }
    }
    if(isboard(x,y,1)){ //north
        x = ox + direct[1][0] ;
        y = oy + direct[1][1] ;
        if(record[x][y] == 0 && (graph[x][y] == 1 || graph[x][y] == 0)){
            record[x][y] = record[ox][oy] + 1 ;
            //cout << x << ' ' << y << " north" << '\n' ;
            dfs(x,y);
            if(flag) return ;
            record[x][y] = -1 ;
        }
    }
    if(isboard(ox,oy,2) ){//east
        x = ox + direct[2][0] ;
        y = oy + direct[2][1] ;
        if(record[x][y] == 0 && (graph[ox][oy] == 2 || graph[ox][oy] == 0)){
            record[x][y] = record[ox][oy] + 1 ;
            //cout << x << ' ' << y << " east" << '\n' ;
            dfs(x,y);
            if(flag) return ;
            record[x][y] = -1 ;
        }
    }
    if(isboard(ox,oy,3)){//south
        x = ox + direct[3][0] ;
        y = oy + direct[3][1] ;
        if(record[x][y] == 0 && (graph[ox][oy] == 1 || graph[ox][oy] == 0 )){
            record[x][y] = record[ox][oy] + 1 ;
            //cout << x << ' ' << y << " south" << '\n' ;
            dfs(x,y);
            if(flag) return ;
            record[x][y] = -1 ;
        }
    }
}

void row_wall( ){
    for(int i = 1 ; i <= M ; i++){
        cout << "+" ;
        if(south_wall[i]){
            cout << "---" ;
            south_wall[i] = 0 ;
        }
        else cout << "   " ;
    }
    cout << "+\n" ;
}


void output(){
    cout << "Maze " << ++kase << "\n\n" ;
    //cout << flag << '\n' ;
    for(int i = 0 ; i <= M ; i++) south_wall[i] = 1 ;

    if(flag == 0 ) record[sx][sy] = -1 ;
    for(int i = 1 ; i <= N ; i++){
        row_wall();
        cout << '|' ;
        //cout << M << '\n' ;
        for(int j = 1 ; j <= M ; j++){
            if(record[i][j] == -1)
                cout << "???" ;
            else if(record[i][j] > 0)
                cout << setw(3) << right << record[i][j] ;
            else cout << "   " ;

            if(j == M || graph[i][j] == 1 || graph[i][j] == 3)
                cout << "|" ;
            else cout << ' ' ;
            if(graph[i][j] == 2 || graph[i][j] == 3)
                south_wall[j] = 1 ;
        }
        cout << '\n' ;
    }
    for(int i = 0 ; i <= M ; i++) south_wall[i] = 1 ;
    row_wall();
    cout << "\n\n" ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    while(cin >> N >> M >> sx >> sy >> ex >> ey && N){
        //cout << N << ' ' << M << ' ' << sx << ' ' << sy << '\n' ;
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                cin >> a ;
                graph[i][j] = a ;
                record[i][j] = 0 ;
            }
        }
        flag = 0 ;
        record[sx][sy] = 1 ;
        dfs(sx,sy);
        output();
    }
    return 0;
}
