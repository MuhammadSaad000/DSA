#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problems solved: Level order traversal in Binary Tree
// Problem Link : https://leetcode.com/problems/binary-tree-level-order-traversal


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

//function prototypes
int HeightOfTree(Node*& root);
void PrintLevel(Node*& root,int level);	//which level you want to print
void PrintLevelOrder(Node*& root);
vector<vector<int>> LevelOrderTraversal(Node*& root);

int HeightOfTree(Node*& root)
{
	//base case
	if (root == NULL)
		return 0;
	
	int leftHeight = HeightOfTree(root->left);
	int rightHeight = HeightOfTree(root->right);

	if (leftHeight >= rightHeight)
		return leftHeight + 1;	//simply adding 1 for each level
	else
		return rightHeight + 1;
}

void PrintLevel(Node*& root, int level)
{
	if (!root)	//if (root == NULL)
		return;

	if (level == 0)
	{
		cout << root->data << " ";
	}
	else
	{
		PrintLevel(root->left , level - 1);	//printing left part of tree
		PrintLevel(root->right , level - 1);//printing right part of tree
	}

}

void PrintLevelOrder(Node*& root)
{
	int h = HeightOfTree(root);
	for (int i = 0; i < h; i++) {
		PrintLevel(root, i);
		cout << endl;
	}
}


vector<vector<int>> LevelOrderTraversal(Node*& root)
{
	vector<vector<int>> ans;
	if (root == NULL)
		return ans;

	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();	//how many elements are in queue 
		// initially there is only root element in queue
		vector<int> level;	// storing elements of a single level in array
		for (int i = 0; i < size; i++) {
			Node* temp = q.front();	//getting first entry of queue 
			q.pop();
			
			//checking for left and right children & pushing to queue
			if (temp->left != NULL) q.push(temp->left);
			if (temp->right != NULL) q.push(temp->right);

			//finally inserting the values of single level in inner array
			level.push_back(temp->data);
		}
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
	root->left->right = new Node(2);

	root->right->left = new Node(7);

	vector<vector<int>> ans = LevelOrderTraversal(root);

	/*for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size() ; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << "Height of tree : " << HeightOfTree(root) << endl;
	PrintLevelOrder(root);


	return 0;
}