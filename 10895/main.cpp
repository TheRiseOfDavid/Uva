#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 10020
using namespace std;
int num[MAXN][MAXN], row[MAXN];
int n, m, r;

void input_row(int i){
    cin >> r;
    for(int j = 1; j <= r; j++)
        cin >> row[j];
    for(int j = 1; j <= r; j++)
        cin >> num[row[j]][i];
}

void output(){
    cout << m << ' ' << n << '\n';
    vector<int> record;
    for(int i = 1; i <= m; i++){
        record.clear();
        for(int j = 1; j <= n; j++){
            if(num[i][j]) record.push_back(j);
        }
        cout << record.size();
        for(auto it: record) cout << ' ' << it;
        cout << '\n';

        if(record.size() > 0){
            for(int j = 0; j < record.size()-1; j++) cout << num[i][record[j]] << ' ';
            cout << num[i][record[record.size()-1]] ;
        }
        cout << '\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    while(cin >> n >> m){
        memset(num, 0, sizeof(num));
        memset(row, 0, sizeof(row));
        for(int i = 1; i <= n; i++) input_row(i);
        output();
    }
    return 0;
}
