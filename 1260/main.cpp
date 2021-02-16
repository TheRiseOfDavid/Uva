#include <iostream>
#include <bits/stdc++.h>
#define MAXN 5020
#define LOCAL
using namespace std;

int a[MAXN];
int T, n, len = 0, cur;


int lis(){
    deque<int> b;
    b.push_back(a[0]);
    int sz = 0, temp;
    for(int i = 1; i < n; i++){
        if(a[i] > b.back()){
            sz += b.size();
            b.push_back(a[i]);
        }
        else{
            temp = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            b.insert(b.begin()+temp , a[i]);
            sz += temp;
            //for(auto it: b) cout << it << ' ';
            //cout << '\n';
        }
        //cout << "sz i is " << sz << '\n';
    }
    return sz;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << lis() << '\n';
    }

    return 0;
}
