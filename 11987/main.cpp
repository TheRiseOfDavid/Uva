#include <iostream>
#include <bits/stdc++.h>
#define LOCAL

using namespace std;
int intSum[200080] , intParent[200080] , intSet[200080] ;


int find_root(int intA){
    if(intParent[intA] == intA)
        return intA ;
    intParent[intA] = find_root(intParent[intA]) ;
    return intParent[intA] ;
}


int each_debug(int n ){
    for(int i = 1 ; i <= n ; i++){
        cout << i << ' ' << intParent[i] << ' '  \
            << intSet[find_root(i)] << ' ' << intSum[find_root(i)] << '\n' ;
    }
    system("Pause") ;
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt","r", stdin);
    freopen("out.txt" ,"w" , stdout) ;
#endif // LOCAL

    int n, m , operation , p , q  ;
    while(cin >> n >> m){
        for(int i = 1 ; i <= n ; i++){
            intParent[i] = i+n ;
            intParent[i+n] = i+n ;
            intSum[i+n] = i;
            intSet[i+n] = 1 ;
        }
        while(m--){
            cin >> operation ;
            if(operation == 1 ){
                cin >> p >> q ;
                int intRoot_p , intRoot_q ;
                intRoot_p = find_root(intParent[p]) ;
                intRoot_q = find_root(intParent[q]) ;
                if(intRoot_p != intRoot_q){
                    intParent[intRoot_q] = intRoot_p ;
                    intSum[intRoot_p] += intSum[intRoot_q] ;
                    intSet[intRoot_p] += intSet[intRoot_q] ;
                }
                //debug
                //each_debug(n) ;

            }
            else if (operation == 2 ){
                cin >> p >> q ;
                int intRoot_p , intRoot_q ;
                intRoot_p = find_root(intParent[p]) ;
                intRoot_q = find_root(intParent[q]) ;
                if(intRoot_p != intRoot_q){
                    intParent[p] = intRoot_q ;
                    intSum[intRoot_q] += p ;
                    intSum[intRoot_p] -= p ;
                    intSet[intRoot_q] ++ ;
                    intSet[intRoot_p] -- ;
                }
                //debug
                //each_debug(n) ;
            }
            else if (operation == 3){
                cin >> p ;
                cout << intSet[find_root(p)] << ' ' << intSum[find_root(p)] << '\n' ;
            }
        }
    }

    return 0;
}
