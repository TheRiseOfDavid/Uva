#include <iostream>
#include <bits/stdc++.h>
#define LOCAL


using namespace std;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin) ;
#endif // LOCAL
    int intCase , D , I , intNow ;
    cin >> intCase ;
    while(intCase--){
        cin >> D >> I ;
        intNow = 1 ;
        for(int i = 1 ; i < D ; i++){
            if(I % 2 ){
                intNow = intNow * 2 ;
                I = (I+1) /2 ;
            }
            else{
                intNow = intNow * 2 +1 ;
                I /= 2 ;
            }
        }
        cout << intNow << '\n' ;
    }
    return 0;
}
