#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define LOCAL
#define DEBUG
#define MAXN 10020
using namespace std;
int t, n ;
int segment, dna;
string s;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        segment = (1 << 27) - 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            dna = 0;
            for(int j = 0; j < s.size(); j++){
                dna |= (1 << (s[j] - 'a'));
            }

            if(dna & segment ) segment &= dna;
            else{
                segment = dna;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
