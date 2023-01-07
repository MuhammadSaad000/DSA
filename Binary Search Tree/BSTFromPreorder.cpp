#include<iostream>
#include<vector>
using namespace std;

// Problem Solved : LeetCode 1008. Construct Binary Search Tree from Preorder Traversal
// Problem Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// submitted on leetcode


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

// function Prototypes
Node* PreToBST(vector<int>& preorder);
Node* SolvePreToBST(vector<int> preorder,int min,int max,int &idx);


Node* SolvePreToBST(vector<int> preorder, int min, int max, int& idx)
{
	if (idx >= preorder.size())	// index crosses total no of values in preorder array sizes
		return NULL;

	// given element doesn't lie in the given range 
	if (preorder[idx] > max && preorder[idx] < min)
		return NULL;

	Node* root = new Node(preorder[idx++]);	// adding the root to BST

	// checking range of each value of array
	root->left = SolvePreToBST(preorder, min, root->data, idx);
	root->right = SolvePreToBST(preorder, root->data, max, idx);

	return root;
}

Node* PreToBST(vector<int>& preorder)
{
	int i = 0,min = INT_MIN , max = INT_MAX;	// i = iterating index 
	Node* root = SolvePreToBST(preorder, min, max, i);
	return root;
}


int main()
{
	Node* root = new Node(10);
	root->left = new Node(7);
	root->right = new Node(11);

	root->left->left = new Node(4);
	root->left->right = new Node(8);
	
	root->right->right = new Node(12);
 

	return 0;
}