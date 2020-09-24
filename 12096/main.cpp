#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
map<set<int> , int> mapSet ;
map<int , set<int> > mapSetReverse ;
vector<int> vecStack ;
int intHash ;


int set_hash(set<int> setTemp){
    int &intTemp = mapSet[setTemp] ;
    if(!intTemp){
        mapSetReverse[intHash] = setTemp ;
        intTemp = intHash++ ;
    }
    return intTemp ;
}


int main()
{
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
    freopen("out.txt" , "w" , stdout);
#endif // LOCAL
    int t , n ;
    string strCommand  ;
    set<int> setA , setB , setC ;
    int intA , intB , intC ;
    cin >> t ;
    while(t--){
        cin >> n ;
        intHash = 1 ;
        vecStack.clear() ;
        mapSet.clear() ;
        mapSetReverse.clear() ;
        while(n--){
            cin >> strCommand ;
            if(strCommand == "PUSH"){
                setA = {} ;
                vecStack.push_back(set_hash(setA)) ;
            }
            else if(strCommand == "DUP"){
                vecStack.push_back(vecStack.back()) ;
            }
            else if (strCommand == "UNION"){
                setA = mapSetReverse[vecStack.back()] ;
                vecStack.pop_back() ;
                setB = mapSetReverse[vecStack.back()] ;
                vecStack.pop_back() ;
                setC = {} ;
                set_union(setA.begin() , setA.end() , setB.begin() , setB.end() , inserter(setC , setC.begin())) ;
                vecStack.push_back(set_hash(setC)) ;
            }
            else if (strCommand == "INTERSECT"){
                setA = mapSetReverse[vecStack.back()] ;
                vecStack.pop_back() ;
                setB = mapSetReverse[vecStack.back()] ;
                vecStack.pop_back() ;
                setC = {} ;
                set_intersection(setA.begin() , setA.end() , setB.begin() , setB.end() , inserter(setC , setC.begin())) ;
                vecStack.push_back(set_hash(setC)) ;
            }
            else if(strCommand == "ADD"){
                intA = vecStack.back() ;
                vecStack.pop_back() ;
                setB = mapSetReverse[vecStack.back()] ;
                vecStack.pop_back() ;
                setB.insert(intA) ;
                vecStack.push_back(set_hash(setB)) ;
            }
            cout << mapSetReverse[vecStack.back()].size() << '\n' ;
        }

        cout << "***" << '\n';
    }
    return 0;
}
