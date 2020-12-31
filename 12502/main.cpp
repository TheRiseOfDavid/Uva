#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
float t , hr , x , y , z ;
int cost ;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt","r" , stdin) ;
    freopen("out.txt", "w" , stdout);
#endif // LOCAL
    cin >> t ;
    while(t--){
        cin >> x >> y >> z ;
        cost = z * (2 * x - y) / (x + y ) ;
        if(cost < 0 ) cost = 0 ;
        cout << cost << '\n' ;
    }

    return 0;
}
