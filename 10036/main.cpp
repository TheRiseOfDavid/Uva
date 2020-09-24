#include <iostream>
#include <bits/stdc++.h>
#define LOCAL

using namespace std;
int intMap[10010][110] = {0} ;


int non_negative(int intNum , int K , int J){
    //debug
    //cout << intNum << ' ' ;

    intNum = (intNum + J ) % K ;
    while(intNum < 0)
        intNum += K ;
    return intNum % K ;
}


void print_map(int *intMap , int N , int K){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < K ; j++)
            cout << *(intMap + i + j) << ' ' ;
        cout << '\n' ;
    }
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int intCase , N , K ;
    cin >> intCase ;
    while(intCase--){
        cin >> N >> K ;

        //debug
        //cout << N << K ;

        int intNum[N] ;

        /**< debug
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < K ; j++)
                cout << intMap[i][j] << ' ' ;
            cout << '\n' ;
        }
        */

        //debug
        //print_map((int *)intMap , N , K ) ;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < K ; j++)
                intMap[i][j] = 0 ;
        }

        for(int i = 0 ; i < N ; i++)
            cin >> intNum[i] ;

        /**<//debug
        for(int i = 0 ; i < N ; i++)
            cout << intNum[i] << ' ' ;
        cout << '\n' ;
        */

        intMap[0][non_negative(intNum[0], K , 0 )] = 1 ;
        for(int i = 1 ; i < N ; i++){
            for(int j = 0 ; j < K ; j++){
                if(intMap[i-1][j]){
                    intMap[i][ non_negative(intNum[i], K , j ) ] = 1 ;
                    intMap[i][ non_negative(-intNum[i], K , j ) ] = 1 ;
                }
            }
        }

        //debug
        //print_map((int *)intMap , N , K ) ;
        //cout << intMap[N-1][0] << '\n' ;

        if(intMap[N-1][0])
            cout << "Divisible" << '\n' ;
        else
            cout << "Not divisible" << '\n' ;

    }
    return 0;
}
