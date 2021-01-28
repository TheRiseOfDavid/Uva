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
    int temp = 0 ;
    for(int k = 0 ; k < 6000; k++){
        for(int i = 0; i < 500; i++){
            for(int j = 0; j < 500; j++){
                temp++;
            }
        }
    }

    cout << temp;
}

