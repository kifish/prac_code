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
    
    void search_root(TreeNode* root,int k,int& cnt){
        if(!root) return;
        cal_from_root(root,0,k,cnt);
        search_root(root->left,k,cnt);
        search_root(root->right,k,cnt);
    }
    void cal_from_root(TreeNode* root,int sum_val,int k,int& cnt){
        if(!root) return;
        sum_val += root->val;
        if(sum_val == k) {
            cnt++;
        }
        cal_from_root(root->left,sum_val,k,cnt);
        cal_from_root(root->right,sum_val,k,cnt);
    }
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0;
        search_root(root,sum,cnt);
        return cnt;
    }
};