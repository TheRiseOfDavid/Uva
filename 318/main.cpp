#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 520
#define oo 1e20
using namespace std;
int kase=0 , N , M ;
int a , b , v , x , st , ed , flag , now   ;
double graph[MAXN][MAXN] ;
int used[MAXN] ;
double max_path , speed[MAXN] ;

void dijkstra(){
    speed[1] = 0 ;
    used[1] = 1;
    now = 1 ;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(graph[now][j] && speed[j] > graph[now][j] + speed[now] ){
                speed[j] = graph[now][j] + speed[now];
                //cout << speed[j] << '\n' ;
            }
        }
        max_path = oo ;
        for(int j = 1 ; j <= N ; j++){
            if( !used[j] && max_path > speed[j]){
                max_path = speed[j] ;
                now = j;
            }
        }
        //cout << "i is " << i << ' ' << now << ' ' << max_path << '\n' ;
        used[now] = 1 ;
    }

}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    while(cin >> N >> M && N ){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++) graph[i][j] = 0 ;
            speed[i] = oo ;
            used[i] = 0 ;
        }

        for(int i = 1 ; i <= M ; i++){
            cin >> a >> b >> v ;
            graph[a][b] = v ;
            graph[b][a] = v ;
        }

        flag = 0 ;
        dijkstra() ;
        max_path = speed[now];

        for(int i = 1 ; i <= N ; i++){
            for(int j = i+1 ; j <= N ; j++){
                if(graph[i][j]  &&max_path < 0.5 * (speed[i] + speed[j] + graph[i][j])){
                    max_path = 0.5 * (speed[i] + speed[j] + graph[i][j]) ;
                    st = i ;
                    ed = j ;
                    flag = 1 ;
                    break;
                }
            }
        }

        cout << "System #" << ++kase << '\n' ;
        if(flag == 1 ){
            cout << "The last domino falls after " << fixed << setprecision(1) << max_path
             << " seconds, between key dominoes " << st <<" and " << ed << ".";
        }
        else
            cout << "The last domino falls after " << fixed << setprecision(1) << max_path << " seconds, at key domino " << now << "." ;
        cout << "\n\n" ;

     }
    return 0;
}
