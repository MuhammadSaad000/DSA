#include<iostream>
#include<stack>
#include<vector>
using namespace std;


// Problems covered : Preorder and Post Order traversal using stack without recursion
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

//prototypes
vector<int> PreOrder(Node* root);
vector<int> PostOrder(Node* root);
vector<int> InOrder(Node* root);


//definitions
vector<int> PreOrder(Node* root)
{
	vector<int> ans;
	if (root == NULL)
		return ans;

	stack<Node*> st;
	st.push(root);

	while (!st.empty()) {
		root = st.top();
		st.pop();

		ans.push_back(root->data);
		if (root->right)    //pushing right first because st in lifo structure left node will be popped out first
			st.push(root->right);
		if (root->left)
			st.push(root->left);
	}	
	return ans;
}

vector<int> PostOrder(Node* root)
{
	vector<int> ans;
	if (root == NULL)
		return ans;

	stack<Node*> st;
	st.push(root);

	while (!st.empty()) {
		root = st.top();
		st.pop();

		ans.push_back(root->data);
		if (root->left)		//pushing left first because st in lifo structure
			st.push(root->left);
		if (root->right)
			st.push(root->right);
	}
	return ans;
}




int main()
{
	Node* root = NULL;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	vector<int> s = PreOrder(root);

	cout << endl << "PreOrder  " ;

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " " ;
	}
	cout << endl << "PostOrder  " ;
	s = PostOrder(root);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}

}