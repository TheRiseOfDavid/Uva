#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define minutes = minute of angle not time minutes
using namespace std;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin) ;
#endif // LOCAL
    string strA ;
    double a , s , douArc , douChord ;
    while(cin >> s >> a >> strA ){
        if(strA == "min")
            a /= 60 ;
        s += 6440 ;
        if(a > 180)
            a = 360 - a ;
        douArc = 2 * s * 2 * acos(0) * a / 360 ;
        douChord = sqrt(s * s + s * s - 2 * s * s * cos(2*acos(0) * a / 180 ) ) ;
        cout << fixed << setprecision(6) << douArc << ' ' << douChord << '\n' ;

    }
    return 0;
}
