#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
//#define DEBUG
#define MAXN 1020
#define int long long
using namespace std;
int n, f, t;
int add[2][100000];
int subtract[2][100000];
int num[MAXN];

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> n >> f && n){
        memset(add, 0, sizeof(add));
        memset(subtract, 0, sizeof(subtract));

        for(int i = 0; i < n; i++) cin >> num[i];

        int L=50000-num[0], R=50000+num[0], roll = 0;
        add[0][R] = 1;
        subtract[0][L] = 1;

        for(int i = 1; i < n; i++){
            memset(add[!roll], 0, sizeof(add[!roll]));
            memset(subtract[!roll], 0, sizeof(subtract[!roll]));

            for(int j = L; j <= R; j++){
                if(add[roll][j] || subtract[roll][j]){
                    int add_value = j + num[i];
                    add[!roll][add_value] |= add[roll][j] | (1LL << i);
                    subtract[!roll][add_value] |= subtract[roll][j];

                    int subtract_value = j - num[i];
                    add[!roll][subtract_value] |= add[roll][j];
                    subtract[!roll][subtract_value] |= subtract[roll][j] | (1LL << i);
                }
            }
            L -= num[i];
            R += num[i];
            roll = !roll;

            //cout << "roll " << roll << '\n';
        }

        #ifdef DEBUG
        for(int i = L-50000; i <= R-50000; i++) printf("%3d ", i);
        cout << '\n';
        for(int i = L; i <= R; i++) printf("%3d ", add[roll][i]);
        cout << '\n';
        #endif //debug

        f += 50000;
        if(add[roll][f] == 0 && subtract[roll][f] == 0){
            cout << "*" << "\n";
            continue;
        }
        for(int i = 0; i < n; i++){
            int item = 1LL << i;
            if(add[roll][f] & item){
                if(subtract[roll][f] & item) cout << "?";
                else cout << "+" ;
            }
            else if(subtract[roll][f] & item) cout << "-";
        }
        cout << "\n";

    }
    return 0;
}
