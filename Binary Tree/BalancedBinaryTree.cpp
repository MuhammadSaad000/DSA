#include<iostream>
using namespace std;

// Problems solved: Leetcode 110 : Balanced Binary Tree
// Problem Link : https://leetcode.com/problems/balanced-binary-tree/

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

// A height-balanced binary tree is a binary tree in which the depth 
// of the two subtrees of every node never differs by more than one.


// function prototypes
bool isBalanced(Node*& root);
bool BalanceUtil(Node*& root, int* height);


// function definitions
bool BalanceUtil(Node*& root,int* height)
{
	int leftHeight = 0, rightHeight = 0;
	if (root == NULL)
		return true;

	// checking balancing for each single node
	if (BalanceUtil(root->left, &leftHeight) == false)
		return false;
	if (BalanceUtil(root->right, &rightHeight) == false)
		return false;

	//how height of single node is calculated
	*height = max(leftHeight, rightHeight) + 1;	//+1 the node itself

	//calculating absolute difference now
	int diff = abs(leftHeight - rightHeight);
	if (diff <= 1) 
		return true;
	else 
		return false;
}

bool isBalanced(Node*& root) 
{
	int height = 0;
	return BalanceUtil(root, &height);
}


int main()
{
	Node* root = new Node(5);
	root->left = new Node(1);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->left = new Node(2);

	root->left->left->left = new Node(7);

	cout << "Is Tree Balanced : " << isBalanced(root) << endl;


	return 0;
}