#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define Maxn_Num 1000000000
using namespace std;
enum {Maxn = Maxn_Num , sqrt_max = (int)sqrt(Maxn_Num)};
vector<int> prime ;

int count_div(int x ){
    int total =1 , j ;
    for(int i = 0 ; i < prime.size() && x ; i++){
        j = 1 ;
        while(x % prime[i] ==0 ){
            x /= prime[i];
            j++ ;
        }
        total *= j ;
    }
    return total;
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin) ;
#endif // LOCAL

    int flag ;
    for(int i = 2 ; i <= sqrt_max ; i++){
        flag = 1 ;
        for(int j = 2 ; j <= sqrt(i) ; j++ ){
            if(i % j == 0 ){
                flag = 0;
                break;
            }
        }
        if(flag)
            prime.push_back(i);
    }

/**<      //debug
    for(auto it : prime)
        cout << it << '\n' ;
*/
    int n , l , u, temp;
    cin >> n ;
    while(n--){
        cin >> l >> u ;
        pair<int , int> divMax = {0,0} ;
        for(int i = l ; i <= u ; i++){
            temp = count_div(i);
            if ( temp > divMax.second){
                divMax.first = i ;
                divMax.second = temp ;
            }
        }
        cout << "Between " << l << " and " << u << ", " << divMax.first << " has a maximum of " << divMax.second << " divisors.\n";
    }

    return 0;
}
