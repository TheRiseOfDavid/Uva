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
        else if (num[v] < num[t[m]]) r = m ;
        else return m ;
    }
    return r ;
}

int lcs(){
    dict.clear() ;
    for(int i = strA.length()-1 ; i > 0 ; i--) dict[strA[i]].push_back(i) ;

    int k = 0 ;
    for(int i = 1 ; i < strB.length() ; i++){
        for(int j = 0 ; j < dict[strB[i]].size() ; j++)
            num[++k] = dict[strB[i]][j] ;
    }
    if(k==0) return 0 ;
    //memset(t ,-1 , sizeof(t));
    d[1] = -1 , t[1] = 1 ;
    int len = 1, cur ;

    for(int i = 1 ; i <= k ; i++ ){
        if(num[i] > num[t[len]]) t[++len] = i , d[i] = t[len-1] ;
        else{
            cur = bs(1,len,i);
            t[cur] = i ;
            d[i] = t[cur-1];
        }

        //debug
//        for(int i = 1 ; i <= k ; i++)
//            cout << num[t[i]] << ' ' ;
//        cout << '\n' ;
    }
    return len ;

}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin ) ;
    freopen("out.txt" , "w" , stdout) ;
#endif // LOCAL
    n = 1 ;
    while(getline(cin,strA) && strA != "#"){
        getline(cin,strB);
        strA = "$" + strA;
        strB = "$" + strB;
        //cout << lcs() << '\n' ;
        cout << "Case #" << n++ << ": you can visit at most " << lcs() << " cities.\n";
    }
    return 0;
}
