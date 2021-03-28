#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1020
using namespace std;
int n, m, idx, ans, temp, kase=1;
int num[MAXN];
vector<int> sum;

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    while(cin >> n && n){
        sum.clear();
        sum.push_back(-0x3f3f3f);
        for(int i = 0; i < n; i++){
            cin >> num[i];
            for(int j = i-1; j >= 0; j--) sum.push_back(num[i]+num[j]);
        }
        sort(sum.begin(), sum.end());

        cout << "Case " << kase++ << ":\n";
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> temp;
            idx = upper_bound(sum.begin(), sum.end(), temp) - sum.begin();
            int gap1 = abs(sum[idx] - temp);
            int gap2 = abs(sum[idx-1] - temp);
            //cout << sum[index] << ' ' << sum[index-1] << '\n';
            if(gap2 < gap1) cout << "Closest sum to " << temp << " is " << sum[idx-1] << ".\n";
            else cout << "Closest sum to " << temp << " is " << sum[idx] << ".\n";
        }

    }

    return 0;
}
