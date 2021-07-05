#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAXN = 10000;
int record[MAXN][10];
int n, t;

void pretreatment(){
    for(int i = 1; i < 10000; i++){
        int num = i;
        while(num){
            record[i][num % 10]++;
            num /= 10;
        }

        for(int j = 0; j < 10; j++) record[i][j] += record[i-1][j];
    }
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL
    pretreatment();
    cin >> n;
    while(n--){
        cin >> t;

        cout << record[t][0];
        for(int i = 1; i < 10; i++) cout << ' ' << record[t][i];
        cout << '\n';
    }

    return 0;
}
