#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define int long long
using namespace std;

int  h , m , s , data  ;
float new_speed , speed=0  , mile=0 ,s1=0 ,s2=0 ;
char strQ[128] ;


int32_t main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    while(gets(strQ)){
        //printf("%s\n" , strQ);
        data = sscanf(strQ , "%lld:%lld:%lld %f" , &h , &m , &s , &new_speed);
        //printf("%lld:%lld:%lld %f\n",h , m , s , new_speed);
        s2 = s1 ;
        s1 = h * 3600 + m * 60 + s ;
        mile += abs(s1-s2) * speed / 3600 ;
        if(data == 4){
            speed =new_speed ;
        }
        if(data == 3){
            //printf("speed is %f\n" , speed);

            printf("%.2lld:%.2lld:%.2lld %.2f km\n" , h , m ,s ,mile);
        }
    }

    return 0;
}
