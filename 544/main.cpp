#include <bits/stdc++.h>
#define Local

using namespace std;
string strA , strB ;
map<string, int> mapHash;
const int intSegments = 20000;
int intParent[250] ,intHash ;

int get(string strA ){
    if(!mapHash.count(strA)){
       mapHash[strA] = intHash++ ;

        //debug
        //cout << strA << ' ' << intHash << '\n' ;

    }
    return mapHash[strA] ;
}


struct node{
    int u , v , val ;
    void read(){
        cin >> strA >> strB >> val ;
        u = get(strA);
        v = get(strB);
    }
}nodEdge[intSegments];


int find_root(int intA){
    return intA == intParent[intA] ?  intA : intParent[intA] = find_root(intParent[intA]);
}


int main()
{
#ifdef Local
    freopen("in1.txt","r" , stdin);
    freopen("out.txt","w" , stdout);
#endif
    int n=4 , m=4 , intValue , intCase = 0 ;
    while(cin >> n >> m  && n + m != 0){
        intCase++ ;
        mapHash.clear();
        intHash = 0 ;
        for(int i = 0 ; i < n ; i++) intParent[i] = i ;
        for(int i = 0 ; i < m ; i++) nodEdge[i].read() ;
        string strStart , strDestination ;
        cin >> strStart >> strDestination ;
        sort(nodEdge , nodEdge+m , [](node nodA , node nodB){
             return  nodA.val > nodB.val ;
              }
        );

        /**<debug
        for(int i = 0 ; i < m ; i++)
            cout << nodEdge[i].u << ' ' << nodEdge[i].v << ' ' << nodEdge[i].val << '\n' ;
         */

        for(int i = 0 ; i < m ; i++){
            /**<debug
            for(int i = 0 ; i < n ; i++){
                cout << nodEdge[i].u << ' ' << intParent[nodEdge[i].u] << '\n' ;
                cout << nodEdge[i].v << ' ' << intParent[nodEdge[i].v] << '\n' ;
            }
            cout << '\n' ;
            */

            int intRootU , intRootV ;
            intRootU = find_root(nodEdge[i].u);
            intRootV = find_root(intParent[nodEdge[i].v]);
            if( intRootU != intRootV){
                intParent[intRootU] = find_root(intRootV) ;
                /**< debug
                cout << "start" << intParent[mapHash[strStart]] << ' ' \
                     << "Destination" << intParent[mapHash[strDestination]] << '\n' ;
                */

                if(find_root(intParent[mapHash[strStart]]) == find_root(intParent[mapHash[strDestination]])){
                    cout << "Scenario #" << intCase << '\n' ;
                    cout << nodEdge[i].val << " tons" << "\n\n";
                    break ;
                }
            }
        }

        /**<debug
        for(int i = 0 ; i < m ; i++){
            cout << nodEdge[i].u << ' ' << intParent[nodEdge[i].u] << '\n' ;
            cout << nodEdge[i].v << ' ' << intParent[nodEdge[i].v] << '\n' ;
        }
        cout << '\n' ;
        */

    }

    return 0;
}
