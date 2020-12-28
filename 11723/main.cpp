#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define N 27
#define int long long
using namespace std;
int r , n , kase , cnt ;

void compute(){
    cnt = (r + n-1) / n ;
    cout << "Case " << ++kase << ": ";
    if(cnt > 27 )
        cout <<"impossible\n" ;
    else
        cout << cnt-1 << '\n' ;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    while(cin >> r >> n && r+n != 0 ){
        compute();
    }
    return 0;
}
