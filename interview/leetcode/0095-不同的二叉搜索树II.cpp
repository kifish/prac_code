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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>{};
        return construct_trees(1,n);
    }
    
    vector<TreeNode*> construct_trees(int begin,int end){
    vector<TreeNode*> roots;
    if(begin > end){
        roots.push_back(NULL);
        return roots;
    }
    for(int i=begin;i<=end;i++){
        vector<TreeNode*> left_subtree_roots = construct_trees(begin,i-1);
        vector<TreeNode*> right_subtree_roots = construct_trees(i+1,end);
        for(auto left_subtree_root : left_subtree_roots){
            for(auto right_subtree_root : right_subtree_roots){
                struct TreeNode* root = new TreeNode(i);
                root->left = left_subtree_root;
                root->right = right_subtree_root;
                roots.push_back(root);
            }
        }
    }
    return roots;
    }
};