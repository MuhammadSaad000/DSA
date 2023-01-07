#include<iostream>
#include<vector>
using namespace std;

// Problem Solved : Two Sum - input is BST
// Problem Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
void Inorder(Node*& root, vector<int>&);
bool TwoSum(Node*& root,int target);

void Inorder(Node*& root, vector<int>& ans)
{	
	if (root == NULL)
		return;
	
	Inorder(root->left, ans);
	ans.push_back(root->data);
	Inorder(root->right, ans);
	return;
}

bool TwoSum(Node*& root, int target)
{
	vector<int> ans;
	if (root == NULL)
		return false;
	Inorder(root, ans);	//sorting tree using inorder traversal or dfs 
	int i = 0, j = ans.size() - 1;	//using two pointer approach

	while (i < j)
	{
		int sum = ans[i] + ans[j];
		if (sum == target)
			return true;
		else if (sum > target)
			j--;
		else if (sum < target)
			i++;
	}
	return false;
}



int main()
{
	Node* root = new Node(10);
	root->left = new Node(7);
	root->right = new Node(11);

	root->left->left = new Node(4);
	root->left->right = new Node(8);
	
	root->right->right = new Node(12);


	cout << TwoSum(root, 25);

	return 0;
}