#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 110
using namespace std;
map<pair<int,int>,int> mp_lost ;
int direct[4][2] = {{0,1},{-1,0},{0,-1},{1,0}} ;
int n , m ; // n,m is border and d is now direct
int sx , sy , tx , ty , d ; //start x , start y ,
string ins , str_d; //instruction
map<char,int> map_sd ;
map<int,string> back_sd ;

int in_grid(int x , int y , int d  ){
    if(x < 0 || x > n )
        return 0 ;
    if(y < 0 || y > m )
        return 0 ;
    return 1 ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    cin >> n >> m ;
    map_sd['N'] = 0 ;
    map_sd['W'] = 1 ;
    map_sd['S'] = 2 ;
    map_sd['E'] = 3 ;
    back_sd[0] = "N";
    back_sd[1] = "W";
    back_sd[2] = "S";
    back_sd[3] = "E";
    while(cin >> sx >> sy >> str_d ){
        cin >> ins ;
        //cout << ins << '\n' ;
        d = map_sd[str_d[0]] ;
        int flag = 1;
        for(int i = 0 ; i < ins.length() ; i++){
            if(ins[i] == 'F'){
                tx = sx ;
                ty = sy ;
                sx += direct[d][0] ;
                sy += direct[d][1] ;
                pair<int,int> pa(tx,ty) ;
                if(in_grid(sx,sy,d) == 0){
                    if(mp_lost.count(pa)){ //indicate past robot fell
                        sx = tx ;
                        sy = ty ;
                        continue ;
                    }
                    cout << tx << ' ' << ty << ' ' << back_sd[d] << ' ' << "LOST" <<'\n';
                    mp_lost[pa] = 1 ;
                    flag = 0 ;
                    break ;
                }
            }
            if(ins[i] == 'L')
                d = (d+4+1) % 4 ;
            if(ins[i] == 'R')
                d = (d+4-1) % 4 ;
            //cout << "i is : " << sx << ' ' << sy << ' ' << back_sd[d] << '\n' ;
        }
        if(flag)
            cout << sx << ' ' << sy << ' ' << back_sd[d] <<'\n';
    }
    return 0;
}
