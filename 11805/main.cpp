#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int t , n , k , p ;
int kase ;

int compute(){
    int temp = (k + p) % n ;
    if(temp == 0 )
        return n ;
    return  temp ;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL

    cin >> t ;
    while(t--){
        cin >> n >> k >> p ;
        cout << "Case " << ++kase << ": " << compute() << '\n' ;
    }

    return 0;
}
