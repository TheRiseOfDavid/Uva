#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll t ;
    cin >> t ;
    while(t--){
        ll a , b;
        cin >> a >> b ;
        ll sum ;
        sum = ((b-a) + (b-1))* a / 2 ;
        cout << sum << '\n' ;
    }

}
