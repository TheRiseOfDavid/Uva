#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin ) ;
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int intMax= 11 , intMin = 0 , isRight = 1 , n ;
    string strLine ;
    while(scanf("%d\n" , &n ) && n ){
        getline(cin , strLine ) ;

        if (strLine == "right on"){
            if(intMax <= n || intMin >= n)
                isRight = 0 ;

            if(isRight)
                cout << "Stan may be honest" << '\n' ;
            else
                cout << "Stan is dishonest" << '\n' ;

            //debug
            //cout << intMax << ' ' << intMin << ' ' << n << '\n' ;

            isRight = 1 ;
            intMax = 11 ;
            intMin = 0 ;
            continue ;
        }
        if(strLine == "too high" && intMax > n ){
            intMax = n ;
        }
        else if (strLine == "too low" && intMin < n ){
            intMin = n ;
        }

    }
    return 0;
}
