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
    int min_val;
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        min_val = root->val;
        return findFirstBigger(root);
    }
    int findFirstBigger(TreeNode* root){
        if(!root) return -1;
        if(root->val > min_val) return root->val;
        
        int left = findFirstBigger(root->left);
        int right = findFirstBigger(root->right);
        if(left == -1) return right;
        else if(right == -1) return left;
        return min(left,right);
    }
};