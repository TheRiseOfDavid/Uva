#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin ) ;
#endif // LOCAL
    int intCase , x , y , intStep , intDistance , intSum , intLength ;
    cin >> intCase ;
    while(intCase--){
        cin >> x >> y ; 
        intStep = 0 ;
        intDistance = y - x ;
        intSum = 0 ;
        intLength = 0 ;
        //debug
        //cout << intDistance << '\n' << '\n' ;
        /*
        if(intDistance == 1){
            cout << 1 << '\n' ;
            continue ;
        }
        */
       
        while(++intLength){
            if(intSum + intLength * 2 > intDistance)
                break ;
            intSum += intLength * 2 ;
            intStep +=2;
        }
        //debug
        //cout << "intLength: " << intLength << '\n' ;
        //cout << "intSum: " << intSum << '\n' ;

        if(intSum + intLength < intDistance)
            intStep += 2 ;
        else if (intSum != intDistance )
            intStep ++ ;
        cout << intStep << '\n' ;


    }
    return 0;
}
