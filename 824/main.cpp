#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define pos 8
using namespace std;
//int direct[pos][2] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}} ;
int direct[pos][2] = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}} ;
int counter_direct[] = {4,5,6,7,0,1,2,3} ;
map<pair<int,int>,int> record;
int x , y , d , a , b , c ;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    //freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    while(cin >> x >> y >> d && x != -1){
        record.clear();
        for(int i = 0 ; i < pos ; i++){
            cin >> a >> b >> c ;
            record[make_pair(a,b)] = c ;
        }
        int ox , oy , r ;
        ox = x ; oy = y ;
        r = counter_direct[d];
        //record[make_pair(x+direct[r][0],y+direct[r][1])] = 0;
        //cout << "r is " << x+direct[r][0] << ' ' << y+direct[r][1] << '\n' ;
        for(int i = 1 ; i <= pos ; i++){
            d = (r+i) % 8 ;
            //cout << "r is " << r << '\n' ;
            x = ox + direct[d][0] ;
            y = oy + direct[d][1] ;
            //cout << x << ' ' << y << '\n' ;
            if(record[make_pair(x,y)] == 1 ){
                cout << d << '\n' ;
                break ;
            }
        }

    }

    return 0;
}
