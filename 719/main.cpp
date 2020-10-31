#include <iostream>
#include <bits/stdc++.h>
#define LOCAl
#define N 10010
#define SAMN N*10
using namespace std;
int sz , last ;
struct state{
    int len , link ;
    map<char,int> next ;
}st[SAMN];

void sam_init(){
    sz = 0 ;
    st[0].len = 0 ;
    st[0].link = -1 ;
    st[0].next.clear();
    sz++ ;
    last = 0 ;
}

void sam_extend(char c ){
    int cur = sz++ ;
    st[cur].next.clear() ;
    st[cur].len = st[last].len+1 ;
    int p = last ;
    while(p != -1 && !st[p].next.count(c)){
        st[p].next[c] = cur ;
        p = st[p].link ;
    }
    if(p == -1){
        st[cur].link = 0 ;
    }
    else{
        int q = st[p].next[c] ;
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q ;
        }
        else{
            int clone = sz++ ;
            st[clone].len = st[p].len + 1 ;
            st[clone].next = st[q].next ;
            st[clone].link = st[q].link ;
            while(p != -1 && st[p].next[c] == q){
                st[p].next[c] = clone ;
                p = st[p].link ;
            }
            st[q].link = st[cur].link = clone ;

        }
    }
    last = cur ;
}


int main()
{
#ifdef LOCAl
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAl
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , len;
    string strA ;
    cin >> n ;
    while(n--){
        cin >> strA ;
        len = strA.length() ;
        strA += strA ;
        sam_init() ;
        for(int i = 0 ; i < strA.length() ; i++) sam_extend(strA[i]);

        int u = 0 , now = len  ;
        while(now--){
            for(auto it : st[u].next){
                u = it.second ;
                break ;
            }
        }
        cout << st[u].len - len + 1 << '\n' ;
    }
    return 0;
}
