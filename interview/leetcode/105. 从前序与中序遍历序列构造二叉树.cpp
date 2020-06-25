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

    void preorder(TreeNode* root){
        if(root == nullptr) return;
        // root
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode* root){
        if(root == nullptr) return;

        inorder(root->left);
        // root
        inorder(root->right);
    }
    vector<int> v1;
    vector<int> v2;

    TreeNode* build_tree(int s1,int e1, int s2, int e2){
        if(s1 > e1){
            return nullptr;
        }

        int root_val = v1[s1];
        int root_idx = s2;
        for(;root_idx <= e2;root_idx++){
            if(v2[root_idx] == root_val)
                break;
        }
        TreeNode* root = new TreeNode;
        root->val = root_val;
        root->left = build_tree(s1+1,s1+1+root_idx-1-s2,s2,root_idx-1);
        root->right = build_tree(e1-(e2-root_idx-1),e1,root_idx+1,e2);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        v1 = preorder;
        v2 = inorder;
        TreeNode* root = new TreeNode;
        root = build_tree(0,(int) v1.size()-1,0,(int) v2.size() -1);
        return root;
    }
};