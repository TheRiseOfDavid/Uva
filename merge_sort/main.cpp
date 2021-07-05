#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
int num[] = {4,96,1546,13,48,34,77,48,31};
int out[MAXN];
int num_size;


void output(){
    for(int i = 0 ; i < num_size ; i++)
        cout << num[i] << ' ' ;
    cout << '\n' ;
}

void merge_sort(int L, int R){
    if(L >= R) return ;
    int l=L, r=R,m=(L+R)/2;
    int start_l = l, end_l = m;
    int start_r = m+1, end_r = R;

    merge_sort(start_l, end_l);
    merge_sort(start_r, end_r);

    int index = l;
    while(start_l <= end_l && start_r <= end_r)
        out[index++] = num[start_l] < num[start_r] ? num[start_l++] : num[start_r++];
    while(start_l <= end_l) out[index++] = num[start_l++];
    while(start_r <= end_r) out[index++] = num[start_r++];

    for(int i = L; i <= R; i++) num[i] = out[i];
}

int main()
{
    num_size = sizeof(num) / sizeof(num[0]);

    merge_sort(0, num_size-1);
    output();

    return 0;
}
