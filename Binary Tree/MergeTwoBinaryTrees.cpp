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

// Problem Solved : Merge Two Binary Trees

// Problem Link : https://leetcode.com/problems/merge-two-binary-trees/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;
        int val1 = 0, val2 = 0;
        if (root1)
            val1 = root1->val;

        if (root2)
            val2 = root2->val;

        TreeNode* newRoot = new TreeNode(val1 + val2);
        newRoot->left = mergeTrees(root1->left, root2->left);
        newRoot->right = mergeTrees(root1->right, root2->right);

        return newRoot;
    }
};