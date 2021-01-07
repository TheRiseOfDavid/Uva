#include <bits/stdc++.h>
#define LOCAL
using namespace std;
struct t{
    int a ;
    bool operator<(t c){
        return c.a < a ;
    }
};
int main() {
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    set<int> s ;
    if(s.count(1))
        cout << "Hi" << '\n' ;
    if(s.count(1))
        cout << "Hi" << '\n' ;
    return 0;
}
