
/*

https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1026/


*/

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

// class Solution {
// public:
//     TreeNode* lcs = nullptr;

//     // dfs: 如果root(是p的父节点或是p)或(是q的父节点或是q)则返回true
//     bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
//         if(root == nullptr){
//             return false;
//         }

//         bool in_left = dfs(root->left, p, q);
//         bool in_right = dfs(root->right, p,q);
//         // p、q 为不同节点且均存在于给定的二叉树中。
//         bool in_current_code = root->val == p->val || root->val == q->val ? true : false;
//         if(in_left && in_right || ((in_left || in_right) && in_current_code)){
//             lcs = root;
//         }

//         return in_left || in_right || in_current_code;
//     }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         dfs(root, p, q);
//         return lcs;    
//     }
// };


// 如果是二叉搜索树, 可以写的非常优雅:
// interview\leetcode\面试题68-I-二叉搜索树的最近公共祖先.cpp

// 本题是二叉树
// 更优雅的写法
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/

// 执行用时：
// 20 ms
// , 在所有 C++ 提交中击败了
// 93.47%
// 的用户
// 内存消耗：
// 14.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

// 这个ppt的演示非常形象。
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/

// 这个递归实现里有回溯的思想
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left == nullptr && right == nullptr) return nullptr;

        else if(left && right == nullptr){
            return left;
        }
        else if(right && left == nullptr){
            return right;
        }
        else return root;
    }
};

