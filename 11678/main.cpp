#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    set<int> A , B , diff_A , diff_B ;
    int x , y , intTemp ;
    while(cin >> x >> y && x && y){
        A.clear() ;
        B.clear() ;
        diff_A.clear() ;
        diff_B.clear() ;
        for(int i = 0 ; i < x ; i++){
            cin >> intTemp ;
            A.insert(intTemp) ;
        }
        for(int i = 0 ; i < y ; i++){
            cin >> intTemp ;
            B.insert(intTemp) ;
        }
        set_difference(A.begin() , A.end() , B.begin() , B.end() , inserter(diff_A, diff_A.begin()) ) ;
        set_difference(B.begin() , B.end() , A.begin() , A.end() , inserter(diff_B, diff_B.begin()) ) ;
        cout << min(diff_A.size() , diff_B.size()) << '\n' ;
    }
    return 0;
}
