/*
https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1026/

https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

gallery\interview\leetcode\236. 二叉树的最近公共祖先.cpp



*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;

        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else{
            return root;
        }
    }
};
