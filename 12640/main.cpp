#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
//#define DEBUG
#define int long long
#define MAXN 100020
using namespace std;
int n, temp;
vector<int> num;
string q;
// istringstream insert ostringstream output
//https://stackoverflow.com/questions/3292107/whats-the-difference-between-istringstream-ostringstream-and-stringstream-w
stringstream ss;

int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    while(getline(cin, q)){
        ss.clear(); ss.str("");
        ss << q;
        num.clear();

        int sum=0, max_sum=0;
        while(1){
            ss >> temp;
            if(ss.fail()) break;
            num.push_back(temp);

            sum += temp;
            if(sum < 0) sum = 0;
            max_sum = max(sum, max_sum);
        }
        cout << max_sum << '\n';

        #ifdef DEBUG
        //cout << num.size() << '\n';
        for(int i = 0; i < num.size(); i++) cout << num[i] << ' ';
            cout << '\n';
        #endif // DEBUG

    }

    return 0;
}
