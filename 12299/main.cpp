#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define LOCAL
#define Lson(x) ((x << 1) +1)
#define Rson(x) ((x << 1) +2)
#define INF 99999999
using namespace std;
const int N = 100005 ;
int shift[35] , num[N] , len_shift ;
string strLine ;


struct Node{
    int left , right , Min_Value  ;
}node[4 * N ];


void build(int left , int right , int x = 0 ){
    node[x].left = left ;
    node[x].right = right ;
    if(left == right){
        node[x].Min_Value = num[left] ;
        return ;
    }
    int mid = (left + right ) / 2 ;

    //debug
    //cout << mid << '\n' ;
    //cout << x << ' ' << node[x].left << ' ' << node[x].right << ' ' << '\n' ;

    build(left , mid , Lson(x)) ;
    build(mid + 1 , right , Rson(x)) ;
    node[x].Min_Value = min(node[Lson(x)].Min_Value  , node[Rson(x)].Min_Value ) ;
}


void handle(){
    len_shift = 0 ;
    shift[len_shift] = 0;
    for(int i = 6 ; i < strLine.length() ; i++){
        if(strLine[i] >= '0' && strLine[i] <= '9' ){
            shift[len_shift] = shift[len_shift] * 10 + (int) (strLine[i] - '0' ) ;
        }
        else{
            shift[++len_shift ] = 0 ;
        }
    }
    //finaly char is ')' , so len_shift is right
    sort(shift , shift + len_shift ) ;

    //debug
    /**<
    for(int i = 0 ; i < len_shift ; i++)
        cout << shift[i] << ' ' ;
    cout << '\n' ;
    */
}


int query(int left , int right , int x = 0 ){
    if(node[x].left >= left && node[x].right <= right)
        return node[x].Min_Value ;
    int mid = (node[x].left + node[x].right ) / 2 ;
    int ans = INF ;

    //debug
    //cout << x << ' ' << node[x].left << ' ' << node[x].right << ' ' << node[x].Min_Value << '\n' ;

    if( left <= mid )
        ans = min(ans , query(left , right , Lson(x))) ;
    if(mid < right )
        ans = min(ans , query(left , right , Rson(x))) ;
    return ans ;
}


void set_num(int position , int value , int x = 0 ){
    if(node[x].left == position && node[x].right == position ){
       node[x].Min_Value = value ;
       return ;
    }
    int mid = (node[x].left + node[x].right ) / 2 ;
    if(position <= mid )
        set_num(position , value , Lson(x) );
    if(mid < position )
        set_num(position , value , Rson(x)) ;
    node[x].Min_Value = min(node[Lson(x)].Min_Value , node[Rson(x)].Min_Value );

}


int main()
{
    int n , q , intTemp ;
    ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("out.txt" , "w" , stdout ) ;
    freopen("in1.txt" , "r" , stdin ) ;
#endif // LOCAL
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i++)
        cin >> num[i] ;
    build(1,n);

    //debug
    /**<
    for(int i = 0 ; i < 13 ; i++){
        cout << node[i].left << ' ' << node[i].right << ' ' << node[i].Min_Value << '\n' ;
    }
    return 0 ;
    */

    while(q--){
        cin >> strLine ;
        if(strLine[0] == 'q'){
            handle();
            cout << query(shift[0] , shift[1] ) << '\n' ;
        }
        else if (strLine[0] == 's'){
            handle();
            intTemp = num[shift[0]] ;

            for(int i = 1 ; i < len_shift ; i++){
                set_num(shift[i-1] , num[shift[i]]) ;
                num[shift[i-1]] = num[shift[i]] ;
            }
            num[shift[len_shift-1]] = intTemp ;
            set_num(shift[len_shift-1] , intTemp );

            //debug
            //cout << intTemp << ' ' << shift[len_shift-1] << '\n' ;
            //for(int i = 1 ; i <= n ; i++)
             //   cout << num[i] << ' ' ;
        }
    }
    return 0;
}
