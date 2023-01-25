#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges);

void MakeAdjList(vector<pair<int, int>> edges, unordered_map<int, vector<int>>& adjList)
{
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}

void BreadthFirst(unordered_map<int, vector<int>> adjList,
	unordered_map<int, bool> visited, vector<int> ans, int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty()) {
		int frontNode = q.front();
		q.pop();
		ans.push_back(frontNode);

		for (auto i : adjList[frontNode])
		{
			if (!visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
	unordered_map<int, vector<int>> adjList;
	vector<int> ans;
	unordered_map<int, bool> visited;

	MakeAdjList(edges, adjList);

	for (int i = 0; i < vertex; i++) {
		if (!visited[i]) {
			BreadthFirst(adjList, visited, ans, i);
		}
	}


}

int main()
{

}