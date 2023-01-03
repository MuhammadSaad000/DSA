#include<iostream>
using namespace std;

// Problems solved: Leetcode 100 : Same Binary Tree
// Problem Link : https://leetcode.com/problems/same-tree/

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

// function prototypes
bool isSame(Node*& root1, Node*& root2);
bool Sum(Node*& root1);

// function definitions
bool isSame(Node*& root1, Node*& root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL && root2 != NULL)
		return false;
	if (root1 != NULL && root2 == NULL)
		return false;

	bool left = isSame(root1->left, root2->left);
	bool right = isSame(root1->right, root2->right);

	bool val = (root1->data == root2->data);

	if (left && right && val)
		return true;
	else
		return false;
}

bool Sum(Node*& root)
{
	//checking for leaf nodes 
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return true;

	int sum = 0;
	//calculating sum of left and right
	if (root->left)
		sum += root->left->data;
	if (root->right)
		sum += root->right->data;


	//checking if current node data is equal to left sum
	// then calling for left and right of current node
	return (root->data == sum && Sum(root->left)
		&& Sum(root->right));
}



int main()
{
	Node* root1 = new Node(5);
	root1->left = new Node(1);
	root1->right = new Node(3);

	Node* root2 = new Node(5);
	root2->left = new Node(2);
	root2->right = new Node(3);

	cout << isSame(root1,root2) << endl;
	cout << "Sum : " << Sum(root2) << endl;

	return 0;
}