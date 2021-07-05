#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int num[] = {1,2,3,4,5,6,7,8,9,10};
int num_size;

int fib(int i){
    if(i == 1 || i == 0) return i;
    return fib(i-1) + fib(i-2);
}

int fib_search(int val){
    cout << "fib search start.\n";

    int i = 2, cnt=0;
    num_size--;
    while(num_size > fib(i)) i++;

    i--;
    int root = fib(i);
    int diff1 = fib(i-1);
    int diff2 = fib(i-2);
    root--;

    //    ^ ^
    //1 1 3 5 8 13
    while(1){
        cout << "root " << root << '\n';
        cout << ++cnt << " search. find " << num[root] << '\n';

        if(val == num[root]) return root;
        if(val < num[root]){
            root -= diff2;
            int temp = diff1;
            diff1 = diff2;
            diff2 = temp - diff2;
            i--;
        }
        if(val > num[root]){
            root += diff2;
            diff1 = diff1 - diff2;
            diff2 = diff2 - diff1;
            i -= 2;
        }
    }
    cout << "cat't find " << val << "\n";
    return -1;
}

int main()
{
    num_size = sizeof(num) / sizeof(num[0]);
    int val = 4;
    cout << val << " position is " << fib_search(val) << '\n';
    return 0;
}
