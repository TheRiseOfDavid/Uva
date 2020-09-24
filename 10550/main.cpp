#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin);
#endif // LOCAL
    int a, b, c, d ;
    while(cin >> a >> b >> c >> d && (a + b + c + d) != 0){
        int calibration = 120;
        calibration += (40 + a - b ) % 40 ;
        calibration += (40 - b + c ) % 40 ;
        calibration += (40 + c - d ) % 40 ;
        cout << calibration * 9 << '\n' ;
    }
    return 0;
}
