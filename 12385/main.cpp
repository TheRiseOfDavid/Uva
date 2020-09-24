#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL

    int n ,t , last , ans , temp ;
    int num[100020] = {} ;
    cin >> t ;
    while(t--){
        ans = 0;
        last = 0 ;
        for(int i = 0 ; i < 100020 ; i++)
            num[i] = -1 ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> temp ;
            if( num[temp] >= last){

                //debug
                //cout << "debug: " <<  i << " last: " << last << '\n' ;

                ans++ ;
                last = i ;

            }
            num[temp] = i ;
        }
        cout << ans << '\n' ;
    }

    return 0;
}
