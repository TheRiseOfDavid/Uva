#include <iostream>
#include <bits/stdc++.h>
#define LOCAL


using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL

    int intCase , n , intTemp , intNum[25] , isFlag , intSum  ;
    cin >> intCase ;
    while(intCase--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> intNum[i] ;

        isFlag = 0 ;

        for(int i = 0 ; i < 1010 ; i++){
            intSum = 0 ;
            intNum[n] = intNum[0] ;
            for(int j = 0 ; j < n ; j++ )
                intNum[j] = abs(intNum[j] - intNum[j+1]) ;

            for(int i = 0 ; i < n ; i++){
                //debug
                //cout << intNum[i] << ' ' ;

                intSum += intNum[i] ;
            }

            //debug
            //cout << '\n' ;

            if(!intSum){
                isFlag = 1 ;
                break ;
            }

        }
        if(isFlag)
            cout << "ZERO" << '\n' ;
        else
            cout << "LOOP" << '\n' ;
    }

    return 0;
}
