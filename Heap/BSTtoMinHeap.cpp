#include<iostream>
#include<vector>
using namespace std;

// Problem Solved : Convert BST TO MIN HEAP 
// Problem Link : https://www.geeksforgeeks.org/convert-bst-min-heap/
// Approach : 1) convert bst to inorder to get sorted array 2) first(smallest) node of inorder will 
// the root node of min Heap now fill the tree in preorder manner from inorder/sorted traversal of BST

class Node
{
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

void Inorder(Node*& root,vector<int>&ans)
{
    if (root == NULL)
        return;

    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
}

void FillPreorder(Node*& root, vector<int>& inorder,vector<int>& ans,int& index);

void FillPreorder(Node*& root, vector<int>& inorder,vector<int>&ans ,int& index)
{
    if (root == NULL)
        return;

    ans.push_back(inorder[index++]);
    FillPreorder(root->left, inorder, ans, index);
    FillPreorder(root->right, inorder, ans, index);
}



int main()
{ 
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    vector<int> ans;
    Inorder(root, ans);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    vector<int> preOrder;
    int idx = 0;
    FillPreorder(root, ans, preOrder, idx);
    for (auto i : preOrder)
        cout << i << " ";
    cout << endl;
	return 0;
}