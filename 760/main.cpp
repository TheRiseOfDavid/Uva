#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define N 2000
using namespace std;
string strA="" , strB="" , strC="" ;
int sa[N] , rk[N<<1] , oldrk[N<<1] , id[N] , cnt[N] ;
int n , m , maxn , lenA , lenB , flag =0 ;

void build_sa(){
    int i , m , p , w ;
    n = strA.length()-1 ;
    m = max(n , 300 );
    memset(cnt,0,sizeof(cnt));
    memset(rk,0,sizeof(rk));
    for(i = 1 ; i <= n ; i++) ++cnt[rk[i] = (int)strA[i]] ;
    for(i = 1 ; i <= m ; i++) cnt[i] += cnt[i-1] ;
    for(i = n ; i >= 1 ; i--) sa[cnt[rk[i]]--] = i ;

    for(w = 1 ; w < n ; w <<= 1){
        memset(cnt,0,sizeof(cnt));
        for(i = 1 ; i <= n ; i++) id[i] = sa[i] ;
        for(i = 1 ; i <= n ; i++) ++cnt[rk[id[i]+w]] ;
        for(i = 1 ; i <= m ; i++) cnt[i] += cnt[i-1] ;
        for(i = n ; i >= 1 ; i--) sa[cnt[rk[id[i]+w]]--] = id[i] ;

        memset(cnt, 0 , sizeof(cnt));
        for(i = 1 ; i <= n ; i++) id[i] = sa[i] ;
        for(i = 1 ; i <= n ; i++) ++cnt[rk[id[i]]] ;
        for(i = 1 ; i <= m ; i++) cnt[i] += cnt[i-1] ;
        for(i = n ; i >= 1 ; i--) sa[cnt[rk[id[i]]]--] = id[i] ;

        memcpy(oldrk , rk , sizeof(rk));
        for(p = 0 , i = 1 ; i <= n ; i++){
            if(oldrk[sa[i]] == oldrk[sa[i-1]] &&
               oldrk[sa[i] + w] == oldrk[sa[i-1] + w])
                rk[sa[i]] = p ;
            else
                rk[sa[i]] = ++p ;
        }
    }

    //debug
//    cout << "Suffix Array is:\n" ;
//    for(int i = 1 ; i <= n ; i++){
//        cout << i << ' ' << strA.substr(sa[i]) << ' ' <<sa[i] << '\n' ;
//    }
}

void build_lcp(){
    int lcp[N] = {} ;
    int max_lcp = 0 ;
    for(int i = 1 , k = 0 ; i <= n ; i++){
        if(k) k-- ;
        while(strA[i+k] == strA[sa[rk[i]-1]+k]) ++k ;
        lcp[rk[i]] = k ;
    }

    for(int i = 1 ; i <= n ; i++){
        if((sa[i] < lenA && sa[i-1] < n+1 && sa[i-1] > lenA ) ||
            (sa[i] > lenA && sa[i-1] < n+1 && sa[i-1] < lenA))
            max_lcp = max(max_lcp , lcp[i]);
    }

    //debug
//    cout << "max_lcp is " << max_lcp << '\n' ;
//    for(int i = 0 ; i <= n ; i++)
//        cout << i << ' ' << lcp[i] << '\n' ;
//    cout << "lenA =" << lenA << "\nn is" << n << '\n' ;

    if(flag)
        cout << '\n' ;
    flag = 1 ;

    map<string,int> mp ;
    if(max_lcp == 0)
        {cout << "No common sequence.\n" ; return ;}
    for(int i = 1 ; i <= n ; i++){
        if((sa[i] < lenA && sa[i-1] < n+1 && sa[i-1] > lenA ) ||
           (sa[i] > lenA && sa[i-1] < n+1 && sa[i-1] < lenA))
           if(lcp[i] == max_lcp){
                string temp = strA.substr(sa[i] , max_lcp);
                if(mp[temp]) continue ;
                else mp[temp] = 1 ;
                cout << temp << '\n' ;
           }
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    //freopen("out.txt" , "w" , stdout );
#endif // LOCAL

    while(cin >> strA >> strB){
        lenA = strA.length()+1;
        lenB = strB.length();
        strA = ' ' + strA + '$' + strB + '#' ;
        //debug
        //cout << "strA is " <<strA << "\nstrA.length() is " << strA.length() << '\n' ;

        build_sa();
        build_lcp();
    }

    return 0;
}
