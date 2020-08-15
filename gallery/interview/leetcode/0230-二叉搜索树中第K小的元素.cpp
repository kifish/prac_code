/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution
{
public:
    int left;
    int res;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left);
        if(left > 0){
            left--;
            if(left == 0) res = root->val;
        }
        else return;
        if (root->right)
            inorder(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        left = k;
        inorder(root);
        return res;
    }
};