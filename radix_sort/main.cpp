#include <iostream>
#include <bits/stdc++.h>
#define N 20
using namespace std;
int num[10] = {24,6239 ,249 , 465935 , 4353 ,543 , 9352 ,2154 , 953 , 3952} ;
int cnt[N] = {} ;
int id[N] , old_id[N] ;

int main()
{
    queue<int> buckets[10] ;
    int k = 465935 ,j = 1 ;
    while(k/j){
        for(int i = 0 ; i < 10 ; i++)
            buckets[(num[i] /j)%10].push(num[i]);
        int p = 0 ;
        for(int i = 0 ; i < 10 ; i++){
            while(!buckets[i].empty()){
                num[p++] =buckets[i].front();
                buckets[i].pop();
            }
        }
        j *= 10;
        for(int i = 0 ; i < 10 ;i++)
            cout << i << ' ' << num[i] << '\n' ;
        cout << '\n' ;
    }


    return 0;
}
