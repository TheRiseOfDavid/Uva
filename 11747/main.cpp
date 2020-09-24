#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define ll long long
using namespace std;
int parent[1020] ;

struct edge{
    ll n1 , n2 , w ;
}node[25020];


int compare(edge A , edge B ){
    return A.w < B.w ;
}


int find_root(int a){
    if(a != parent[a] )
        return parent[a] = find_root(parent[a]) ;
    return a ;
}



int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout );
#endif // LOCAL
    int n , m , p_n1 , p_n2 ; // parent_n1 , parent_n2
    vector<int> hce ; //heavy edge circle
    while(cin >> n >> m && n + m != 0 ){
        for(int i = 0 ; i < m ; i++ ){
            cin >> node[i].n1 >> node[i].n2 >> node[i].w ;
        }

        for(int i = 0 ; i < n ; i++)
            parent[i] = i ;
        sort(node , node + m , compare ) ;
        hce.clear() ;

        //kruskal
        for(int i = 0 ; i < m ; i++){
            p_n1 = find_root(node[i].n1) ;
            p_n2 = find_root(node[i].n2) ;
            if(p_n1 != p_n2 )
                parent[p_n2] = p_n1 ;
            else
                hce.push_back(node[i].w) ;

            //debug
            /**<
            for(int i = 0 ; i < n ; i++)
                cout << parent[i] << ' ' ;
            cout << '\n' ;
            */
        }
        sort(hce.begin() , hce.end()) ;
        if(hce.size()){
            for(int i = 0 ; i < hce.size()-1 ; i++)
                cout << hce[i] << ' ' ;
            cout << hce[hce.size()-1] ;
        }
        else
            cout << "forest" ;
        cout << '\n' ;
    }
    return 0;
}
