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
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if(!root1 && !root2) return true;
        else if(!root1 && root2) return false;
        else if(!root2 && root1) return false;

        if(root1->val != root2->val) return false;
        if(!root1->left && !root1->right){
            if (!(!root2->left && !root2->right)) return false;
            return true;
        }
        if(!root1->left && root1->right){
            if(!root2->left && root2->right){
                if(root1->right->val == root2->right->val)
                    return flipEquiv(root1->right, root2->right);
            }
            else if(!root2->right && root2->left){
                if(root1->right->val == root2->left->val){
                    return flipEquiv(root1->right,root2->left);
                }
            }
            return false;
        }

        else if (!root1->right && root1->left)
        {
            if (!root2->left && root2->right)
            {
                if (root1->left->val == root2->right->val)
                    return flipEquiv(root1->left, root2->right);
            }
            else if (!root2->right && root2->left)
            {
                if (root1->left->val == root2->left->val)
                {
                    return flipEquiv(root1->left, root2->left);
                }
            }
            return false;
        }
        else{
            if(root2->left && root2->right){
                if(root2->left->val == root1->left->val && root2->right->val == root1->right->val) return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
                else if (root2->left->val == root1->right->val && root2->right->val == root1->left->val)
                    return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
                return false;
            }
            return false;
        }
    }
};