#include <iostream>
#include <cstring>
#include <cstdio>
#define LOCAL

using namespace std;

char arrGraph[52][52] = {} ;


//debug
void print_map(int n , int m ){
    //debug print map
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++){
            cout << arrGraph[i][j] ;
        }
        cout << '\n' ;
    }
}


int intact_letter(string strLine , int intLine_Index , int intDirection , int n , int m){
    if(strLine.length()-1 == intLine_Index ){
        //debug
        //cout << strLine << intLine_Index << '\n' ;

        return 1;
    }

    if ( intDirection == 1  && arrGraph[n-1][m-1] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 1 , n-1,m-1);

    if ( intDirection == 2  && arrGraph[n-1][m] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 2 , n-1,m);

    if ( intDirection == 3  && arrGraph[n-1][m+1] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 3 , n-1,m+1);

    if ( intDirection == 4 && arrGraph[n][m-1] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 4 , n,m-1);

    if ( intDirection == 5  && arrGraph[n+1][m-1] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 5 , n+1,m-1);

    if ( intDirection == 6  && arrGraph[n+1][m] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 6 , n+1,m);

    if ( intDirection == 7  && arrGraph[n+1][m+1] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 7 , n+1,m+1);

    if ( intDirection == 8  && arrGraph[n][m+1] == strLine[intLine_Index +1 ])
        return intact_letter(strLine , intLine_Index +1 , 8 , n,m+1);

    return 0;
}


void search_letter( string strLine , int n , int m ){
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++){
            if(arrGraph[i][j] == strLine[0] ){
                for (int k = 0 ; k < 9 ; k++){
                    if(intact_letter(strLine , 0 , k , i , j)){
                        cout << i << ' ' << j << '\n' ;
                        return ;
                    }
                }
            }
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt","r" , stdin);
#endif // LOCAL
    int indicating , n , m , k , isInit= 0 ;
    cin >> indicating ;
    string strLine ;
    while(indicating--){
        if(isInit)
            cout << '\n' ;
        isInit = 1 ;
        cin >> n >> m ;
        for(int i = 1 ; i <= n ; i++){
            cin >> strLine ;
            for(int j = 1 ; j <= m ; j++){
                arrGraph[i][j] = tolower(strLine[j-1]) ;
            }
        }

        //debug
        //print_map(n,m);

        cin >> k ;
        for (int i = 0 ; i < k ; i++){
            cin >> strLine ;
            for(int i = 0 ; i < k ; i++)
                strLine[i] = tolower(strLine[i]);
            search_letter(strLine , n , m);
        }
    }
    return 0;
}
