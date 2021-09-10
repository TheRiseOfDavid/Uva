#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 200020
#define int long long
using namespace std;
int t, n, m;
int a, b, c;
int start, destination;
int ca, cb;
int p[MAXN];

struct edge{
    int u, v, c; //u,v ���O���䪺�`�I�A c �O����

    edge(): u(0), v(0), c(0) {}
    edge(int u, int v, int c): u(u), v(v), c(c) {}
    bool operator < (const edge& other) const{
        return c < other.c;
    }
};
vector<edge> node;
vector<edge> MST; //�̤p�ͦ���

int find_root(int x){
    //cout << "find_root " << x << "\n";
    if(p[x] != x) return p[x] = find_root(p[x]);
    return x;
}

void kruskal(){
    node.clear();
    MST.clear();


    for(int i = 0; i < m; i++){
        cin >> a >> b >> c; //��J��B����
        node.push_back({a,b,c});
    }
    sort(node.begin(), node.end()); //�ƧǡA�o��ƧǤ覡�����W

    cin >> ca >> cb;


    cin >> n;
    while(n--){
        int ans = 0;
        cin >> start >> destination;
        for(int i = 0; i < n; i++) p[i] = i; //init disjoint set

        for(edge it: node){
            //cout << it.u << " " << it.v << " " << it.c << "\n";
            //cout << p[3] << " " << p[4] << "\n";
            int pu = find_root(it.u); //�P�_�䪺�`�I�̬O�_���b�P�� set
            int pv = find_root(it.v);
            if(pu != pv) p[pv] = pu;

            if(find_root(start) == find_root(destination)){
                ans =
            }
        }
    }




    for(edge it: MST){
        cout << it.u << " " << it.v << " " << it.c << "\n"; //��X�Ҧ���
    }
}

int32_t main(){
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    cin >> t;
    while(t--){
        kruskal();
    }
}
