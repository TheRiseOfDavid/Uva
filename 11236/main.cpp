#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 2*1e9
#define int long long
using namespace std;
int c = 1e6;

//add more fast than product
void solve(){
    for(int a1 = 1; a1 <= 2000; a1++){
        //if(pow(a1,4) >= MAXN) break;
        if(a1+a1+a1+a1 > 2000) break;
        for(int a2 = a1; a2 <= 2000-a1; a2++ ){
            //if(a1+pow(a2,3) >= MAXN) break;
            if(a1+a2+a2+a2 > 2000) break;
            for(int a3 = a2; a3 <= 2000-a1-a2; a3++){
                //if(a1+a2+pow(a3,2) >= MAXN) break;
                if(a1+a2+a3+a3 > 2000) break;

                int sum = a1 + a2 + a3;
                int product = a1 * a2 * a3;
                if(product <= c) continue;
                if((sum*c) % (product-c) != 0) continue;

                int a4 = (sum*c) / (product-c);
                if(a3 > a4) continue;
                if(sum + a4 > 2000) continue;
                if(product * a4 > MAXN) continue;
                cout << fixed << setprecision(2) << a1/100.0 << ' ' << \
                    fixed << setprecision(2) << a2/100.0 << ' ' << \
                    fixed << setprecision(2) << a3/100.0 << ' ' << \
                    fixed << setprecision(2) << a4/100.0 << '\n';
            }
        }
    }
}

int32_t main()
{

    solve();
    return 0;
}
