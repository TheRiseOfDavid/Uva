#include <iostream>
#include <bits/stdc++.h>
#define LOCAL


using namespace std;


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    int intCase , n , intPosition ;
    string strWord , strAns , strLine ;
    vector<string> vecAns ;
    cin >> intCase ;
    n = 1 ;
    getline(cin , strLine ) ;
    getline(cin , strLine ) ;
    while(getline(cin , strLine )){
        //debug
        //cout << strLine << '\n' ;

        if(strLine != ""){
            stringstream ss ;
            ss.str("");
            ss.clear() ;
            ss << strLine ;
            intPosition = 0 ;
            strAns = "" ;
            while(ss >> strWord){
                //debug-
                //cout << strWord << '\n' ;

                if(strWord.length() > intPosition){
                    strAns += strWord[intPosition++] ;

                    //debug
                    //cout << strAns << '\n' ;

                }
            }
            vecAns.push_back(strAns) ;
        }
        else{
            cout << "Case #" << n++ << ":" << '\n' ;
            for(int i = 0 ; i < vecAns.size()-1 ; i++)
                cout << vecAns[i] << '\n' ;
            cout << vecAns[vecAns.size()-1] ;
            if(n-1 != intCase)
                cout << '\n' ;
            vecAns.clear() ;
            cout << '\n' ;
        }
    }
    return 0;
}
