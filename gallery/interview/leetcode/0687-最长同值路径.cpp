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
    int res = 1;//最长路径中相同节点的个数
    int cal_same_val(TreeNode* root,int val){
        if(root == NULL) return 0;
        
        int l = cal_same_val(root->left,root->val);
        int r = cal_same_val(root->right,root->val);
        res = max(res,l+r+1);
        
        if(root->val != val){
            return 0;
        }
        else{
            return max(l,r) + 1;
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        cal_same_val(root,-1);
        return res - 1;
    }
};