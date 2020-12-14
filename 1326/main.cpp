#include <bits/stdc++.h>
#include <iostream>
#define LOCAL
#define MAXN 30
using namespace std ;
int n , mark[MAXN] , x ;
string temp ;

int main(){
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL

    while(cin >> n){
        memset(mark,0,sizeof(mark));
        for(int i = 0 ; i < n ; i++){
            cin >> temp ;
            x = 0 ;
            for(int j = 0 ; j < temp.length() ; j++)
                x ^= 1 << (temp[j] - 'A');
            mark[i] = x ;
        }
        map<int,int> m1 , m2 ;
        int div1 = n/2 , div2 = n - n/2 ;
        for(int i = 0 ; i < ( 1 <<div1) ; i++ ){
            x = 0 ;
            for(int j = 0 ; j < div1 ; j++ ){
                if((i >> j ) & 1) x ^= mark[j] ;
            }
            if(!m1.count(x) || __builtin_popcount(m1[x]) < __builtin_popcount(i) )
                m1[x] = i ;
        }
        for(int i = 0 ; i < (1 << div2) ; i++){
            x = 0 ;
            for(int j = 0 ; j < div2 ; j++){
                if((i >> j ) & 1) x ^= mark[j + div1];
            }
            if(!m2.count(x) || __builtin_popcount(m2[x]) < __builtin_popcount(i) )
                m2[x] = i ;
        }
        int resMask = 0 , resCnt = 0 ;
        for(auto it : m1){
            if(m2.count(it.first)){
                x = (m2[it.first] << div1) | it.second ;
                if(resCnt < __builtin_popcount(x)) resCnt = __builtin_popcount(x) , resMask = x ;
            }
        }
        int flag = 1 ;
        cout << resCnt << '\n' ;
        for(int i = 0 ; i < n ; i++){
            if((resMask >> i) & 1){
                if(flag) cout << i+1 ;
                else cout << ' ' << i+1 ;
                flag = 0 ;
            }
        }
        cout << '\n' ;
    }


}
