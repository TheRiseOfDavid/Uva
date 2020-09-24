#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define INF 99999999
using namespace std;
int intMap[1010][1010] = {} , intValue[1010][1010] = {};
int m , n ;


struct Node{
    int x , y , v ;
    void read( int _x , int _y , int _v){
        x = _x ; y = _y ; v = _v ;
    }
    bool operator < (const Node &a) const{
        return v > a.v ;
    }
}nodNode;


void print_map(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(intValue[i][j] == 99999999)
                cout << 'r' << ' ' ;
            else
                cout << intValue[i][j] << ' ' ;
        }
        cout << '\n' ;
    }
    cout << '\n' ;
}


void bfs(){
    int x , y , intDirection[4][2] = {-1,0 ,0,1 ,1,0 ,0,-1};
    int intDx , intDy ;
    Node nodTemp ;
    priority_queue<Node> deqNode ;
    nodTemp.read(1,1,0);
    deqNode.push(nodTemp);
    while(deqNode.size()){
        x = deqNode.top().x ;
        y = deqNode.top().y ;
        deqNode.pop() ;

        for(int i = 0 ; i < 4 ; i++){
            intDx = intDirection[i][0] + x ;
            intDy = intDirection[i][1] + y ;

            //debug
            //cout << intDx << ' ' << intDy << ' ' << intValue[x][y] + intMap[intDx][intDy] << ' ' << i <<  '\n' ;

            if(intValue[x][y] + intMap[intDx][intDy] < intValue[intDx][intDy]  ){
                intValue[intDx][intDy] = intValue[x][y] + intMap[intDx][intDy] ;
                nodTemp.read(intDx , intDy , intValue[intDx][intDy]);
                deqNode.push(nodTemp) ;
            }
        }
        //print_map() ;
    }
}


int main() {
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout) ;
#endif
ios::sync_with_stdio(false);
    int intCase ;
    cin >> intCase ;
    while(intCase --){
        cin >> n >> m ;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                 cin >> intMap[i][j] ;
                intValue[i][j] = INF ;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            intValue[i][0] = 0 ;
            intValue[i][m+1] = 0 ;
            intMap[i][0] = INF +1 ;
            intMap[i][m+1] = INF +1 ;
        }
        for(int i = 1 ; i <= m ; i++){
            intValue[0][i] = 0 ;
            intValue[n+1][i] = 0 ;
            intMap[0][i] = INF +1 ;
            intMap[n+1][i] = INF +1 ;
        }
        intValue[1][1] = intMap[1][1] ;

        //debug
        //cout << intValue[1][1] << '\n' ;

        bfs();
        cout << intValue[n][m] << '\n' ;
    }
	return 0;

}
