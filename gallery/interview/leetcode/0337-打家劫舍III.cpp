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
    int rob(TreeNode* root) {
        if(!root) return 0;
        int root_val = root->val;
        int sub_left_all = 0;
        int sub_right_all = 0;
        if(root->left){
            if(root->left->left)
                sub_left_all += rob(root->left->left);
            if(root->left->right)
                sub_left_all += rob(root->left->right);
        }
        if(root->right){
            if(root->right->right)
                sub_right_all += rob(root->right->right);
            if(root->right->left)
                sub_right_all += rob(root->right->left);
        }
        int sum1 = root_val + sub_left_all + sub_right_all;
        //可加memo优化
        int left_all = 0;
        int right_all = 0;
        if(root->left){
            left_all += rob(root->left);
        }
        if(root->right){
            right_all += rob(root->right);
        }
        int sum2 = left_all + right_all;
        if(sum1 > sum2){
            return sum1;
        }
        else return sum2;
    }
};