#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int u , v  ;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    while(cin >> u >> v){
        cout << u * v * 2 << '\n'  ;
    }

    return 0;
}
