#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define Lson(x) x << 1
#define Rson(x) (x << 1) + 1
#define MAXN 100020
using namespace std;
int n, q, ta, tb;
struct tree{
    int l, r, v;
    tree(){}
    tree(int _l, int _r, int _v): l(_l), r(_r), v(_v) {}
}node[4 * MAXN];
struct NUM{
    int l, r, f, v;
}num[MAXN];


void build(int left, int right, int x = 1){
    node[x].l = left;
    node[x].r = right;

    if(left == right){
        node[x].v = num[left].f;
        return;
    }

    int mid = (left + right) / 2;
    build(left, mid, Lson(x));
    build(mid + 1, right, Rson(x));
    node[x].v = max(node[Lson(x)].v, node[Rson(x)].v);
}

int query(int left, int right, int x = 1){
    if(num[left].v == num[right].v) return right - left + 1;

    int ans = 0;
    if(left > num[left].l){
        ans = num[left].r - left + 1;
        left = num[left].r + 1;
    }
    if(right < num[right].r){
        ans = max(right - num[right].l + 1, ans);
        right = num[right].l - 1;
    }
    //cout << "left right ans " << left << ' ' << right << ' ' << ans << '\n';
    if(left > right ) return ans;

    if(node[x].l >= left && node[x].r <= right ) return node[x].v;
    int mid = (node[x].l + node[x].r) / 2;
    if(left <= mid) ans = max(ans, query(left, right, Lson(x)));
    if(mid < right) ans = max(ans, query(left, right, Rson(x)));
    return ans;
}

void debug_num(){
    for(int i = 1; i <= n; i++)
        cout << i << ' ' << num[i].l << ' ' << num[i].r << ' ' << num[i].v << ' ' << num[i].f << '\n';
    cout << '\n';
}

void debug_build(){
    for(int i = 1; i <= n; i++)
        cout << i << ' ' << node[i].l << ' ' << node[i].r << ' ' << node[i].v << '\n';
    cout << '\n';
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL

    int s = 1, e;
    while(cin >> n >> q && n + q != 0){
        for(int i = 1; i <= n; i++){
            cin >> ta;
            num[i].v = ta;
            if(num[i].v != num[i-1].v){
                for(int j = s; j < i; j++){
                    num[j].l = s;
                    num[j].r = i-1;
                    num[j].f = i - s;
                }
                s = i;
            }
        }
        for(int j = s; j <= n; j++){
            num[j].l = s;
            num[j].r = n;
            num[j].f = n - s + 1;
        }
        //debug_num();
        build(1, n);
        //debug_build();
        for(int i = 0; i < q; i++){
            cin >> ta >> tb;
            cout << query(ta, tb) << '\n';
        }
    }



    return 0;
}
