#include<iostream>
#include<vector>
using namespace std;

// Problem Solved : LeetCode 1382 : Balance a Binary Search Tree
// Problem Link : https://leetcode.com/problems/balance-a-binary-search-tree/
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
void Inorder(Node*& root, vector<int>& ans);
Node* InorderToBST(vector<int>& ans, int start, int end);
Node* BSTtoBalanced(Node*& root);

// Inorder traversal to get sorted array
void Inorder(Node*& root, vector<int>& ans)
{
	if (root == NULL)
		return;

	Inorder(root->left, ans);
	ans.push_back(root->data);
	Inorder(root->right, ans);
	return;
}

// using binary search to construct tree from sorted inorder of BST
Node* InorderToBST(vector<int>& ans, int start, int end)
{
	if (start > end)
		return NULL;
	int mid = start + (end - start) / 2;
	Node* root = new Node(ans[mid]);	// new root will be middle element of inorder traversal 
	// recursive call for left of root node
	root->left = InorderToBST(ans, start, mid - 1);

	// recursive call for right of root node
	root->right = InorderToBST(ans, mid + 1, end);
	return root;	// new root of BST
}

Node* BSTtoBalanced(Node*& root)
{
	if (root == NULL)
		return NULL;

	// 1st step - Finding inorder of BST

	vector<int> ans;
	Inorder(root,ans);
	// 2nd step - Construct BST from sorted Inorder traversal 
	root = InorderToBST(ans, 0, ans.size() - 1);
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
 

	BSTtoBalanced(root);

	return 0;
}