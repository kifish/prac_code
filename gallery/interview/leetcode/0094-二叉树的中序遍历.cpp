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
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //Õ»;µü´ú
        stack<TreeNode> S;
        TreeNode* t = root;
        while(t || !S.empty()){
            while(t){
                S.push(*t);
                t = t->left;
            }
            if(!S.empty()){
                res.push_back(S.top().val);
                t = S.top().right;
                S.pop(); 
            }
        }
        return res;
    }
};