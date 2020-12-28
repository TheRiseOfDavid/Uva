#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int kase ;
double n , u , d , v ;
double fast ,shortest ;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    cin >> n ;
    while(n--){
        cin >> d >> v >> u;
        cout << "Case " << ++kase << ": " ;
        if(u == 0 || v == 0 || v >= u ){
            cout << "can't determine" << '\n' ;
            continue ;
        }

        fast = 0 ; shortest = 0 ;
        fast = d / u ;
        shortest = d / (u *cos(asin(v/u)));
        //cout << fast << ' ' << shortest << '\n' ;
        cout << fixed << setprecision(3) << abs(fast - shortest ) << '\n' ;
    }
    return 0;
}
