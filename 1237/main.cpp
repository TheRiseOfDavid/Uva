#include <iostream>
#include <bits/stdc++.h>
#define MAXN 10020
#define LOCAL
#define lson(x) ((x << 1) +1)
#define rson(x) ((x << 1) +2)
using namespace std;
int t, h, m, l, p, d, q;
struct Com{
    int l, r;
    string v;
};
Com com[MAXN];

string solve(int p){
    string name = "";
    for(int i = 0; i < d; i++){
        if(p >= com[i].l && p <= com[i].r){
            if(name == "" ) name = com[i].v;
            else return "UNDETERMINED";
        }
    }
    if(name == "" ) name = "UNDETERMINED";
    return name;
}

int main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        cin >> d;
        for(int i = 0; i < d; i++) cin >> com[i].v >> com[i].l >> com[i].r;
        cin >> q;
        string name;
        for(int i = 0; i < q; i++){
            cin >> p;
            name = solve(p);
            cout << name << '\n';
        }
        if (t != 0) cout << '\n';
    }

}
