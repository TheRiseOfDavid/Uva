#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int num[10010] ;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    int n = 1 , step = 0 ;
    for(int i = 1 ; i < 10010 ; i++){
        num[i] = step ;
        if(i == n){
            n = n << 1;
            step++;
        }
    }
    step = 1;
    while(cin >> n && n >= -1){
        cout << "Case " << step << ": " << num[n] << '\n' ;
        step++;
    }

    return 0;
}
