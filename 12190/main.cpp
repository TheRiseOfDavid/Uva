#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define LOCAL
using namespace std;
const int MAXN_quota = 1e18;
int price[] = {2,3,5,7};
int quota[] = {100,9900,990000, MAXN_quota};
int a, b;

int bill_convert_to_cwh(int bill){
    int chw = 0;
    for(int i = 0; i < 4; i++){
        if(bill > 0){
            chw += min(bill/price[i], quota[i]);
            bill -= min(bill/price[i], quota[i]) * price[i];
            //cout << "now_bill " << bill << '\n';
        }
    }
    return chw;
}

int chw_convert_to_bill(int chw){
    int bill = 0;
    for(int i = 0; i < 4; i++){
        if(chw > 0){
            bill += min(chw, quota[i]) * price[i];
            chw -= min(chw, quota[i]);
            //cout << "now_chw " << chw << '\n';
        }
    }
    return bill;
}

int binary_serach(int chw){
    int billA, billB;
    int left=0, right=chw;

    while(right > left){
        int mid = (left + right) / 2;
        billA = chw_convert_to_bill(mid);
        billB = chw_convert_to_bill(chw - mid);
        //cout << "bill " << billA << ' ' << billB << '\n';

        int diff = billB - billA;
        if(diff == b) break;
        if(diff < b) right = mid;
        if(diff > b) left = mid+1;
    }
    return billA;
}

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    int chwAll, chwA;
    while(cin >> a >> b && a+b != 0){
        chwAll = bill_convert_to_cwh(a);
        //cout << chwAll << '\n';
        int chwA = binary_serach(chwAll);
        cout << chwA << '\n';
        //cout << chw_convert_to_bill(chwA) << '\n';
    }
    return 0;
}
