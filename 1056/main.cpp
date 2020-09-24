#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define INF 99999999
using namespace std;
map<string , int> mapMember ;
int intPath[55][55] ;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int P , R , intCase = 1 , intHash ;
    string strNameA , strNameB ;
    while(cin >> P >> R){
        if(!(P + R))
            break ;
        mapMember.clear() ;
        for(int i = 1 ; i <= P ; i++){
            for(int j = 1 ; j <= P ; j++)
                intPath[i][j] = INF ;
        }
        intHash = 1 ;
        for(int i = 0 ; i < R ; i++){
            cin >> strNameA >> strNameB ;
            if(!mapMember[strNameA])
                mapMember[strNameA] = intHash++ ;
            if(!mapMember[strNameB])
                mapMember[strNameB] = intHash++ ;
            intPath[ mapMember[strNameA] ][ mapMember[strNameB] ] = 1 ;
            intPath[ mapMember[strNameA] ][ mapMember[strNameA] ] = 0 ;
            intPath[ mapMember[strNameB] ][ mapMember[strNameA] ] = 1 ;
            intPath[ mapMember[strNameB] ][ mapMember[strNameB] ] = 0 ;
        }

        //floyd
        int intMax = 0 ;
        for(int i = 1 ; i <= P ; i++){
            for(int j  = 1 ; j <= P ; j++){
                for(int k = 1 ; k <= P ; k++){
                    if(intPath[j][k] > intPath[j][i] + intPath[i][k]){
                        intPath[j][k] = intPath[j][i] + intPath[i][k] ;

                    }
                }
            }
        }
        for(int i = 1 ; i <= P ; i++){
            for(int j = 1 ; j <= P ; j++){
                intMax = max(intPath[i][j] , intMax);
            }
        }
        if(intMax == INF)
            cout << "Network " << intCase++ << ": " << "DISCONNECTED" << '\n' ;
        else
            cout << "Network " << intCase++ << ": " << intMax << '\n' ;
        cout << '\n' ;
    }
    return 0;
}
