#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Problems solved: Leetcode 103 : Zig zag Traversal of binary tree
// Problem Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
vector<vector<int>> ZigZagTraversal(Node*& root);

vector<vector<int>> ZigZagTraversal(Node*& root)
{
	vector<vector<int>> ans;
	if (root == NULL)
		return ans;

	queue<Node*> q;
	q.push(root);

	bool leftToRight = true;

	while (!q.empty()) {
		int size = q.size();

		vector<int> level(size);
		for (int i = 0; i < size; i++) 
		{
			Node* curr = q.front();
			q.pop();


			//index if normal insert or reverse insert
			int index;
			if (leftToRight) index = i;
			else index = size - i - 1;
			//putting in right index 
			level[index] = (curr->data);

			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);

		}
		//changing direction from left to right
		leftToRight = !leftToRight;
		ans.push_back(level);
	}
	return ans;
}

int main()
{
	Node* root = new Node(5);
	root->left = new Node(1);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(0);

	vector<vector<int>> ans = ZigZagTraversal(root);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size() ; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}