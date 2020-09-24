#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int n , p ;
    map<string , int > MapCountry ;
    map<string , int> MapName ;
    string strLine , strCountry , strName ;
    cin >> n ;
    cin.ignore() ;
    while(n--){
        getline(cin , strLine) ;
        p = strLine.find(' ') ;
        strCountry = strLine.substr(0 , p ) ;
        strName = strLine.substr(p+1 , strLine.length() ) ;

        //debug
        //cout << strName << ' ' << strCountry << '\n' ;

        if(MapCountry[strCountry])
            MapCountry[strCountry]++ ;
        else
            MapCountry[strCountry] = 1 ;
        if(!MapName[strName])
            MapName[strName] = 1 ;
    }
    for(auto it : MapCountry )
        cout << it.first << ' ' << it.second << '\n' ;

    return 0;
}
