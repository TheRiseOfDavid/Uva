#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int n ;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    while(cin >> n && n ){
        n = (n * (n+1) * (2*n+1)) / 6 ;
        cout << n << '\n' ;
    }
    return 0;
}
