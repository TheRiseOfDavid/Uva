#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int a1=0 , a2=1 , b1=1 , b2=1 , c1=1 , c2=0 ;
int d1 , d2 , t1 , t2 ;
double compute_b , compute_d , d_b1 , d_b2 , d_d1 , d_d2 ;
void bs(){ //binary search
    a1 = 0 ; a2 = 1 ;
    b1 = 1 ; b2 = 1 ;
    c1 = 1 ; c2 = 0 ;
    while(!(b1 == d1 && b2 == d2)){
        d_b1 = b1 ; d_b2 = b2 ;
        d_d1 = d1 ; d_d2 = d2 ;
        compute_b = d_b1 / d_b2 ;
        compute_d = d_d1 / d_d2 ;
        //cout << compute_b << ' ' << compute_d << '\n' ;
        if(compute_d > compute_b ){ //great than
            a1 = b1 ; a2 = b2 ;
            cout << "R" ;
        }
        else{ //less than
            c1 = b1 ; c2 = b2 ;
            cout << "L" ;
        }
        b1 = a1 + c1 ;
        b2 = a2 + c2 ;
        //cout << "a is " << a1 << '/' << a2 << '\n' ;
        //cout << "b is " << b1 << '/' << b2 << '\n' ;
        //cout << "c is " << c1 << '/' << c2 << '\n' ;
    }
    cout << '\n' ;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL

    while(cin >> d1 >> d2 && d1 + d2 != 2 ){
        //cout << d1 << ' ' << d2 << '\n' ;
        bs();
    }
    return 0;
}
