#include <iostream>
#include <bits/stdc++.h>
#define LOCAL


using namespace std;
int intNum[4020] = {} ;
int intDp[4020] = {} ;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin ) ;
#endif // LOCAL

    int intCase , n , intA ;
    cin >> intCase ;
    while(intCase--){
            cin >> n ;
        for(int i = n , j = 1 ; i > 0 ; i-- , j += 2 ){
            cin >> intA ;
            intNum[i] = intA ;
            intNum[i+j] = intA ;

            //debug
            //for(int i = 1 ; i <= n * 2 ; i++)
            //    cout << intNum[i] << ' ' ;
            //cout << '\n' ;

        }

        int intLIS = 0 , intLenDp = 0 ;
        intDp[intLenDp] = 0 ;
        for(int i = 1 ; i <= n * 2 ; i++){

            //debug
            //cout << intNum[i] << ' ' << intDp[intLenDp] << '\n' ;

            if(intNum[i] > intDp[intLenDp])
                intDp[++intLenDp] = intNum[i] ;
            else
                *lower_bound(intDp+1 , intDp + intLenDp , intNum[i] ) = intNum[i] ;

            //debug
            //for(int i = 0 ; i <= intLenDp ; i++)
            //    cout << intDp[i] << ' ' ;
            //cout << '\n' ;

        }
        cout << intLenDp << '\n' ;

        //debug
        //cout << '\n' ;
    }




    return 0;
}
