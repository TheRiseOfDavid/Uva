#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;

struct st{
    int a ;
    bool operator < (st r)const {
        return a > r.a ;
    }
};

int32_t main(){
    /*
    st b , w ;
    b.a = 2 ;
    w.a = 3 ;
    cout << (b < w) << '\n' ;
    */
    ///*
    priority_queue<st> q ;
    q.push({2});
    q.push({3});
    while(!q.empty()){
        st c ;
        c = q.top() ; q.pop() ;
        cout << c.a << '\n' ;
    }
    //*/
}

