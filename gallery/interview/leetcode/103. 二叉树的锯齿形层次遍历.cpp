/*

https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1027/

https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/


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


// 执行用时：
// 4 ms
// , 在所有 C++ 提交中击败了
// 74.88%
// 的用户
// 内存消耗：
// 11.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

// 这题的另一个名字是二叉树的之字形遍历

class Solution {
public:
    struct Node
    {
        int val;
        TreeNode* the_tree_node;
        int level;
        Node(int val, int level, TreeNode* the_tree_node):val(val), level(level), the_tree_node(the_tree_node){}
    };
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool odd = false;
        vector<vector<int>> ret;
        queue<Node> q;
        if(root == nullptr) return ret;

        vector<int> the_level_vals;
        int pre_level = 0; // pre_node_level
        q.push(Node(root->val, 0, root));
        while(!q.empty()){
            Node cur_node = q.front();
            q.pop();
            if(cur_node.level == pre_level){
                the_level_vals.push_back(cur_node.val);
            }
            else{
                if(odd){
                    reverse(the_level_vals.begin(), the_level_vals.end());
                }
                odd = !odd;
                ret.push_back(the_level_vals);
                the_level_vals.clear();
                the_level_vals.push_back(cur_node.val);
                pre_level = cur_node.level;
            }
            if(cur_node.the_tree_node->left){
                q.push(Node(cur_node.the_tree_node->left->val, pre_level+1, cur_node.the_tree_node->left));
            }
            if(cur_node.the_tree_node->right){
                q.push(Node(cur_node.the_tree_node->right->val, pre_level+1, cur_node.the_tree_node->right));
            }
        }

        if(the_level_vals.size()){
            if(odd){
                reverse(the_level_vals.begin(), the_level_vals.end());
            }
            odd = !odd;
            ret.push_back(the_level_vals);
        }
        return ret;
    }
};


// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-de-ju-chi-xing-ceng-ci-bian-li-by-leetc/

// 注意官方的python解法实际上也没真正实现锯齿形遍历

// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-de-ju-chi-xing-ceng-ci-bian-li-by-leetc/319804

// 可以看看这个解法, 相当于queue永远只存同一个level的node。

// 从左向右遍历还是从右向左遍历 只是取决于先加左节点再加右节点还是先加右节点还是再加左节点

