#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problems solved: Count Leaf Nodes in Binary Tree
// Problem Link : https://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

//function prototypes
int LeafNodeCount(Node*& root);
void Inorder(Node*& root, int& count);	//for traversing the whole tree

void Inorder(Node*& root, int& count)	//Inorder -> LNR
{
	if (root == NULL)
		return;
	
	Inorder(root->left , count);

	//checking if node has left and right node
	if (root->left == NULL && root->right == NULL)
		count++;
	//going to both nodes and checking if it has both child as NULL

	Inorder(root->right, count);
}

int LeafNodeCount(Node*& root)
{
	int count = 0;
	//just traversing the whole tree
	Inorder(root, count);	//sending initial count as zero
	return count;
}



int main()
{
	Node* root = new Node(5);
	root->left = new Node(1);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(2);

	root->right->left = new Node(7);

	cout << "No of leaf node is : " << LeafNodeCount(root) << endl;

	return 0;
}