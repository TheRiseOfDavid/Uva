#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 30
using namespace std;
int tree[MAXN], cT[MAXN], cA[MAXN]; //cntTree cntAcorn
int t;
string temp;
vector<int> record;

void init(){
    for(int i = 0; i < MAXN; i++){
        tree[i] = i;
        cA[i] = 1;
    }
    memset(cT, 0, sizeof(cT));
    record.clear();
}

int find_root(int i){
    if(tree[i] != i)
        return tree[i] = find_root(tree[i]);
    return tree[i];
}

void debug(){
    for(int i = 0 ; i < MAXN; i++)
        cout << i << ' ';
    cout << '\n';
    for(int i = 0 ; i < MAXN; i++)
        cout << tree[i] << ' ';
    cout << '\n';
    for(int i = 0 ; i < MAXN; i++)
        cout << cA[i] << ' ';
    cout << '\n';
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while(t--){
        init();
        while(cin >> temp){
            if(temp[0] == '('){
                int x, y, rx, ry; //rootx rooty
                x = temp[1] - 'A' + 1;
                y = temp[3] - 'A' + 1;
                rx = find_root(tree[x]);
                ry = find_root(tree[y]);
                if(rx != ry)
                    tree[ry] = rx;
            }
            if(temp[0] == '*'){
                cin >> temp;
                int root, x;
                for(int i = 0; i < temp.length(); i+=2){
                    x = temp[i] - 'A' + 1;
                    record.push_back(x);
                    root = find_root(tree[x]);
                    //cout << root << ' ' << x << "\n";
                    if(root != x){
                        cA[x] = 0;
                        cA[root] = 0;
                        cT[root] = 1;
                    }
                }
                break;
            }
        }
        //debug();
        int sum_cT = 0, sum_cA = 0;
        for(int i = 0; i < record.size(); i++){
            if(cT[record[i]]) sum_cT++;
            if(cA[record[i]]) sum_cA++;
        }
        cout << "There are " << sum_cT << " tree(s) and " << sum_cA << " acorn(s).\n";
    }

    return 0;
}
