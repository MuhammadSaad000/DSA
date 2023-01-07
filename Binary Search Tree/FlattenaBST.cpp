#include<iostream>
#include<vector>
using namespace std;

// Problem Solved : Flatten BST to Linked List
// Problem Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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

void Inorder(Node*& root, vector<Node*>& ans)
{
	if (root == NULL)
		return;
	Inorder(root->left,ans);
	ans.push_back(root);
	Inorder(root->right,ans);
	return;
}

Node* FlattenBST(Node*& root)
{
	if (root == NULL)
		return NULL;

	vector<Node*> ans;
	// 1st step - create sorted array of nodes using inorder
	Inorder(root, ans);
	int i = 0, n = ans.size();

	Node* first = ans[i];
	Node* curr = first;

	// 2nd step - Linking all nodess
	for (i = 1; i < n; i++){
		Node* temp = ans[i];
		curr->left = NULL;	//make each left pointer NULL
		curr->right = ans[i]; // pointing iTh node to (i+1)th node
		curr = temp;	
	}

	// 3rd Step - Pointing left and right of last node to null
	curr->left = NULL;
	curr->right = NULL;
	return first;
}

void PrintList(Node* root) {
	Node* temp = root;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->right;
	}
	return;
}

int main()
{
	Node* root = new Node(5);
	root->left = new Node(4);
	root->right = new Node(8);
	root->left->left = new Node(1);
	root->right->left = new Node(6);

	Node* ans = FlattenBST(root);
	PrintList(ans);
	return 0;
}