#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Problems Solved : Creation of BST, Search in BST (iterative + recursive) 

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
void CreateTree(Node*& root);
Node* InsertToBST(Node*& root, int data);
vector<vector<int>> LevelOrderTraversal(Node*& root);
bool isPresent(Node*& root, int data);		//recursive
Node* SearchBST(Node*& root, int data);		// iterative
int MinValue(Node*& root);
int MaxValue(Node*& root);


// function definitions
void CreateTree(Node*&root)
{
	int data;
	cout << "Enter data for root : ";
	cin >> data;

	while (data != -1)
	{
		InsertToBST(root, data);
		cin >> data;
	}
}
Node* InsertToBST(Node*& root, int data)
{
	if (root == NULL)
	{
		root = new Node(data);
		return root;
	}

	if (data < root->data) {
		root->left = InsertToBST(root->left, data);
	}
	if (data > root->data) {
		root->right = InsertToBST(root->right, data);
	}
	return root;
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

// Recursive method 
bool isPresent(Node*& root, int data)
{
	if (root == NULL)
		return false;
	if (root->data == data)
		return true;

	if (data > root->data)	//if data is greater than current node search left part
		return isPresent(root->right, data);
	if (data < root->data)	// if data is greater than right node search right part
		return isPresent(root->left, data);
}
// Iterative Approach
Node* SearchBST(Node*& root, int data)
{
	Node* temp = root;
	while (temp != NULL) {
		if (temp->data == data)
			return temp;
		else if (data < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp; 
}

// Delete from BST 

Node* DeleteFromBST(Node*& root, int data)
{
	if (root == NULL)
		return NULL;
	
	if (root->data == data) {
		//No child 
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}

		//1 child
		if (root->left != NULL && root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else if (root->left == NULL && root->right != NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}

		//2 child
		else if (root->left != NULL && root->right != NULL) {
			int min = MinValue(root->right);
			root->data = min;
			root->right = DeleteFromBST(root->right, min);
			return root;
		}
	}


	else if (root->data > data) {
		root->left = DeleteFromBST(root->left, data);
		return root;
	}
	else if (root->data < data) {
		root->right = DeleteFromBST(root->right, data);
		return root;
	}

}

int MinValue(Node*& root)
{
	Node* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp->data;
}

int MaxValue(Node*& root)
{
	Node* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp->data;
}


int main()
{
	Node* root = NULL;
	// 10 8 21 7 27 5 4 3 -1
	CreateTree(root);
	vector<vector<int>> ans = LevelOrderTraversal(root);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Is element present ? " << isPresent(root, 11) << endl;

	cout << SearchBST(root, 11) << endl;

	cout << MaxValue(root) << endl;

	cout << MinValue(root) << endl;

	return 0;
}