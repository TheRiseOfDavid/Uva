#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 30
#define INF 0x3f3f3f
using namespace std;
int n, m, cnt, node, flag;
int area[MAXN];
string temp;
char ca, cb;
vector<int> edge[MAXN];


void init(){
    memset(area,0,sizeof(area));
    for(int i = 0; i < MAXN; i++) edge[i].clear();
}

void wake(vector<int> record){
    vector<int> temp2;
    cnt++;
    for(auto it: record){
        //cout << (char)(it+'A') << ' ';
        for(int i = 0; i < edge[it].size(); i++){
            area[edge[it][i]]++;
            if(area[edge[it][i]] >= 3){
                temp2.push_back(edge[it][i]);
                area[edge[it][i]] = -INF;
            }
        }
    }
    //cout << '\n';
    if(temp2.empty()) return ;
    return wake(temp2);
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> n >> m){
        vector<int> record;
        init();

        cin >> temp;
        for(int i = 0; i < temp.length(); i++){
            area[temp[i] - 'A'] = -INF;
            record.push_back(temp[i] - 'A');
        }
        for(int i = 0; i < m ; i++){
            cin >> ca >> cb;
            edge[ca - 'A'].push_back(cb - 'A');
            edge[cb - 'A'].push_back(ca - 'A');
        }
        cnt = -1; flag = 0;
        wake(record);
        for(int i = 0; i < MAXN; i++){
            if(area[i] < 0) flag++;
            //cout << area[i] << '\n';
        }


        if(flag == n) cout << "WAKE UP IN, " << cnt << ", YEARS\n";
        else cout << "THIS BRAIN NEVER WAKES UP\n";
    }

    return 0;
}
