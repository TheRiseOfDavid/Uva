#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int num[] = {4,96,1546,13,48,34,77,48,31};
int num_size;


void output(){
    for(int i = 0 ; i < num_size ; i++)
        cout << num[i] << ' ' ;
    cout << '\n' ;
}


void quick_sort(int L , int R  ){
    if(L > R) return ;
    int standard = num[L] , l = L , r = R+1 ;
    while(1){
        while(standard > num[++l] && R > l  ) ;
        while(standard < num[--r] && L < r ) ;
        if(l >= r )
            break ;
        swap(num[l] , num[r]);
        //output();
    }
    swap(num[L] , num[r]);
    //output();
    quick_sort( L , r-1 );
    quick_sort( r+1 , R);
}


int main()
{
    num_size = sizeof(num) / sizeof(num[0]);

    quick_sort(0, num_size-1);
    output();

    return 0;
}
