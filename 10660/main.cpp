#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 30
using namespace std;
int num[MAXN], ans[MAXN], result[MAXN];
int t, n, a, b, c;
int d = MAXN*MAXN*1000;

void dfs(int p, int office){
    if(office >= 5){
        int sum = 0;
        //cout << "result " << result[i] << '\n';
        for(int j = 0; j < 25; j++){
            int compute = MAXN*MAXN*1000, temp;
            for(int i = 0; i < 5; i++){
                temp = num[j] * (abs(result[i]/5 - j/5) + abs(result[i]%5 - j%5));
                compute = min(temp, compute);
            }
            sum += compute;
        }

        if(sum < d){
            //cout << "test:" << sum << ' ';
            d = sum;
            for(int i = 0; i < 5; i++){
                ans[i] = result[i];
                //cout << result[i] << ' ';
            }
            //cout << '\n';
        }
        return;
    }
    for(int i = p+1; i < 25; i++){
        result[office] = i;
        dfs(i, office+1);
    }
}

void debug(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            cout << num[i*5+j] << ' ';
    cout << '\n';
    }
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> n;
        memset(num, 0, sizeof(num));
        while(n--){
            cin >> a >> b >> c;
            num[a*5+b] = c;
        }
        //debug();
        d = MAXN*MAXN*1000;
        dfs(-1, 0);

        cout << ans[0];
        for(int i = 1; i < 5; i++) cout << ' ' << ans[i];
        cout << '\n';
    }
    return 0;
}
