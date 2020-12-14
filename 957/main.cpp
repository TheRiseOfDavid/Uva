#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAX 1000010
using namespace std;
int y , p , temp , num[MAX] ;
int max_large , max_first , max_last ;

int bs(int l , int r , int v){
    int m ;
    while(l < r){
        //debug
        //cout << num[l] << ' ' << num[r] << '\n' ;
        m = (l+r) / 2 ;
        if(num[m] <= v) l = ++m;
        else r = m;
    }
    return m-1 ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    //freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    int large , first , last ;
    while(cin >> y){
        max_large = max_first = max_last = 0 ;
        large = first = last = 0 ;
        cin >> p ;
        for(int i = 0 ; i < p ; i++) cin >> num[i] ;
        for(int i = 0 ; i < p ; i++){
            last = bs(i,p,num[i]+y-1) ;
            first = i ;
            large = last - first +1 ;
            //debug
            //cout << "i = " << i << " binary search range " << num[first] << "-" << num[last] << " result is " << large << '\n' ;
            if(large >  max_large){
                max_large = large ;
                max_first = first ;
                max_last = last ;
            }
        }
        cout << max_large << " " << num[max_first] << " " << num[max_last] << '\n' ;
    }

    return 0;
}
