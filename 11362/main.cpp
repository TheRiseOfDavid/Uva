#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define alp_MAXN 15
#define arr_MAXN 1000009
using namespace std;
int cnt = 0 , flag = 0 ;
string strA ;

struct node{
    bool isWord = false ;
    int next[alp_MAXN];

    void reset(){
        for(int i = 0 ; i < alp_MAXN ; i++)
            next[i] = -1 ;
        isWord = false ;
    }

}trie[arr_MAXN];

void insrt(){
    int c , cur = 0;
    for(int i = 0 ; i < strA.length() ; i++){
        c = strA[i] - '0' ;
        if(trie[cur].next[c] == -1 ){
            trie[cnt].reset();
            trie[cur].next[c] = cnt ;
            cur = cnt++ ;
        }
        else{
            cur = trie[cur].next[c];
            if(trie[cur].isWord || i == strA.length()-1 ) {flag = 1 ;return ;}
        }
        if(flag) break ;
    }
    trie[cur].isWord = true ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    //freopen("out.txt" , "w" , stdout );
#endif // LOCAL

    int t , n ;
    cin >> t ;

    while(t--){
        cin >> n ;
        cnt = 1 ;
        flag = 0 ;
        trie[0].reset();
        for(int i = 0 ; i < n ; i++){
            cin >> strA ;
            insrt();
        }
        cout << (flag? "NO" : "YES") << '\n' ;

        //debug
//        for(int i = 0 ; i < 20 ; i++){
//            for(int j = 0 ; j < 10 ; j++)
//                cout << trie[i].next[j] << ' ' ;
//            cout << trie[i].isWord ;
//            cout << '\n' ;
//        }
    }

    return 0;
}
