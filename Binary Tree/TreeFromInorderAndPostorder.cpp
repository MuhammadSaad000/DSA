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

// Problem Solved : Construct a Binary Tree from PostOrder and InOrder Traversal
// Problem Link : LeetCode 106 : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal



#include<iostream>
#include<vector>
#include<map>
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
    void createMap(vector<int> inorder, map<int, int>& nodeToIdx, int size)	//doing mapping of all the inorder elements in hashmap
    {
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIdx[inorder[i]] = i;      //key(element or value) to index mapping
        }
    }
    TreeNode* SolveTree(vector<int> postorder, vector<int> inorder, int& postIdx, int inStIdx, int inEndIdx, map<int, int> nodeToIdx)
    {
        // Base case 
        if (postIdx < 0 || inStIdx > inEndIdx)
            return NULL;

        int element = postorder[postIdx--];	//decrementing root in postorder
        //declaring first index of preOrder as root
        TreeNode* root = new TreeNode(element);
        //find position of node in InOrder 
        int position = nodeToIdx[element];

        //recursive calls for the remaining nodes 
        // recursive call for right will be made first in post order as we are going from right to left
        // and next root in postOrder is in right of root in inorder
        root->right = SolveTree(postorder, inorder, postIdx, position + 1, inEndIdx, nodeToIdx);
        root->left = SolveTree(postorder, inorder, postIdx, inStIdx, position - 1, nodeToIdx);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;
        map<int, int> nodeToIdx;
        createMap(inorder, nodeToIdx, postorder.size());
        TreeNode* ans = SolveTree(postorder, inorder, postIdx, 0, postorder.size() - 1, nodeToIdx);
        return ans;
    }
};