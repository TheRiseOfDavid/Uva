#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int num[] = {1,2,3,4,5,6,7,8,9,10};
int num_size;

int interpolation_search(int val){
    int L = 0;
    int R = num_size-1;
    int cnt = 0;
    cout << "interpolation search start.\n";

    while(R >= L){
        int mid = L + (val-num[L]) * (R-L) / (num[R]-num[L]);
        cout << ++cnt << " search. find " << num[mid] << '\n';
        if(num[mid] == val) return mid;
        if(num[mid] > val) L = mid+1;
        if(num[mid] < val) R = mid;

    }
    cout << "cat't find " << val << "\n";
    return -1;

}

int main()
{
    num_size = sizeof(num) / sizeof(num[0]);
    int val = 4;
    cout << val << " position is " << interpolation_search(val) << '\n';
    return 0;
}
