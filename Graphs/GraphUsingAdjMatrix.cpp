#include<iostream>
using namespace std;

class Graph {
private:
	bool** adjMatrix;
	int numOfNodes;	// graph with num of nodes 

public:
	Graph(int numOfNodes) {
		this->numOfNodes = numOfNodes;
		adjMatrix = new bool* [numOfNodes];	// creating 2d dynamic matrix
		// initialize the matrix with all false/zeros

		for (int i = 0; i < numOfNodes; i++) {
			adjMatrix[i] = new bool[numOfNodes];
			for (int j = 0; j < numOfNodes; j++)
				adjMatrix[i][j] = false;
		}
	}

	// Add Edges
	void AddEdge(int origin, int destination)
	{
		adjMatrix[origin][destination] = true;
		adjMatrix[destination][origin] = true;
	}

	void RemoveEdge(int origin, int destination)
	{
		adjMatrix[origin][destination] = false;
		adjMatrix[destination][origin] = false;
	}

	void PrintAdjMatrix()
	{
		for (int i = 0; i < numOfNodes; i++) {
			for (int j = 0; j < numOfNodes; j++) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	~Graph()
	{ 
		for (int i = 0; i < numOfNodes; i++)
			delete[] adjMatrix[i];
		delete[] adjMatrix;
	}
};
	
int main()
{
	Graph g1(3);

	g1.AddEdge(0, 1);
	g1.AddEdge(1, 2);
	g1.AddEdge(2, 0);

	cout << "Printing Adjacency Matrix " << endl;
	g1.PrintAdjMatrix();

	cout << "Adjacency Matrix after removing edge(2,0) " << endl;
	g1.RemoveEdge(2, 0);
	g1.PrintAdjMatrix();
	

	return 0;
}