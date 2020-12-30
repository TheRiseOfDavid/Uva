#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 15
#define oo 1e9
using namespace std;
int num[MAXN] ;
int t , n ;
int  kase  ;

int compute(){
    for(int i = 0 ; i < n ; i++){
        cin >> num[i] ;
    }
    //sort(num,num+n);

    return num[n/2] ;
}


int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL

    cin >> t ;
    while(t--){
        cin >> n ;
        cout << "Case " << ++kase << ": " << compute() << '\n' ;
    }

    return 0;
}
