#include <bits/stdc++.h>
#define LOCAL
#define MAXN 1024200
#define Lson(x) x<<1
#define Rson(x) (x<<1)+1
using namespace std;
int t, n, m, a, b, Qcnt, q, kase, len;
int num[MAXN];
struct tree{
    int l, r, v, z;
    void print(){
        cout << "l = " << l << " r = " << r << " v = " << v << " z = " << z << '\n';
    }
}node[MAXN*4];

void build(int l, int r, int x = 1){

    //cout << "x = " << x << " l = " << l << " r = " << r << '\n';
    node[x].l = l;
    node[x].r = r;
    node[x].z = -1;
    if(l == r){
        node[x].v = num[l];
        return;
    }

    int mid = (l+r)/2;
    build(l, mid, Lson(x));
    build(mid+1, r, Rson(x));
    node[x].v = node[Lson(x)].v + node[Rson(x)].v;
}

void mod1(int x, int cmd){
    int lson = Lson(x), rson = Rson(x);
    node[lson].z = cmd;
    node[rson].z = cmd;

    node[lson].v = (node[lson].r-node[lson].l+1) * cmd;
    node[rson].v = (node[rson].r-node[rson].l+1) * cmd;
}

void mod2(int x, int cmd){
    int lson = Lson(x), rson = Rson(x);

    if(node[lson].z == 2) node[lson].z = -1;
    else if(node[lson].z != -1) node[lson].z ^= 1;
    else node[lson].z = cmd;

    if(node[rson].z == 2) node[rson].z = -1;
    else if(node[rson].z != -1) node[rson].z ^= 1;
    else node[rson].z = cmd;

    node[lson].v = (node[lson].r-node[lson].l+1) - node[lson].v;
    node[rson].v = (node[rson].r-node[rson].l+1) - node[rson].v;
}

void push_down(int x){
    if(node[x].z == 0) mod1(x, 0);
    if(node[x].z == 1) mod1(x, 1);
    if(node[x].z == 2) mod2(x, 2);
    node[x].z = -1;
}

void push_mod1(int a, int b, int cmd, int x = 1){
    if(a <= node[x].l && b >= node[x].r){
        node[x].v = (node[x].r-node[x].l+1) * cmd;
        node[x].z = cmd;
        return;
    }
    push_down(x);

    int mid = (node[x].l+node[x].r) / 2;
    if(a <= mid) push_mod1(a, b, cmd, Lson(x));
    if(b > mid) push_mod1(a, b, cmd, Rson(x));
    node[x].v = node[Lson(x)].v + node[Rson(x)].v;
}

void push_mod2(int a, int b, int cmd, int x = 1){
    if(a <= node[x].l && b >= node[x].r){
        node[x].v = (node[x].r-node[x].l+1) - node[x].v;

        if(node[x].z == 2) node[x].z = -1;
        else if (node[x].z != -1) node[x].z ^= 1;
        else node[x].z = cmd;

        return;
    }
    push_down(x);

    int mid = (node[x].l+node[x].r) / 2;
    if(a <= mid) push_mod2(a, b, cmd, Lson(x));
    if(b > mid) push_mod2(a, b, cmd, Rson(x));
    node[x].v = node[Lson(x)].v + node[Rson(x)].v;
}

int query(int l, int r, int x = 1){
    if(node[x].l >= l && node[x].r <= r) return node[x].v;
    push_down(x);

    int mid = (node[x].l+node[x].r) / 2, ans = 0;
    if(l <= mid) ans += query(l, r, Lson(x));
    if(r > mid) ans += query(l, r, Rson(x));
    //cout << "q x = " << x << " ans = " << ans << '\n';
    return ans;
}


int main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    string temp;
    cin >> t;
    while(t--){
        Qcnt = 1;
        cout << "Case " << ++kase << ":\n";
        cin >> n;
        len = 1;
        while(n--){
            cin >> m >> temp;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < temp.length(); j++) num[len++] = temp[j] - '0';
            }
        }

        build(1, len);
        cin >> q;
        for(int i = 0; i < q; i++){
            cin >> temp >> a >> b;
            a++; b++; //index start from 1
            if(temp == "F") push_mod1(a, b, 1);
            else if(temp == "E") push_mod1(a, b, 0);
            else if(temp == "I") push_mod2(a, b, 2);
            else if(temp == "S") cout << "Q" << Qcnt++ << ": " << query(a, b) << "\n";

        }
    }
    return 0;
}

