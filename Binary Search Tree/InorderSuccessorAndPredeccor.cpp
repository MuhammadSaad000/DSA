#include<iostream>
using namespace std;

// Problem Solved : Inorder Predecessor and Successor in BST
// Problem Link : https://leetcode.com/problems/inorder-successor-in-bst/
// https://www.codingninjas.com/codestudio/problems/_893049


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
pair<int, int> predecessorSucc(Node*& root, int key)
{
	int pred = -1;
	int succ = -1;
	// Finding key 
	Node* temp = root;
	while (temp->data != key) {
		if (temp->data > key) {
			// if data is greater than key means it is successor node
			succ = temp->data;
			temp = temp->left;	//moving to left
		}
		else
		{
			// if data is less than key it is a predecessor node
			pred = temp->data;
			temp = temp->right; // moving to right
		}
	}

	// predecessor
	Node* leftTree = temp->left;
	while (leftTree!=NULL)
	{
		// in pred we have to find maximum value in left subtree  
		pred = leftTree->data;
		leftTree = leftTree->right;
	}

	// successor
	Node* rightTree = temp->right;
	while (rightTree != NULL) {
		succ = rightTree->data;
		rightTree = rightTree->left;
	}
	pair<int, int> ans = {pred,succ};

	return ans;
}


int main()
{
	Node* root = new Node(5);
	root->left = new Node(4);
	root->right = new Node(8);
	root->left->left = new Node(1);
	root->right->left = new Node(6);

	pair<int,int> ans = predecessorSucc(root, 1);
	cout << "Predecessor" << ans.first << endl;
	cout << "Successor" << ans.second << endl;

	return 0;
}