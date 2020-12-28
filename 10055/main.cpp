#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int N , M ;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    while(cin >> N >> M)
        cout << abs(N-M) << '\n' ;
    return 0;
}
