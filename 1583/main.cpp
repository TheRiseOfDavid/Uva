#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define INF 99999999
using namespace std;
int intDict[200010] = {};

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int n , num , sum , intTemp ;
    for(int i = 100000 ; i > 0 ; i-- ){
        intDict[i] = INF ;
        sum = i ;
        intTemp = i ;
        while(intTemp){
            sum += intTemp % 10 ;
            intTemp /= 10 ;
        }
        if(intDict[sum] > i  )
        intDict[sum] = i ;
    }
    cin >> n ;
    while(cin >> n){
        if(intDict[n] == INF)
            cout << 0 << '\n' ;
        else
            cout << intDict[n] << '\n' ;
    }
    return 0;
}
