#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <set>
#include <algorithm> 
using namespace std;
#define MAXN 512
int V[MAXN][MAXN], R[MAXN][MAXN], C[MAXN][MAXN]; 
// V 是成本、R 是可移動的 y 軸、C 是可移動的 x 軸 
int TX, TY;  
struct Node { //dijkstra 用到的節點
    int r, c, v, h; // r=x , c=y , h 等於漢明距離 , v 是成本
    Node(int a=0, int b=0, int d=0, int e=0): //輸入值可以有這種寫法
    r(a), c(b), v(d), h(e) {} 
    bool operator<(const Node &x) const { //看大衛的筆記 , UVa 10181 
        if (v != x.v)
            return v > x.v; //最小
        return h > x.h;
    }
};
priority_queue<Node> pQ; // dijkstra
struct RangeTree { // 2D binary indexed tree，狀態樹 注意，這裡是二維
    int A[MAXN][MAXN]; // 走過的點 1 為還沒走過
    int R, C;
    void init(int R, int C) {
        this->R = R, this->C = C;
        memset(A, 0, sizeof(A));
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                modify(i, j, 1);
    }
    
    void modify(int x, int y, int val) { //修改遞增值
        for (; x <= R; x += x&(-x)) {
            for (int i = y; i <= C; i += i&(-i)) 
                A[x][i] += val;
        }
    }
    int query(int x, int y) {
        int ret = 0;
        for (; x > 0; x -= x&-x)
            for (int i = y; i > 0; i -= i&(-i))
                ret += A[x][i];
        return ret;
    }
    int rectSum(int lx, int rx, int ly, int ry) { //查詢資料
        return query(rx, ry) - query(lx-1, ry) - query(rx, ly-1) + query(lx-1, ly-1);
    }
    void update(int lx, int rx, int ly, int ry, int val, int tot) { // {val: update cost, tot: #unvisited point in area.} //更新最短路徑
        //lx 最大的 x ，rx 最小的 rx
        if (tot == -1) 	
            tot = rectSum(lx, rx, ly, ry); //找區域內有多少節點
        if (tot == 0) 	return; //已經沒有節點可以走了
        if (lx == rx) { //進行二分，但因為有 x,y 兩個方向，我們先從 x 開始進行查詢
            if (ly == ry) { 
                pQ.push(Node(lx, ly, val + V[lx][ly], abs(lx-TX) + abs(ly-TY))); //
                modify(lx, ly, -1);
                return;
            }
            int cnt = rectSum(lx, rx, ly, (ly + ry)/2); //對 y 二分
            if (cnt) //會找到中間一半的值
                update(lx, rx, ly, (ly + ry)/2, val, cnt);
            if (cnt < tot) //如果 tot > cnt 表示 cnt 把所有的點都覆蓋住了
                update(lx, rx, (ly + ry)/2 + 1, ry, val, tot - cnt);
        }
        else {
            int cnt = rectSum(lx, (lx + rx)/2, ly, ry);
            if (cnt) 
                update(lx, (lx + rx)/2, ly, ry, val, cnt);
            if (cnt < tot)
                update((lx + rx)/2 + 1, rx, ly, ry, val, tot - cnt);
        }
    }
} rangeTree;
int findPath(int n, int m, int sx, int sy, int ex, int ey) {
    if (sx == ex && sy == ey)	return 0;
    TX = ex, TY = ey;
    rangeTree.init(n, m);
    rangeTree.modify(sx, sy, -1);
        
    while (!pQ.empty())	pQ.pop();
    pQ.push(Node(sx, sy, V[sx][sy], abs(sx-ex) + abs(sy-ey)));
    
    Node u;
    int lr, rr, lc, rc;
    while (!pQ.empty()) {
        u = pQ.top(), pQ.pop();
        
        if (abs(u.r - ex) <= R[u.r][u.c] && abs(u.c - ey) <= C[u.r][u.c]) 
        //已經可以到達，因為在馬車可以到行走範圍內
            return u.v;
            
        lr = max(1, u.r - R[u.r][u.c]), rr = min(n, u.r + R[u.r][u.c]); //邊界，可以到達的地方
        lc = max(1, u.c - C[u.r][u.c]), rc = min(m, u.c + C[u.r][u.c]); //邊界，可以到達的地方
        rangeTree.update(lr, rr, lc, rc, u.v, -1);
    }
    return -1;
}
int main() {
//	freopen("in.txt", "r+t", stdin);
//	freopen("out.txt", "w+t", stdout);
    int n, m, q, X[16], Y[16];
    while (scanf("%d %d %d", &n, &m, &q) == 3) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &V[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &R[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &C[i][j]);
        for (int i = 0; i < q; i++)
            scanf("%d %d", &X[i], &Y[i]);
            
        for (int i = 1; i < q; i++) {
            int r = findPath(n, m, X[i-1], Y[i-1], X[i], Y[i]);
            printf("%d%c", r, ' ');
            //printf("%d%c", r, i == q - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
/*
 3 4 5
 1 2 1 1
 1 5 3 4
 1 1 6 3
 1 2 3 3
 3 3 1 2
 0 0 0 1
 1 4 0 1
 2 3 0 1
 4 1 3 1
 1 1
 3 4
 1 1
 2 2
 2 2
 */