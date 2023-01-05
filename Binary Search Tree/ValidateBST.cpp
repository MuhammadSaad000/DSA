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