#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    int n;
    double t, s, d, ton;

    cin >> n;
    while(n--){
        cin >> t >> s >> d;
        ton = d * 1000 * 100 * 10 / (t * 24 * 60* 60);
        if(floor(ton) > 0) cout << "Remove " << floor(ton) << " tons\n";
        else cout << "Add " << floor(abs(ton)) << " tons\n";
    }

    return 0;
}
