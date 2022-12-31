#include<iostream>
#include<queue>
using namespace std;

class Node{
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

// File Completed on December 31,2022.
// Topics Covered : Intro and Traversals in Binary Trees

Node* BuildTree(Node*& root);
void LevelOrderTraversal(Node* root);	//level-by-level or Breadth First Search
void InOrder(Node* root);
void PreOrder(Node* root);
void PostOrder(Node* root);


Node* BuildTree(Node*& root)
{
	int data;
	cout << "Enter the data for root node: " << endl;
	cin >> data;
	root = new Node(data);

	if (data == -1) {	//if user enters -1 means root has no left or right child
		return NULL;
	}

	cout << "Enter data for inserting in left of " << data << endl;
	root->left = BuildTree(root->left);
	cout << "Enter data for inserting in right of " << data << endl;
	root->right = BuildTree(root->right);
	return root;

}

void LevelOrderTraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);		
	//adding separator as one level has ended root only level-0
	q.push(NULL);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp == NULL) {	//single level has been traversed
			cout << endl;	
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
}

void InOrder(Node* root)	// left node(print) right (LNR)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);

}

void PreOrder(Node* root)		//node(print) left right (NLR)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);

}

void PostOrder(Node* root)  // Left Right Node(print) (LRN)
{
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}



int main()
{
	Node* root = NULL;
	root = BuildTree(root);

	//7 4 1 -1 -1 3 -1 -1 12 5 -1 -1 -1
	LevelOrderTraversal(root);

	cout << "Pre order traversal : " << endl;
	PreOrder(root);
	cout << endl;

	cout << "In order traversal : " << endl;
	InOrder(root);
	cout << endl;

	cout << "Post order traversal : " << endl;
	PostOrder(root);
	cout << endl;

	return 0;
}