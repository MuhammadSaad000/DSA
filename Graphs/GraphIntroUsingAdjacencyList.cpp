#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

class Graph {
public:
	// first is origin second is destination	
	unordered_map<int, vector<int>> adj;

	void AddEdge(int u, int v, bool dir)
	{
		// direction = 0 -> undirected graph
		// direction = 1 -> directed graph
		adj[u].push_back(v);
		if (dir == 0)
			adj[v].push_back(u);
	}

	void PrintAdjList()
	{
		for (auto i : adj) {
			cout << i.first << " ";
			for (auto j : i.second)
				cout << j << "->";
		cout << endl;
		}
	}
};



int main()
{
	int n,m;
	cout << "Enter the no of nodes : ";
	cin >> n;

	cout << "Enter the no. of edges : ";
	cin >> m;

	Graph g1;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g1.AddEdge(u, v , 0);
	}
	g1.PrintAdjList();
	return 0;

}

/* 5 nodes (0,1,2,3,4) origins
* 6 connections / edges / routes /ways 
0 1
1 2
2 3
3 1
3 4
0 4
*/