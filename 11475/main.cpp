#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
using namespace std;
string strA , strB ;
int b[MAXN] , p[MAXN] ;

void kmp_process(){
    int n = strB.length() ,i = 0 ,  j = -1 ;
    b[0] = -1 ;
    while(i < n ){
        while(j >= 0 && strB[i] != strB[j]) j = b[j] ;
        i++ ; j++ ;
        b[i] = j ;
    }

    //debug
//    for(int k = 0 ; k <= n ; k++)
//        cout << b[k] << ' ' ;
//    cout << '\n' ;
}

int kmp(){
    int n = strA.length() , m=strB.length() , i=0 , j=0  ;
    while(i < n ){
        while(j >= 0 && strA[i] != strB[j]) j = b[j] ;
        i++ ; j++ ;
    }
    return j ;
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL

    while(cin >> strA){
        strB = strA;
        reverse(strB.begin() , strB.end());
        kmp_process();
        int n = kmp() ;
        cout << strA << strB.substr(n) << '\n' ;
    }
    return 0;
}
