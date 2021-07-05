#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAXN = 1020;
int n, dp[MAXN];

struct record{
    string time, phone, mark;
    int year;
    record(string _time, string _phone, string _mark, int _year){
        time = _time;
        phone = _phone;
        mark = _mark;
        year = _year;
    };
    record(): time(""), phone(""), mark(""), year(0){}

};
deque<record> info;

void debug(){
    for(int i = 0; i < n; i++){
        cout << info[i].time << ' ' << info[i].phone << ' ' << info[i].mark << ' ' << info[i].year << '\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // LOCAL

    while(cin >> n && n){
        string time, phone, mark;
        info.clear();
        for(int i = 0; i < n; i++){
            cin >> time >> phone >> mark;
            info.push_back( record(time, phone, mark, 0));
        }

        int year = 0;
        for(int i = 1; i < n; i++){
            if(info[i].time <= info[i-1].time) info[i].year = ++year;
            else info[i].year = year;
        }

        //debug();
        int first_mark = n, flag = 1, last_mark;
        for(int i = n-1; i >= 0; i--){
            if(info[i].mark == "+") first_mark = i;

            dp[i] = flag && info[i].year == year ? 1 : n-i;
            if(flag && (info[i].mark == "+" || info[i].year != year)){
                flag = 0;
                last_mark = i;
            }

        }

        for(int i = last_mark; i >= first_mark; i--){
            for(int j = i+1; j < n; j++){
                if(info[i].year == info[j].year || \
                   (info[i].year + 1 == info[j].year && info[i].time >= info[j].time))
                    dp[i] = min(dp[i], dp[j]+1);
                else break;

                if(info[j].mark == "+") break;
            }
        }

        //for(int i = 0; i < n; i++) cout << dp[i] << ' ';
        //cout << '\n';
        cout << dp[first_mark] << '\n';
    }


    return 0;
}
