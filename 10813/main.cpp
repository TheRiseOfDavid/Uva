#include <iostream>
#include <bits/stdc++.h>
#define LOCAL


using namespace std;
intMap[5][5] = {} ;


int main()
{
    int isCase ;
    cin >> isCase ;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++)
            cin >> intMap[i][j] ;
    }
    for(int i = 2 ; i < 5 ; i++)
        swap(intMap[i][j] , intMap[i][j+1]);


    return 0;
}
