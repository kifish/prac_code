/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 执行用时 :
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗 :
// 12.2 MB
// , 在所有 C++ 提交中击败了
// 9.09%
// 的用户


class Solution {
public:
    struct Node
    {
        int level;
        TreeNode* tree_node;
        Node(int level_, TreeNode* tree_node_): level(level_), tree_node(tree_node_) {}
    };
    
    queue<Node> q;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;

        q.push(Node(0, root));
        int pre_level = 0;
        int pre_val = 0;
        while(!q.empty()){
            Node cur_node = q.front();
            q.pop();

            if(pre_level != cur_node.level){
                ret.push_back(pre_val);
                pre_level = cur_node.level;
            }

            pre_val = cur_node.tree_node->val;
            if(cur_node.tree_node->left){
                q.push(Node(cur_node.level + 1, cur_node.tree_node->left));
            }

            if(cur_node.tree_node->right){
                q.push(Node(cur_node.level + 1, cur_node.tree_node->right));
            }
        }

        ret.push_back(pre_val);

        return ret;
    }
};


// https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/er-cha-shu-de-you-shi-tu-by-leetcode-solution/361141

// 这人给的解法也挺优雅的

