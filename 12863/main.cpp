#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 512
#define lowbit(x) x&(-x)
using namespace std;
int V[MAXN][MAXN], R[MAXN][MAXN], C[MAXN][MAXN], P[MAXN][2] ;
int TX , TY ;

struct Node{
    int r, c, v, h;
    Node(int _r=0,int _c=0, int _v=0, int _h=0):
        r(_r), c(_c), h(_h), v(_v) {}
    bool operator<(const Node &a) const{
        if(v != a.v)
            return a.v < v ;
        return a.h < h ;
    }
};

priority_queue<Node> q ;
struct BIT{
    int A[MAXN][MAXN] ;
    int R , C ;
    void init(int _R, int _C){
        R = _R ;
        C = _C ;
        memset(A,0,sizeof(A));
        for(int i = 1 ; i <= R ; i++){
            for(int j = 1 ; j <= C ; j++)
                modify(i, j, 1);
        }
    }
    void modify(int x, int y, int val){
        for(; x <= R ; x += lowbit(x)){
            for(int i = y ; i <= C ; i += lowbit(i))
                A[x][i] += val;
        }
    }
    int query(int x, int y){
        int cnt=0 ;
        for(; x > 0 ; x -= lowbit(x)){
            for(int i = y ; i>0 ; i -= lowbit(i))
                cnt += A[x][i] ;
        }
        return cnt ;
    }
    int rectCnt(int lx, int ly, int rx, int ry){
        return query(rx,ry) - query(lx-1,ry) - query(rx, ly-1) + query(lx-1, ly-1);
    }
    void update(int lx, int ly, int rx, int ry, int val, int tot){
        if(tot == -1)
            tot = rectCnt(lx,ly,rx,ry);
        if(tot == 0) return ;
        if(lx == rx){
            if(ly == ry){
                q.push(Node(lx, ly, val+V[lx][ly], abs(lx-TX)+abs(ly-TY)));
                modify(lx, ly, -1);
                cout << lx << ' ' << rx << '\n';
                return ;
            }
            int cnt = rectCnt(lx, ly, rx, (ly+ry)/2);
            if(cnt)
                update(lx, ly, rx, (ly+ry)/2, val, cnt);
            if(cnt < tot)
                update(lx, (ly+ry)/2 + 1, rx, ry, val, tot - cnt);
        }
        else{
            int cnt = rectCnt(lx, ly, (lx+rx)/2, ry);
            if(cnt)
                update(lx, ly, (lx+rx)/2, ry, val, cnt);
            if(cnt < tot)
                update((lx+rx)/2 + 1, ly, rx, ry, val, tot - cnt);
        }
    }
}bit;

int findPath(int n, int m, int sx, int sy, int ex, int ey){
    if(sx == ex && sy == ey ) return 0 ;
    TX = ex ; TY = ey ;
    bit.init(n, m);
    bit.modify(sx, sy, -1);
    //clear
    while(!q.empty()) q.pop();
    q.push(Node(sx, sy, V[sx][sy], abs(sx-TX)+abs(sy-TY)));

    Node u;
    int lr, rr, lc, rc;
    while(!q.empty()){
        u = q.top(); q.pop();
        if(abs(u.r - ex) <= R[u.r][u.c] && abs(u.c - ey) <= C[u.r][u.c])
            return u.v;

        lr = max(1, u.r-R[u.r][u.c]); rr = min(n, u.r+R[u.r][u.c]);
        lc = max(1, u.c-C[u.r][u.c]); rc = min(m, u.c+C[u.r][u.c]);
        bit.update(lr, lc, rr, rc, u.v, -1);
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int r, c, n;

    while(cin >> r >> c >> n){
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c ;j++)
                cin >> V[i][j] ;
        }
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c ;j++)
                cin >> R[i][j] ;
        }
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c ;j++)
                cin >> C[i][j] ;
        }
        for(int i=0; i<n; i++)
            cin >> P[i][0] >> P[i][1];
        for(int i=1; i<n; i++){
            cout << findPath(r, c, P[i-1][0], P[i-1][1], P[i][0], P[i][1]) ;
            if(i==n-1)
                cout << '\n';
            else
                cout << ' ';
        }
    }


    return 0;
}
