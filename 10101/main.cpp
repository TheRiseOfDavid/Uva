#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

void recursive(string strInt){
    int len , intCout ;
    // hajar 10000000
    len = strInt.length() - 7;
    if(len > 0 ){
        recursive(strInt.substr(0,len));
        cout << " kuti" ;
        strInt = strInt.substr(strInt.length()-7 , 7);
    }

    // lakh 100000
    len = strInt.length() - 5;
    if(len > 0){
        intCout = stoi(strInt.substr(0,len));
        if(intCout)
            cout << ' ' << intCout << " lakh";
        strInt = strInt.substr(strInt.length()-5 , 5);
    }

    // hajar 1000
    len = strInt.length() - 3;
    if(len > 0){
        intCout = stoi(strInt.substr(0, len));
        if(intCout)
            cout << ' ' << intCout << " hajar";
        strInt = strInt.substr(strInt.length()-3 , 3);
    }

    // shata 100
    len = strInt.length() - 2;
    if(len > 0){
        intCout = stoi(strInt.substr(0,len));
        if(intCout)
            cout << ' ' << intCout << " shata";
        strInt = strInt.substr(strInt.length()-2 , 2);
    }
    if(stoi(strInt))
        cout << ' ' << stoi(strInt) ;
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    string strInt;
    int intCase=1 , len , intTemp;
    while(cin >> strInt){
        for(int i = 0 ; i < 4- to_string(intCase).length() ; i++ )
            cout << ' ' ;
        cout << intCase++ << "." ;
        recursive(strInt);
        if(strInt == "0")
            cout << " 0" ;
        cout << '\n' ;

    }
    return 0;
}
