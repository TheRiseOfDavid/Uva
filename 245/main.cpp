#include<bits/stdc++.h>
#define LOCAL
#define MAXN 100000
using namespace std ;

char ch ;
string strTemp = "" ;
int wcnt = 0 , head = 0 , num =0   ;

struct stu_words{
    int next ;
    string word ;
}word[MAXN] ;

int main(){
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    //freopen("out.txt" , "w" , stdout );
#endif // LOCAL

    while(1){
        ch = getchar() ;
        if(ch == '0')
            break ;
        else if(isalpha(ch)){
            while(isalpha(ch)){
                strTemp += ch ;
                ch = getchar() ;
            }
            cout << strTemp ;
            word[wcnt].word = strTemp ;
            word[wcnt].next = head ;
            head = wcnt++ ;
            strTemp = "" ;
        }
        else if(isdigit(ch)){
            while(isdigit(ch)){
                num = num * 10 + (ch - '0') ;
                ch = getchar() ;
            }

            int cur = head , prev  ;
            for(int i = 1 ; i < num ; i++){
                prev = cur ;
                cur = word[cur].next ;
            }
            num = 0 ;
            cout << word[cur].word ;

            if(head != cur ){
                word[prev].next = word[cur].next ;
                word[cur].next = head ;
                head = cur ;
            }

        }
        putchar(ch) ;
    }

}
