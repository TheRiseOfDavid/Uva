#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 10
using namespace std;
int ans;
string s;
map<char, int> roman;
deque<int> num;

void roman_system(int a){
    if(num.empty()) num.push_back(a);
    else if(num.back() == a) num.push_back(a);
    else if(num.back() > a){
        while(!num.empty()){
            ans += num.front();
            num.pop_front();
        }
        num.push_back(a);
    }
    else if(num.back() < a){
        while(!num.empty()){
            ans -= num.front();
            num.pop_front();
        }
        num.push_back(a);
    }
    IICM = 1000-100-2 = 898
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif // LOCAL
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    while(cin >> s){
        ans = 0;
        char pre_char = '!';
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            cnt = pre_char == s[i] ? cnt+1 : 0;
            pre_char = s[i];

            if(cnt < 4 && roman.count(s[i])) roman_system(roman[s[i]]);
            else{
                ans = 0;
                num.clear();
                break;
            }
        }
        while(!num.empty()){
            ans += num.front();
            num.pop_front();
        }
        cout << ans << "\n";
    }
    return 0;
}
