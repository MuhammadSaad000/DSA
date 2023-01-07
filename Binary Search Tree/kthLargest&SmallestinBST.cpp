#include<iostream>
using namespace std;

// Problem Solved : kth Largest and kth Smallest in BST
// Problem Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

// function prototype
int kthSmallest(Node*& root, int k);
int Solve(Node*& root, int& i, int k);	//utility function for kth smallest
int kthLargest(Node*& root, int& i, int k);

int kthSmallest(Node*& root, int k)
{
	int i = 0;
	return Solve(root, i, k);
}

int Solve(Node*& root, int& i, int k)
{
	// inorder traversal for kth smallest in BST
	if (root == NULL || i > k)
		return -1;

	// Left 
	int left = Solve(root->left, i, k);
	if (left != -1)
		return left;
	i++;
	// node 
	if (i == k)
		return root->data;

	// right
	return Solve(root->right, i, k);
}

int kthLargest(Node*& root, int& i, int k)
{
	if (root == NULL)
		return -1;

	// reverse inorder in kth largest 
	int right = kthLargest(root->right, i, k);
	if (right != -1) {
		return right;
	}
	
	i++;

	if (i == k)
		return root->data;

	return kthLargest(root->left, i, k);
}


int main()
{
	Node* root = new Node(10);
	root->left = new Node(7);
	root->right = new Node(11);

	root->left->left = new Node(4);
	root->left->right = new Node(8);
	
	root->right->right = new Node(12);

	cout << kthSmallest(root,4) << endl;
	int i = 0;
	cout << kthLargest(root, i, 4) << endl;

	return 0;
}