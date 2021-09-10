#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
#define MAXN 100020
using namespace std;
int num[MAXN], n;
int f = 9;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL

    memset(num, 0x3f3f3f, sizeof(num));
    int sum = 1;
    num[0] = 0;
    for(int i = 1; i < 9; i++){
        sum *= i;
        for(int j = sum; j < MAXN; j++){
            num[j] = min(num[j], num[j - sum]+1);
        }
    }

    //for(int i = 0; i < 30; i++) cout << num[i] << "\n";

    while(cin >> n){
        cout << num[n] << "\n";
    }
    return 0;
}
