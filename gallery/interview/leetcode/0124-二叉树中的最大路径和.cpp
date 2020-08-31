/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 错误的写法，因为这里实现的maxPathSum，可包含root也可不包含root，导致出错。
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        int left_sum = maxPathSum(root->left);
        int right_sum = maxPathSum(root->right);
        // 几种情况
        // left_sum+right_sum+root->val
        // root->val
        // left_sum
        // right_sum
        // left_sum + root->val
        // right_sum + root->val
        // 显然当前的实现方式中并不能保证路径一定是连续的, 有可能某些位置断了
        return max(left_sum+right_sum+root->val,max(root->val,max(left_sum+root->val,max(right_sum+root->val,max(right_sum,left_sum)))));
    }
};
*/



// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/shou-hui-tu-jie-hen-you-ya-de-yi-dao-dfsti-by-hyj8/



// 执行用时：
// 52 ms
// , 在所有 C++ 提交中击败了
// 36.61%
// 的用户
// 内存消耗：
// 28.4 MB
// , 在所有 C++ 提交中击败了
// 7.69%
// 的用户




class Solution
{
private:
    int max_path_sum = INT_MIN; // 使用一个global来求最优的结果; 为什么需要这么设计因为max_path_sum_include(root) 并不一定是全局最优值, 全局最优值可以出现在树中的任意一处, 且dfs之后再遍历找到这个位置也比较麻烦, 因此用一个全局变量解决问题
public:
    int max_path_sum_include(TreeNode* root){ // 包含该点的路径和, 但不能同时包含左子树和右子树; 因为同时包含左子树和右子树, 这个路径就不能保证是一条链, 可能会是多条链交叉
        if(!root) return 0;
        int left = max_path_sum_include(root->left);
        left = max(0,left); // 0相当于不包含，避免分情况讨论
        int right = max_path_sum_include(root->right);
        right = max(0,right);
        // 考了了root->val + left + right; root->val + left; root->val + right; root->val
        // left_sum和right_sum在之前的遍历过程中已经被考虑过了
        // 举例, 这棵树是个单单链表 -1->1->1
        // 1->1 这种情况肯定在考虑-1之前就被考虑过了
        max_path_sum = max(max_path_sum, root->val + left + right);
        // global 最优值变量和 返回值意义不一样, 是因为max_path_sum_include特殊设计的结果, 这个设计使得实现起来非常简洁, 不需要讨论很多情况

        return root->val + max(left,right); // 必须包含根节点, 保证最后形成的链条连续
    }

    int maxPathSum(TreeNode *root)
    {
        max_path_sum_include(root);
        return max_path_sum;
    }
};