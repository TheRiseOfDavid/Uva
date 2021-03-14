#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 100020
#define Lson(x) (x<<1)
#define Rson(x) ((x<<1)+1)
using namespace std;
int num[MAXN];
int N, K, temp, a, b;
string cmd, result;
struct Node{
    int l, r;
    int v;
}node[4 * MAXN];


void build(int l, int r, int x = 1){
    node[x].l = l;
    node[x].r = r;
    if(l == r){
        node[x].v = num[l];
        return;
    }

    int mid = (l+r) / 2;
    build(l, mid, Lson(x));
    build(mid+1, r, Rson(x));
    node[x].v = node[Lson(x)].v * node[Rson(x)].v;
}

void modify(int p, int v, int x = 1){
    if(node[x].l == p && node[x].r == p){
        node[x].v = v;
        return;
    }

    int mid = (node[x].l+node[x].r) / 2;
    if(p <= mid) modify(p, v, Lson(x));
    if(p > mid) modify(p, v, Rson(x));
    node[x].v = node[Lson(x)].v * node[Rson(x)].v;
}

int query(int l, int r, int x = 1){
    if(node[x].l >= l && node[x].r <= r) return node[x].v;

    int mid = (node[x].l+node[x].r) / 2, ans = 1;
    if(l <= mid) ans *= query(l, r, Lson(x));
    if(r > mid) ans *= query(l, r, Rson(x));
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> N >> K){
        for(int i = 1; i <= N; i++){
            cin >> temp;
            if(temp > 0) temp = 1;
            else if(temp < 0) temp = -1;
            else if(temp == 0) temp = 0;
            num[i] = temp;
        }
        build(1, N);

        for(int i = 1; i <= K; i++){
            cin >> cmd >> a >> b;
            if(cmd == "C"){
                if(b > 0) b = 1;
                else if(b < 0) b = -1;
                else if(b == 0) b = 0;
                modify(a, b);
            }
            if(cmd == "P"){
                int ans = query(a, b);

                if(ans > 0) result = "+";
                else if(ans < 0) result = "-";
                else if(ans == 0) result = "0";
                cout << result;
            }
        }
        cout << '\n';
    }
    return 0;
}
