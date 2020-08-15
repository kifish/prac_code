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

vector<int> nums;
void init(TreeNode* root){
    if(!root) return;
    if(root->left) init(root->left);
    nums.push_back(root->val);
    if(root->right) init(root->right);
}
public:
    bool findTarget(TreeNode* root, int k) {
        init(root);
        int i = 0;
        int j = (int) nums.size() - 1;
        while(i<j){
            int v = nums[i] + nums[j];
            if(v == k) return true;
            else if(v < k) i++;
            else j--;
        }
        return false;
    }
};