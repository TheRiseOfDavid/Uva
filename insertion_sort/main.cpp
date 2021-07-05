#include <iostream>

using namespace std;
int num[] = {4,96,1546,13,48,34,77,48,31};
int num_size;

void insert_sort(){
    num_size = sizeof(num) / sizeof(num[0]);
    for(int i = 0; i < num_size; i++){
        for(int j = i+1; j < num_size; j++){
            if(num[i] < num[j]) swap(num[i], num[j]);
        }
    }
}

void output(){
    for(int i = 0; i < num_size; i++) cout << num[i] << ' ';
    cout << '\n';
}

int main()
{
    insert_sort();
    output();
    return 0;
}
