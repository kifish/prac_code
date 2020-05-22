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
    int rangeSumBST(TreeNode* root, int L, int R) {
        //可以通过中序遍历也可以通过递归。
        if(!root) return 0;
        if(root->val < L) return rangeSumBST(root->right,L,R);
        else if(root->val > R) return rangeSumBST(root->left,L,R);
        else return (rangeSumBST(root->left,L,R) + root->val + rangeSumBST(root->right,L,R));
    }
};