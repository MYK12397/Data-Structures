#include<bits/stdc++.h>
using namespace std;
class Graph {
	int V;
	list<int> *l;
public:
	Graph(int v) {
		V = v;
		//Array of linked lists
		l = new list<int>[V];
	}
	void addEdge(int u, int v, bool bidir = true) {
		l[v].push_back(u);
		l[u].push_back(v);
	}
	void printAdjlist() {
		for (int i = 0; i < V; i++) {
			cout << "vertex " << i << "->";
			//l[i] is a linked list
			for (int vertex : l[i])
				cout << vertex << ", ";

			cout << endl;
		}

	}
};
int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	g.printAdjlist();

	return 0;

}
