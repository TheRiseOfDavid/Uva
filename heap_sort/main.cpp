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

void heapify(int n, int i){
    int largest = i; //root
    int L = 2 * i; //subtree
    int R = 2 * i + 1; //subtree

    if(L < n && num[L] > num[largest]) largest = L;
    if(R < n && num[R] > num[largest]) largest = R;

    if(largest != i){
        swap(num[largest], num[i]);
        heapify(n, largest);
    }
}

void heap_sort(){
    for(int i = num_size/2; i >= 0; i--) heapify(num_size, i);

    for(int i = num_size-1; i >= 0; i--){
        swap(num[0], num[i]);
        heapify(i, 0);
    }
}

int main()
{
    num_size = sizeof(num) / sizeof(num[0]);
    heap_sort();
    output();
    return 0;
}
