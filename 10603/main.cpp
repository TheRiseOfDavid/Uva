#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 220
using namespace std;
int visit[MAXN][MAXN] , ans[MAXN] , cap[5] , d ;
// https://www.twblogs.net/a/5b87da1e2b71775d1cd945e5

struct status{
    int jug[3] , vol ;
    bool operator < (const status& rhs ) const{
        return vol > rhs.vol ;
    }
};

priority_queue<status> p ;


void update_ans(status s ){
    for(int i = 0 ; i < 3 ; i++){
        int d = s.jug[i] ;
        if(ans[d] < 0 )
            ans[d] = s.vol ;
    }
}


void bfs(){
    status s , cs ; // cs copy_s
    s.jug[0] = 0 ; s.jug[1] = 0 ; s.jug[2] = cap[2] ; s.vol = 0 ;
    p.push(s) ;
    int temp;
    while(!p.empty()){
        s = p.top() ;
        p.pop() ;
        update_ans(s);
        visit[s.jug[0]][s.jug[1]] = 1 ;
        //debug
        //cout << "" << s.jug[0] << ' ' << s.jug[1] << ' ' << s.jug[2] << ' ' << s.vol << '\n' ;
        if(ans[d] >= 0)
            break ;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(i == j || s.jug[j] == cap[j] || s.jug[i] == 0) // e.v[j] == cap[j] this cup water is full , so it doesn't have any water
                    continue ;
                cs = s ;
                temp = min(cap[j] , s.jug[i] + s.jug[j]) -s.jug[j] ;
                cs.jug[i] -= temp ;
                cs.jug[j] += temp ;
                cs.vol += temp ;
                if(!visit[cs.jug[0]][cs.jug[1]]){
                    p.push(cs);
                    //debug
                    //cout << cs.jug[0] << ' ' << cs.jug[1] << ' ' << cs.jug[2] << ' ' << cs.vol << '\n' ;
                    //cout << visit[cs.jug[0]][cs.jug[1]] << '\n' ;
                    //cout << &s << ' ' << &cs << '\n' ;
                }
            }
        }
    }
    while(d>=0){
        if(ans[d] != -1){
            cout << ans[d] << ' ' << d << '\n' ;
            break ;
        }
        d-- ;
    }
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int n ;
    cin >> n ;
    while(n--){
        cin >> cap[0] >> cap[1] >> cap[2] >> d ;
        memset(visit , 0 , sizeof(visit)) ;
        memset(ans , -1 , sizeof(ans)) ;
        while(!p.empty()) // priority_queue doesn't have clear
            p.pop() ;
        bfs() ;
    }

    return 0;
}
