#include <iostream>
#include <bits/stdc++.h>
#define LOCAL

using namespace std;


void decode(string strLetter , int intCount ){
    for(int i = 0 ; i < intCount ; i++ )
        cout << strLetter ;
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt","r" , stdin) ;
    freopen("out.txt" , "w" , stdout ) ;
#endif // LOCAL
    int intCase ;
    string strLine , strLetter , strCount ;
    cin >> intCase ; cin.ignore() ;
    for(int t = 1 ; t <= intCase ; t++){
        getline(cin , strLine) ;
        cout << "Case " << t << ": " ;
        strCount = "0" ;
        for(int i = 0 ; i < strLine.length() ; i++ ){
            if(isalpha(strLine[i])){
               decode(strLetter , stol(strCount)) ;
               strLetter = strLine[i] ;
               strCount = "" ;
            }
            else
                strCount += strLine[i] ;
        }
        decode(strLetter , stol(strCount));
        cout << '\n' ;
    }
    return 0;
}
