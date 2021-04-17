#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAXN = 10;
int n, m, a, b, c;
int peoples[MAXN];
int position[MAXN];
int cnt = 0;

struct relation{
    int x,y,v;
    relation(){}
    relation(int _x, int _y, int _v){
        x = _x;
        y = _y;
        v = _v;
    }
};
vector<relation > listed;

int islegal(relation concern){
    if(concern.v < 0){
        return abs(peoples[concern.x] - peoples[concern.y]) >= abs(concern.v);
    }
    else if(concern.v >= 0){
        return abs(peoples[concern.x] - peoples[concern.y]) <= concern.v;
    }
}

void dfs(int people){
    //cout << "people " << people << '\n';
    if(people >= n){
        for(int i = 0; i < listed.size(); i++){
            if(!islegal(listed[i])) return;
        }
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(position[i]) continue;
        peoples[people] = i;
        position[i] = 1;
        dfs(people+1);
        position[i] = 0;
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    while(cin >> n >> m && (n+m) != 0){
        listed.clear();
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            relation temp(a,b,c);
            listed.push_back(temp);
        }
        for(int i = 0; i < n; i++){
            position[i] = 0;
            peoples[i] = 0;
        }
        cnt = 0;
        dfs(0);
        cout << cnt << '\n';
    }

    return 0;
}
