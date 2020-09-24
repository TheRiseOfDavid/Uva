#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int ax[30][7] = {} ;
int ay[30][7] = {} ;
vector<string> Ans;

void dfs(int j , string strAns){
    if(j == 5){
        Ans.push_back(strAns);
        return ;
    }
    for(int i = 0 ; i < 26 ; i++){
        if(ax[i][j] && ay[i][j])
            dfs(j+1 , strAns+ (char)('A' + i));

    }
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin) ;
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL

    int n , x ;
    string strLine ;
    cin >> n ;
    while(n--){
        Ans.clear();
        cin >> x ;
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < 6 ; j++){
                ax[i][j] = 0;
                ay[i][j] = 0;
            }
        }

        for(int i = 0 ; i < 6 ; i++){
            cin >> strLine;
             for(int j = 0 ; j < strLine.length() ; j++){
                ax[strLine[j] - 'A'][j] = 1 ;
            }
        }
        for(int i = 0 ; i < 6 ; i++){
            cin >> strLine;
             for(int j = 0 ; j < strLine.length() ; j++){
                ay[strLine[j] - 'A'][j] = 1 ;
            }
        }

        dfs(0, "");
        if(Ans.size() < x)
            cout << "NO" << '\n' ;
        else
            cout << Ans[x-1] << '\n' ;
    }

    return 0;
}
