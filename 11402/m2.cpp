#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1024200
#define lson(x) x<<1
#define rson(x) (x<<1) + 1
using namespace std;
int num[MAXN];
int t, n, m, q, cnt, a , b, kase=1, qcnt;
string temp;
struct{
    int l, r, v, z1, z2, f;
    void print(){
        cout << "node l r v z1 z2 " << l << ' ' << r << ' ' << v << ' ' << z1 << ' ' << z2 << '\n';
    }
}node[MAXN*4];

void build(int l, int r, int x = 1){
    node[x].l = l;
    node[x].r = r;
    node[x].z1 = -1;
    node[x].z2 = -1;
    if(l == r){
        node[x].v = num[l];
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, lson(x));
    build(mid+1, r, rson(x));
    node[x].v = node[lson(x)].v + node[rson(x)].v;
}

void mod2(int x){
    node[lson(x)].z2 = node[x].z2;
    node[rson(x)].z2 = node[x].z2;
    node[x].f = 0;
    if(node[x].z1 != 0) node[x].f = 0;
    else node[x].f = node[x].z1;

    node[lson(x)].v = (node[lson(x)].r-node[lson(x)].l+1) - node[lson(x)].v;
    node[rson(x)].v = (node[rson(x)].r-node[rson(x)].l+1) - node[rson(x)].v;

    cout << "x.z2 lson.gap " << x << ' ' << (node[lson(x)].r-node[lson(x)].l+1) << '\n';
}

void mod1(int x){
    node[lson(x)].z1 = node[x].z1;
    node[rson(x)].z1 = node[x].z1;
    node[x].z1 = -1;
    if(node[x].z2 != 0) node[x].f = 0;
    else node[x].f = node[x].z2;

    node[lson(x)].v = (node[lson(x)].r-node[lson(x)].l+1) * node[lson(x)].z1;
    node[rson(x)].v = (node[rson(x)].r-node[rson(x)].l+1) * node[rson(x)].z1;

    cout << "x lson.v lson.z1 " << x << ' ' << node[lson(x)].v << ' ' << node[lson(x)].z1 << '\n';
}

void push(int x){
    int i;
    while(node[x].f != 0){
        if(node[x].f == 1) mod1(x);
        else if(node[x].f == 2) mod2(x);
    }
}

void interMod1(int a, int b, int m, int x = 1){
    cout << "x a b " << x << ' ' << a << ' ' << b << ' ' << "interMod1" << "\n";

    if(a <= node[x].l && b >= node[x].r){ //this node interval will be recover
        cout << "in\n";
        node[x].v = (node[x].r-node[x].l+1) * m; //m is 1 or 0
        node[x].z1 = m;
        if(node[x].f == 0) node[x].f = 1;
        return;
    }
    push(x);

    int mid = (node[x].l+node[x].r)/2;
    if(a <= mid) interMod1(a, b, m, lson(x));
    if(b > mid) interMod1(a, b, m, rson(x));
    node[x].v = node[lson(x)].v + node[rson(x)].v;
}

void interMod2(int a, int b, int m, int x = 1){
    cout << "x a b " << x << ' ' << a << ' ' << b << ' ' << "interMod2" << "\n";

    if(a <= node[x].l && b >= node[x].r){ //this node interval will be recover
        cout << "in\n";
        node[x].v = (node[x].r-node[x].l+1) - node[x].v; //m is 1 or 0
        node[x].z2 = m;
        if(node[x].f == 0)node[x].f = 2;
        return;
    }
    push(x);

    int mid = (node[x].l+node[x].r)/2;
    if(a <= mid) interMod2(a, b, m, lson(x));
    if(b > mid) interMod2(a, b, m, rson(x));
    node[x].v = node[lson(x)].v + node[rson(x)].v;
}

int query(int l, int r, int x = 1){


    if(node[x].l >= l && node[x].r <= r) return node[x].v;
    push(x);

    int mid = (node[x].l+node[x].r) / 2, ans = 0;
    if(l <= mid) ans += query(l, r, lson(x));
    if(r > mid) ans += query(l, r, rson(x));
    cout << "query x ans " << x << ' ' << ans << '\n';
    return ans;
}

void debug_num(){
    for(int i = 0; i < cnt; i++) cout << num[i];
    cout << '\n';
}

void debug_node(){
    for(int i = 1; i < 15; i++) node[i].print();
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        qcnt = 1;
        cout << "Case " << kase++ << ":\n";
        cin >> n;
        cnt = 1;
        while(n--){
            cin >> m >> temp;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < temp.length(); j++) num[cnt++] = temp[j] - '0';
            }
        }
        //debug_num();

        build(1, cnt);
        debug_node();
        cout << '\n';

        cin >> q;
        for(int i = 0; i < q; i++){
            cin >> temp >> a >> b;
            a++; b++; //index start from 1
            if(temp == "F") interMod1(a, b, 1);
            else if(temp == "E") interMod1(a, b, 0);
            else if(temp == "I") interMod2(a, b, 1);
            else if(temp == "S") cout << "Q" << qcnt++ << ": " << query(a, b) << "\n";
            debug_node();
            cout << '\n';
        }

    }
    return 0;
}
