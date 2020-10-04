#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100
using namespace std;
string strA , strB ;
int dis[MAXN][MAXN] , back_table[MAXN][MAXN] ;
int cnt , m , n  ;

void backtracking(int i , int j ){
    if(i==0 || j==0){
        while( i > 0 ){
            cout << cnt++ << " Delete " << i << '\n' ;
            i--;
        }
        while( j > 0){
            cout << cnt++ << " Insert " << i+1 << "," << strB[j-1] << '\n' ;
            j-- ;
        }
        return ;
    }

    if(strA[i-1] == strB[j-1])
        backtracking(i-1,j-1);
    else{
        if(dis[i][j] == dis[i-1][j-1]+1){
            cout << cnt++ << " Replace " << i << "," << strB[j-1] << '\n' ;
            backtracking(i-1,j-1);
        }
        else if(dis[i][j] == dis[i-1][j]+1){
            cout << cnt++ << " Delete " << i << '\n' ;
            backtracking(i-1,j) ;
        }
        else if(dis[i][j] == dis[i][j-1]+1){
            cout << cnt++ << " Insert " << i+1 << "," << strB[j-1] <<'\n'  ;
            backtracking(i,j-1);
        }

    }

}

void med(){ //Minimum Edit Distance
    for(int i = 0 ; i <= n ; i++) dis[i][0] = i ;
    for(int j = 0 ; j <= m ; j++) dis[0][j] = j ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(strA[i-1] == strB[j-1]) dis[i][j] = dis[i-1][j-1] ;
            else dis[i][j] = min(dis[i-1][j-1], min(dis[i-1][j] , dis[i][j-1]))+1;
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int flag = 0 ;
    while(getline(cin ,strA) && getline(cin , strB)){
        n=strA.length() ;
        m=strB.length() ;
        cnt = 1 ;
        med();
        if(flag) cout << '\n' ;
        flag = 1 ;
        cout << dis[n][m] << '\n' ;
        backtracking(n,m);
    }
    return 0;
}
