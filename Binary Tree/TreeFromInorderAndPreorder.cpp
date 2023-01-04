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

// Problem Solved : Construct a Binary Tree from PreOrder and InOrder Traversal
// Problem Link : LeetCode 105 : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/



#include<iostream>
#include<vector>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


class Solution {
public:

    int findPosition(vector<int> inorder, int element)	//element = root determined from preorder
    {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* SolveTree(vector<int> preorder, vector<int> inorder, int& preIdx, int inStIdx, int inEndIdx)
    {
        // Base case 
        if (preIdx >= preorder.size() || inStIdx > inEndIdx)
            return NULL;

        int element = preorder[preIdx++];	//incrementing root 
        //declaring first index of preOrder as root
        TreeNode* root = new TreeNode(element);
        //find position of node in InOrder 
        int position = findPosition(inorder, element);

        //recursive calls for the remaining nodes 
        root->left = SolveTree(preorder, inorder, preIdx, inStIdx, position - 1);
        root->right = SolveTree(preorder, inorder, preIdx, position + 1, inEndIdx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        TreeNode* ans = SolveTree(preorder, inorder, preIdx, 0, preorder.size() - 1);
        return ans;
    }
};