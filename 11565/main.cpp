#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int A, B, C;
int t;

int solve(){
    for(int x = -100; x < 100; x++){
        for(int y = -100; y < 100; y++){
            int z = A - x -y;
            if(x - y == 0 || y - z == 0 || x - z == 0) continue;
            if(B != z * x * y) continue;
            if(C != (x*x + y*y + z*z)) continue;
            cout << x << ' ' << y << ' ' << z << '\n' ;
            return 1;
        }
    }
    return 0;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    cin >> t;
    while(t--){
        cin >> A >> B >> C;
        if(solve() == 0) cout << "No solution.\n";
    }

    return 0;
}
