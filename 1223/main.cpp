#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define N 5020
using namespace std;
int root , cnt , pos , needSL ,remainder_ ,
    active_node , active_e , active_len ;
string text ;
int oo ;
int max_lrs = 0 , lrs_index = 0 , lrs_repeat = 0 ;

struct node{
    int start , end , slink ;
    map<char,int> next ;

    int edge_length(){
        return min(end,pos+1) - start ;
    }

    void init(int st , int ed = oo){
        start = st ;
        end = ed ;
        slink = 0 ;
        next.clear() ;
    }
}tree[2*N];

char active_edge(){
    return text[active_e] ;
}

void add_SL(int node){
    if(needSL > 0 ) tree[needSL].slink = node;
    needSL = node ;
}

bool walkdown(int node){
    if(active_len >= tree[node].edge_length()){
        active_e += tree[node].edge_length() ;
        active_len -= tree[node].edge_length();
        active_node = node ;
        return true ;
    }
    return false ;
}

void st_init(){
    needSL = remainder_ = 0 ;
    active_node = active_e = active_len = 0 ;
    pos = -1 ;

    cnt = root = 1 ;
    active_node = 1 ;
    tree[cnt++].init(-1,-1);
    return ;
}

void st_extend(char c){
    pos++ ;
    needSL = 0 ;
    remainder_++ ;
    while(remainder_ > 0){
        if(active_len == 0 ) active_e = pos ;
        if(tree[active_node].next[active_edge()] == 0){
            int leaf = cnt ;
            tree[cnt++].init(pos) ;
            tree[active_node].next[active_edge()] = leaf ;
            add_SL(active_node) ;
        }
        else{
            int nxt = tree[active_node].next[active_edge()] ;
            if(walkdown(nxt)) continue ;
            if(text[tree[nxt].start + active_len] == c){
                active_len++ ;
                add_SL(active_node) ;
                break ;
            }

            int split = cnt;
            tree[cnt++].init(tree[nxt].start , tree[nxt].start + active_len) ;
            tree[active_node].next[active_edge()] = split ;
            int leaf = cnt;
            tree[cnt++].init(pos) ;
            tree[split].next[c] = leaf ;
            tree[nxt].start += active_len ;
            tree[split].next[text[tree[nxt].start]] = nxt ;
            add_SL(split) ;
        }
        remainder_-- ;
        if(active_node == root && active_len > 0){
            active_len--;
            active_e = pos - remainder_ + 1 ;
        }
        else{
            active_node = tree[active_node].slink > 0 ? tree[active_node].slink : root ;
        }
    }
    return ;
}

void debug(){
    for(int i = 0 ; i < cnt ; i++){
        cout << i << ' ' << tree[i].start << ' ' << tree[i].end << ' ' << tree[i].slink << '\n' ;
        for(auto it : tree[i].next){
            cout << it.first << ' ' << it.second << '\n' ;
        }
    }
    return ;
}

void lrs_dfs(int r , int len , int repeats){
    for(auto it : tree[r].next){
        lrs_dfs(it.second , len + tree[r].edge_length() , tree[r].next.size()) ;
    }
    if(tree[r].slink == 0 && len > max_lrs){
        lrs_repeat = repeats ;
        max_lrs = len ;
        lrs_index = tree[r].start - len ;
    }
    return ;
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    int n ;
    cin >> n ;
    while(n--){
        cin >> text ;
        st_init() ;
        text += "$" ;
        oo = text.length() ;
        for(int i = 0 ; i < text.length() ; i++) st_extend(text[i]);

        max_lrs = lrs_index = lrs_repeat = 0 ;
        lrs_dfs(root,0,0) ;
        cout << max_lrs << '\n' ;
    }

    return 0;
}
