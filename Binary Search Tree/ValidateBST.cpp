/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// Problem solved : LeetCode 98 : Validate Binary Search Tree
// Problem Link : https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool checkBST(TreeNode* root)
    {
        if(root == NULL)
            return true;
        if (root->val > root->left->val && root->val < root->right->val)
            return true;
        else 
            return false;
        if(root->left)
            return checkBST(root->left);
        if(root->right)
            return checkBST(root->right);

    }
    bool isValidBST(TreeNode* root) {
        bool ans = checkBST(root);
        return ans;
    }
};







/*

bool validateBST(Node* root);
bool isBST(Node* root, int min, int max); //min = -inf max = +inf

bool isBST(Node* root, int min, int max) 
{
	if (root == NULL)
		return true;

	if (root->data >= min && root->data <= max) {
		bool left = isBST(root->left, min, root->data);
		bool right = isBST(root->right, root->data, max);
		return left && right;
	}
	else
		return false;
}
bool validateBST(Node* root)
{
	return isBST(root, INT_MIN, INT_MAX);
}*/