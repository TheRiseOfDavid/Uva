#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 10020
using namespace std;
int n, temp;
int num[MAXN], lis_index[MAXN], lds_index[MAXN];
deque<int> lis, lds;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> n){
        lis.clear(); lds.clear();
        for(int i = 0; i < n; i++) cin >> num[i];

        //LIS
        lis.push_back(num[0]);
        lis_index[0] = 0;
        for(int i = 1; i < n; i++){
            if(num[i] > lis.back()){
                lis_index[i] = lis.size(); //be careful, lower_bound => deque.size(). NOT LIS length
                lis.push_back(num[i]);
            }
            else{
                temp = lower_bound(lis.begin(), lis.end(), num[i]) - lis.begin();
                lis[temp] = num[i];
                lis_index[i] = temp;
            }
        }

        //LDS
        lds.push_back(num[n-1]);
        lds_index[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            if(num[i] > lds.back()){
                lds_index[i] = lds.size();
                lds.push_back(num[i]);
            }
            else{
                temp = lower_bound(lds.begin(), lds.end(), num[i]) - lds.begin();
                lds[temp] = num[i];
                lds_index[i] = temp;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            //cout << "i lis lds " << i << " " << lis_index[i] << " " << lds_index[i] << "\n";
            ans = max(ans, min(lis_index[i], lds_index[i]) * 2 + 1);
        }
        cout << ans << '\n';
    }

    return 0;
}
