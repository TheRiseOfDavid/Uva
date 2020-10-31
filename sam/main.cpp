#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct state {
  int len, link;
  std::map<char, int> next;
};
const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;

void sam_init() {
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}

void sam_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].next.count(c)) {
    st[p].next[c] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      while (p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}

int main()
{
    string strA = "abcb" ;
    sam_init();
    for(int i = 0 ; i < strA.length() ; i++)
        sam_extend(strA[i]) ;

    for(int i = 0 ; i <= sz ; i++){
        cout << i << ' ' << st[i].len << ' ' << st[i].link << '\n' ;
        for(auto it : st[i].next) cout << it.first << "=" << it.second << '\n' ;
        cout << "\n\n" ;
    }
    return 0;
}
