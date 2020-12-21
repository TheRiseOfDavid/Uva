#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 200
using namespace std;
int visit[MAXN] , graph[MAXN][MAXN] ;
int n , len , sz , temp_n , temp_i ;
vector<int> record ;

void dfs(int x ){
    for(int i = 1 ; i <= n ; i++ ){
        //cout << x << ' ' << i << ' ' << graph[x][i] << '\n' ;
        if(graph[x][i] && !visit[i]){
            visit[i] = 1 ;
            dfs(i );
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL

    while(cin >> n && n ){
        memset(graph,0,sizeof(graph));
        while(cin >> temp_i && temp_i )
            while(cin >> temp_n && temp_n) graph[temp_i][temp_n] = 1 ;

        cin >> len ;
        for(int i = 0 ; i < len ; i++){
            cin >> temp_n ;
            sz = 0 ;
            record.clear();
            memset(visit,0,sizeof(visit));
            dfs(temp_n);
            for(int j = 1 ; j <= n ; j++){
                if(!visit[j])
                    record.push_back(j);
            }
            cout << record.size() ;
            for(auto it : record )
                cout << ' ' << it ;
            cout << '\n' ;
        }
    }

}

