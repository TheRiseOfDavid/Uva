#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define N 120
using namespace std;
int n ;
string strA , strB ;
int t[N*N] , d[N*N] , num[N*N] ; //determine
map<char,vector<int>> dict ;

int bs(int l , int r , int v ){
    int m ;
    while(r>l){
        m = (l+r) /2 ;
        if(num[v] > num[t[m]]) l = m+1 ;
        else r = m-1 ;
    }
    return r ;
}

int lcs(){
    dict.clear() ;
    for(int i = strA.length() ; i > 0 ; i--) dict[strA[i]].push_back(i) ;

    int k = 1 ;
    for(int i = 1 ; i < strB.length() ; i++){
        for(int j = 0 ; j < dict[strB[i]].size() ; j++)
            num[k++] = dict[strB[i]][j] ;
    }

    //memset(t ,-1 , sizeof(t));
    d[1] = -1 , t[1] = 1 ;
    int len = 1 , cur ;
    //debug
//    cout << "k is " << k << '\n' ;
//    cout << "num is \n" ;
//    for(int i = 1 ; i < k ; i++) cout << num[i] << ' ' ;
//    cout << "\n\n" ;
    for(int i = 1 ; i < k ; i++ ){
        //debug
//        cout << "i is " << i << '\n' ;
//        cout << "len is " << len << '\n' ;
//        cout << num[i] << ' ' << num[t[len]] << '\n' ;
        if(num[i] > num[t[len]]) t[++len] = i , d[i] = t[len-1] ;
        else{
            cur = bs(0,len,i);
            //debug
            //cout << "cur is " << cur << '\n' ;
            t[cur] = i ;
            d[i] = t[cur-1];
        }
        //debug
        //cout << "t is \n" ;
//        for(int i = 0 ; i < k ; i++) cout << num[t[i]] << ' ' ;
//            cout << "\n\n" ;
    }
    return len ;

}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin ) ;
#endif // LOCAL
    n = 1 ;
    while(cin >> strA && strA != "#"){
        cin >> strB ;
        strA = strA + " " ;
        strB = strB + " " ;
        cout << "Case #" << n++ << ": you can visit at most " << lcs() << " cities.\n";
    }
    return 0;
}
