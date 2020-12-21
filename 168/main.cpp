#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 300
#define MAXN_Alpha 27
using namespace std;
string strQ  ;
char strM , strT ;
int M , T , K , ans , cnt ; //cnt is all of use letter
int graph[MAXN][MAXN] , flag , nx , ny; //nx nodex ny nodey
int visit[MAXN];
vector<int> record ;
vector<int> path[MAXN_Alpha] ;
int dfs(int m , int t , int k ){
    int flag = 1 ;
    while(1){
        flag = 1 ;
        if(k == 0 ){
            visit[t] = 1 ;
            record.push_back(t) ;
            //cout << "candle is " << (char)(t+'A') << '\n' ;
            k = K ;
        }
        //cout << "m is " << (char)(m+'A') << '\n' ;
        for(auto it : path[m]){
            if((visit[it] == 0 && it != t) ){
                //cout << i << '\n' ;
                flag = 0 ;
                t = m ;
                m = it ;
                k-- ;
                break ;
            }
        }
        if(flag) break;
    }
    return m;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    while(cin >> strQ && strQ != "#"){
        cin >> strM >> strT >> K ;
        T = strT - 'A' ;
        M = strM - 'A' ;
        //cout << T << ' ' << M << ' ' << K << '\n' ;
        flag = 0;
        cnt = 0 ;
        memset(visit,0,sizeof(visit));
        record.clear();
        for(int i = 0 ; i < MAXN_Alpha ; i++)
            path[i].clear();
        for(int i = 0 ; i < strQ.length() ; i++){
            if(flag == 0 && strQ[i] == ':'){
                cnt ++;
                nx = strQ[i-1] - 'A' ;
                flag = 1 ;
            }
            else if(strQ[i] == '.' || strQ[i] == ';'){
                flag = 0 ;
            }
            else if(flag == 1 ){
                ny = strQ[i] - 'A' ;
                path[nx].push_back(ny);
                //cout << "edge is " << nx << ' ' << ny << '\n' ;
            }
        }
        //K %= cnt ;
        //if(K == 0 ) K = cnt ;
        ans = dfs(M,T,K);
        for(auto it : record )
            cout << (char)( 'A' + it) << ' ' ;
        cout << '/' << (char)( 'A' + ans) << '\n'  ;
    }


    return 0;
}
