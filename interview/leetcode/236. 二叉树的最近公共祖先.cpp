/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/


// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/390631

// 执行用时 :
// 28 ms
// , 在所有 C++ 提交中击败了
// 46.41%
// 的用户
// 内存消耗 :
// 14.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    TreeNode* lcs = nullptr;

    // dfs: 如果root(是p的父节点或是p)或(是q的父节点或是q)则返回true
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return false;
        }

        bool in_left = dfs(root->left, p, q);
        bool in_right = dfs(root->right, p,q);
        // p、q 为不同节点且均存在于给定的二叉树中。
        bool in_current_code = root->val == p->val || root->val == q->val ? true : false;
        if(in_left && in_right || ((in_left || in_right) && in_current_code)){
            lcs = root;
        }

        return in_left || in_right || in_current_code;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return lcs;    
    }
};

