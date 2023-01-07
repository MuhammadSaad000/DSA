#include<iostream>
using namespace std;

// Problem Solved : Least Common Ancestor in BST
// lowest common ancestor nodes of two nodes in BST 
// Problem Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
Node* LeastCommonAncestor(Node*& root, Node*& n1, Node*& n2);
Node* LowestCommon(Node*& root, Node*& n1, Node*& n2);


Node* LeastCommonAncestor(Node*&root, Node*& n1, Node*& n2) 
{
	while (root != NULL) 
	{
		if (root->data < n1->data && root->data < n2->data)
		{
			root = root->right;
		}
		else if (root->data > n1->data && root->data > n2->data) {
			root = root->left;
		}
		else
			return root;
	}
	return NULL;
}

Node* LowestCommon(Node*& root, Node*& n1, Node*& n2)
{
	if (root == NULL)
		return NULL;

	if (root->data < n1->data && root->data < n2->data)
		LowestCommon(root->right, n1, n2);

	else if (root->data > n1->data && root->data > n2->data)
		LowestCommon(root->left, n1, n2);
	else
		return root;
}


int main()
{
	Node* root = new Node(5);
	root->left = new Node(4);
	root->right = new Node(8);
	root->left->left = new Node(1);
	root->right->left = new Node(6);


	Node* ans1 = LowestCommon(root, root->left, root->right);
	Node* ans2 = LeastCommonAncestor(root, root->left, root->right);

	cout << ans1->data << endl;
	cout << ans2->data << endl;

	return 0;
}