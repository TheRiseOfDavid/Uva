#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define N 25
using namespace std;
int a[N] , b[N] , t[N] , d[N] , n ;
map<int,int> dict ;

int bs(int l , int r , int v){
    int m ;
    while(r>l){
        m = (r+l) / 2 ;
        if(b[v] > b[t[m]] ) l = m+1 ;
        else r = m ;
    }
    return r ;
}

int lis(){
    int len = 1 , cur ;
    d[1] = 0 , t[1] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        if(b[i] > b[t[len]] ){
            d[i] = t[len] ;
            t[++len] = i ;
        }
        else{
            cur = bs(1,len,i);
            t[cur] = i ;
            d[i] = t[cur-1] ;
        }
    }
    return len ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    cin >> n ;
    int j , temp ;
    for(int i = 1 ; i <= n ; i++){
        cin >> temp ;
        a[i] = temp ;
    }

    while(cin >> j ){
        b[j] = a[1]  ;
        for(int i = 2 ; i <= n ; i++){
            cin >> temp ;
            b[temp] = a[i] ;
        }
        //debug
        //for(int i = 1 ; i <= n ; i++) cout << b[i] << ' ' ;
        cout << lis() << '\n' ;
    }

    return 0;
}
