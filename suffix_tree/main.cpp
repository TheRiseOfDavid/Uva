#include <iostream>
#include <stdio.h>
#include <string>

int oo = 1<<25;
const int ALPHABET_SIZE = 256;
const int MAXN = 5000;

using namespace std;

int root, last_added, pos, needSL, remainder,
	active_node, active_e, active_len;
//abbbababba$"
string text = "aba$" ;

struct node {
/*
   There is no need to create an "Edge" struct.
   Information about the edge is stored right in the node.
   [start; end) interval specifies the edge,
   by which the node is connected to its parent node.
*/

	int start, end, slink;
	int next[ALPHABET_SIZE];

	int edge_length() {
		return min(end, pos + 1) - start;
	}
};

node tree[2*MAXN];
//char text[MAXN];

int new_node(int start, int end = oo) {
	node nd;
	nd.start = start;
	nd.end = end;
	nd.slink = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		nd.next[i] = 0;
	tree[++last_added] = nd;
	return last_added;
}

char active_edge() {
	return text[active_e];
}

void add_SL(int node) {
	if (needSL > 0) tree[needSL].slink = node;
	needSL = node;
}

bool walk_down(int node) {
    cout << "walk " <<  active_len << ' ' << tree[node].edge_length() << ' ' << node << '\n' ;
	if (active_len >= tree[node].edge_length()) {
		active_e += tree[node].edge_length();
		active_len -= tree[node].edge_length();
		active_node = node;
		cout << "fine\n" ;
		return true;
	}
	return false;
}

void st_init() {
	needSL = 0, last_added = 0, pos = -1,
	remainder = 0, active_node = 0, active_e = 0, active_len = 0;
	root = active_node = new_node(-1, -1);
}

void st_extend(char c) {
	text[++pos] = c;
	needSL = 0;
	remainder++;
	while(remainder > 0) {
		if (active_len == 0) active_e = pos;
		if (tree[active_node].next[active_edge()] == 0) { // 判斷重複後綴
			int leaf = new_node(pos);
			tree[active_node].next[active_edge()] = leaf;
			add_SL(active_node); //rule 2
		} else {
			int nxt = tree[active_node].next[active_edge()];
			if (walk_down(nxt)) continue; //observation 2
			if (text[tree[nxt].start + active_len] == c) { //observation 1
				active_len++;
				add_SL(active_node); //observation 3
				break;
			}
			int split = new_node(tree[nxt].start, tree[nxt].start + active_len); //切割點
			cout << "debug: " << tree[nxt].start + active_len << "\n\n" ;
			tree[active_node].next[active_edge()] = split;
			int leaf = new_node(pos); //葉節點
			tree[split].next[c] = leaf;
			tree[nxt].start += active_len;
            cout << "demo: " << text[tree[nxt].start] << '\n' ;
			tree[split].next[text[tree[nxt].start]] = nxt;
			add_SL(split); //rule 2
		}
		remainder--;
		//debug
        cout << active_node << ' ' << root << ' ' << active_len << "\n\n" ;
		if (active_node == root && active_len > 0) { //rule 1
			active_len--;
			active_e = pos - remainder + 1;
		} else
			active_node = tree[active_node].slink > 0 ? tree[active_node].slink : root; //rule 3
	}
}

int main() {

	st_init();
	//xyzxyaxyz$"
	text = "xyzxyaxyz$";
	oo = text.length() ;
	for(int i = 0 ; i < text.length() ; i++) st_extend(text[i]);

	for(int i = 0 ; i <= last_added+1 ; i++){
        cout << i << ' ' << tree[i].start << ' ' << tree[i].end << ' ' << tree[i].slink << '\n' ;
        for(int j = 0 ; j < ALPHABET_SIZE ; j++)
            if(tree[i].next[j]) cout << char(j) << ' ' << tree[i].next[j] << '\n' ;

    }
    cout << "active: " << active_node << ' ' << active_e << " " << active_len << ' ' << pos << '\n' ;
    cout << last_added << '\n' ;
	return 0;
}
