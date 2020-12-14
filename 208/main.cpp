#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 22
using namespace std;
int n , kase , cnt , vis[MAXN] , road[MAXN][MAXN] , join[MAXN];
vector<int> res ;

void reverse_dfs(int u ){
    join[u] = 1 ;
    for(int i = 1 ; i < MAXN ; i++)
        if( !join[i] && road[u][i] ) reverse_dfs(i);
}

void dfs(int u ){
    if(u == n ){
        for(int i = 0 ; i < res.size()-1 ; i++) cout << res[i] << ' ' ;
        cout << res[res.size()-1] ;
        cout << '\n' ;
        cnt++ ;
        return ;
    }
    for(int i = 1 ; i < MAXN ; i++){
        if(!vis[i] && road[u][i] && join[i] ){
            vis[i] = 1 ;
            res.push_back(i);
            dfs(i);
            res.pop_back();
            vis[i] = 0 ;
        }
    }
}

void init(){
    memset(road,0,sizeof(road));
    memset(vis,0,sizeof(vis));
    memset(join,0,sizeof(join));
    cnt = 0 ;
    res.clear();
    vis[1] = 1 ;
    res.push_back(1) ;
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout) ;
#endif // LOCAL
    int a,b ;
    while(cin >> n){
        init();
        while(cin >> a >> b && a && b ){
            road[a][b] = 1 ; road[b][a] = 1 ;
        }
        reverse_dfs(n);
        cout << "CASE " << ++kase << ":\n" ;
        dfs(1);
        cout << "There are " << cnt << " routes from the firestation to streetcorner " << n << ".\n";
    }

    return 0;
}
