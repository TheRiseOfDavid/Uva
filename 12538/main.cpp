#include <iostream>
#include <bits/stdc++.h>
#include <ext/rope>
#define LOCAL
#define MAXN 50020
using namespace std;
using namespace __gnu_cxx ;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int n , t , a , b , c , d=0 ;
    int v = 0 ;
    string strA ;
    rope<char> r[MAXN] , rtmp ;
    cin >> n ;
    while(n--){
        cin >> t ;

        if(t==1){
            cin >> a ;
            cin >> strA ;
            a -= d ;
            r[++v] = r[v] ;
            r[v].insert(a,strA.c_str());
            //debug
            //cout << r[v] << '\n' ;
        }
        else if(t==2){
            cin >> a >> b ;
            a -= d ; b -= d ;
            r[++v] = r[v] ;
            r[v].erase(a-1,b);
            //debug
            //cout << r[v] << ' ' << r[v-1] << '\n' ;
        }
        else if(t==3){
            cin >> a >> b >> c ;
            a -= d ; b -= d ; c -= d ;
            rtmp = r[a].substr(b-1,c) ;
            cout << rtmp << '\n' ;
            d += count(rtmp.begin() , rtmp.end() , 'c' );
        }
    }
    return 0;
}
