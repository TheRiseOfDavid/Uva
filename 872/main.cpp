#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 40
using namespace std;
stringstream ss;
int graph[MAXN], visit[MAXN]; //graph
int order[MAXN][MAXN]; //order
int n, lg, flag2, flag3;
char ch;
vector<int> ans;

void dfs(int x){
    visit[x] = 1;
    ans.push_back(x);

    //for(auto it: ans) cout << (char) (it + 'A') << ' ';
    //cout << '\n';

    if(ans.size() == lg){
        flag2 = 0;
        cout << (char) (ans[0] + 'A');
        for(int i = 1; i < ans.size(); i++) cout << ' ' << (char) (ans[i] + 'A');
        cout << '\n';
        return;
    }

    int flag;
    for(int i = 0; i < MAXN; i++){
        flag = 1;
        if(graph[i] != 1 || visit[i] == 1) continue;
        for(auto it: ans){
            if(order[it][i]){
                flag = 0;
                break;
            }
        }

        if(flag == 1){
            dfs(i);
            visit[i] = 0;
            ans.pop_back();
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> n;
    cin.ignore();
    flag3 = 1;
    while(n--){
        string temp;
        getline(cin, temp); //replace blank line
        getline(cin, temp);
        //cout << "temp is " << temp << '\n';
        ss.clear(); ss.str(""); ss << temp;
        memset(graph, 0, sizeof(graph));
        memset(order, 0, sizeof(order));
        lg = 0;
        while(ss >> ch){
            graph[ch - 'A'] = 1;
            lg++;
        }

        getline(cin, temp);
        ss.clear(); ss.str(""); ss << temp;
        while(ss >> temp) order[temp[2] - 'A'][temp[0] - 'A'] = 1;

        flag2 = 1;
        if(flag3 == 0) cout << "\n";
        if(flag3) flag3 = 0;
        for(int i = 0; i < MAXN; i++){
            if(graph[i] == 1){
                dfs(i);
                ans.pop_back();
                visit[i] = 0;
            }
        }
        if(flag2) cout << "NO\n";


    }

    return 0;
}
