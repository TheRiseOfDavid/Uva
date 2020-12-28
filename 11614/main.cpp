#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 10000
#define int long long
using namespace std;
int n , a ;

int compute(int a ){
    return ((-1 + sqrt(1+8*a)) / 2) ;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    cin >> n ;
    while(n--){
        cin >> a ;
        cout << compute(a) << '\n' ;
    }
    return 0;
}
