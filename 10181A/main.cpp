#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;
int n ;
//unordered_map<string,int> visit ;
set<string> visit ; // no set will be AC
int direct[4][4] = {{0,1},{0,-1},{1,0},{-1,0}};
int place[18][2] ;
char dname[4] = {'R' , 'L' , 'D' , 'U'};

struct state{
    int graph[4][4] ;
    int x,y;
    int h=-1 , step=0 ;
    string path ="" ;
    bool operator <(state st) const{
        return h + step > st.h + st.step ;
    }

    void print(){
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4 ; j++)
                cout << graph[i][j] << ' ' ;
            cout << '\n' ;
        }
        cout << '\n' ;
    }

};

int h(int graph[][4]){
    int cnt = 0 ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(graph[i][j] == 0 || (i == place[graph[i][j]][0] && \
                                      j == place[graph[i][j]][1]  ))
                continue ;
            cnt += abs(place[graph[i][j]][0] - i) + abs(place[graph[i][j]][1] - j ) ;
        }
    }
    return cnt * 10 ;
}

bool isboard(int x , int y ){
    if(x >= 0 && x < 4 && y >= 0 && y < 4)
        return true ;
    return false ;
}

bool isrecord(int graph[][4] ){
    string strM ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++)
            strM.push_back((char) graph[i][j] + '0') ;
    }
    ///*
    if(visit.count(strM)){
        //cout << strM << '\n' ;
        return true ;
    }

    visit.insert(strM) ; //TLE key
    //visit[strM] = 1 ;
    //*/
    return false ;
}

bool isback(string path , char nxtD ){
    if(path.size() == 0) return false ;
    char D = path[path.size()-1] ;
    if(D == 'L' && nxtD == 'R' ) return true ;
    if(D == 'R' && nxtD == 'L' ) return true ;
    if(D == 'U' && nxtD == 'D' ) return true ;
    if(D == 'D' && nxtD == 'U' ) return true ;
    return false ;
}

bool Astar(state input ){
    priority_queue<state> q ;
    //visit.clear() ;
    int x , y;
    state now , next ;
    isrecord(now.graph);
    q.push(input);
    while(!q.empty()){
        now = q.top() ; q.pop() ;
        cout << now.h + now.step << '\n' ;
        now.print();
        for(int i = 0 ; i < 4 ; i++){
            x = now.x + direct[i][0] ;
            y = now.y + direct[i][1] ;
            if(!isboard(x,y)) continue ;
            if(isback(now.path,dname[i])) continue ;
            next = now ; //TLE key because this line go to 85 before.
            next.step = now.step + 1 ;
            if(next.step > 50 ) continue ;
            swap(next.graph[x][y] , next.graph[now.x][now.y]);
            //now.print() ;
            //cout << x << ' ' << y << '\n' ;
            //next.print();
            if(!isrecord(next.graph)){
                next.x = x ; next.y = y ;
                next.h = h(next.graph) ;
                next.path.push_back(dname[i]) ;
                q.push(next);
                if(next.h == 0 ){
                    cout << next.path << '\n' ;
                    return true ;
                }
                cout << next.path << '\n' ;

                //next.print();
            }
        }
    }
    return false ;
}

bool issolve(int graph[][4]){
    int cnt = 0 , x , y  ;
    int num[16] = {};
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            num[cnt++] = graph[i][j] ;
            if(graph[i][j]==0) x = i , y = j ;
        }
    }
    cnt = 0 ;
    for(int i = 0 ; i < 16 ; i++){
        for(int j = i+1 ; j < 16 ; j++){
            if(num[j] && num[j] < num[i]) cnt++ ;
        }
    }
    cout << cnt + x << '\n' ;
    if((cnt+x)%2 ==0)
        return false;
    return true ;
}

int32_t main(){
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int cnt = 1;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            place[cnt][0] = i ;
            place[cnt++][1] = j ;
        }
    }

    cin >> n ;
    while(n--){
        state input ;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                 cin >> input.graph[i][j] ;

                 if(input.graph[i][j] == 0)
                    input.x = i , input.y = j ;
            }
        }
        if(!issolve(input.graph) || !Astar(input))
            cout << "This puzzle is not solvable.\n" ;
    }
    return 0 ;
}

