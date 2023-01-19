#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem Solved : Is Binary tree a max heap?
// heap : bt is complete bt and max order is followed
// Pronblem Link : https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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

int NodeCount(Node*& root)
{
    if (root == NULL)
        return 0;
    else
    {
        int ans = 1 + NodeCount(root->left) + NodeCount(root->right);
        return ans;
    }
}

// isCBT working fine checked on LEETCODE 
bool isCBT(Node*& root, int index, int count)
{
    if (root == NULL)   // base case 
        return true;

    if (index >= count) // index must not go out of the bound
        return false;
    else
    {
        bool left = isCBT(root->left, 2 * index + 1, count);
        bool right = isCBT(root->right, 2 * index + 2, count);
        return left && right;
    }
}

// check if cbt follows the property of max-heap
bool isMaxOrder(Node*& root)
{
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    if (root->left == NULL)
    {
        return (root->data > root->right->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
    }
}

bool isHeap(Node*& root)
{
    int count;
    int idx = 0;
    count = NodeCount(root);
    return (isCBT(root, idx, count) && isMaxOrder(root));
}


int main()
{ 
    Node* root = new Node(12);
    root->left = new Node(5);
    root->right = new Node(6);

    cout <<  "Is Binary Tree Heap : " << isHeap(root) << endl;
    

	return 0;
}