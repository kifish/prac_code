/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/

// 执行用时 :
// 4 ms
// , 在所有 C++ 提交中击败了
// 95.67%
// 的用户
// 内存消耗 :
// 12.1 MB
// , 在所有 C++ 提交中击败了
// 6.67%
// 的用户

// 三种遍历永远是左先于右的。这里并不是后序遍历，只是写法可以模仿后序遍历。

class Solution {
public:
    TreeNode* pre_root = nullptr;
    void flatten(TreeNode* root) {
        // 不是后序遍历; 但可以模仿后序遍历的写法
        if(root == nullptr){
            return;
        }

        flatten(root->right);
        flatten(root->left);
        root->right = pre_root;
        root->left = nullptr;
        pre_root = root;
    }
};