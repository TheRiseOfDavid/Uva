#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define ll long long int
using namespace std;
int intNum[500050] , intTemp[500050] ;


ll merge_sort(int l , int r){
    //debug
    //cout << l << ' ' << r << '\n';

    if(l >= r)
        return 0 ;
    ll L , R ;
    L = merge_sort(l , (r+l)/2) ;
    R = merge_sort( (r+l) /2 +1 , r );
    int intP_Start , intQ_Start , intP_End , intPosition ;
    intP_Start = l ;
    intP_End = (r+l) /2 ;
    intQ_Start = intP_End +1 ;
    intPosition = l ;
    while(intPosition <= r ){
        if(intQ_Start <= r && (intP_Start > intP_End || intNum[intQ_Start] < intNum[intP_Start] ) ){
            intTemp[intPosition++] = intNum[intQ_Start++] ;
            L += intP_End - intP_Start + 1 ;
        }
        else
            intTemp[intPosition++] = intNum[intP_Start++] ;
    }

    for(int i = l ; i <= r ; i++)
        intNum[i] = intTemp[i] ;

    //debug
    //for(int i = 0 ; i < 10 ; i++)
    //    cout << intNum[i] << ' ' ;
    //cout << '\n' ;
    return L + R ;

}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int n ;
    while(cin >> n && n ){
        for(int i = 0 ; i < n ; i++)
            cin >> intNum[i] ;
        cout << merge_sort(0 , n-1 ) << '\n' ;
    }

    return 0;
}
