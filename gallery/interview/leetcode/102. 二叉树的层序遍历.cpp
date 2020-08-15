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
// 8 ms
// , 在所有 C++ 提交中击败了
// 47.36%
// 的用户
// 内存消耗 :
// 11.8 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    struct Node{
        TreeNode* tree_node;
        int level;
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;

        queue<Node*> q;
        Node* root_node = new Node;
        root_node->tree_node = root;
        root_node->level = 0;
        q.push(root_node);
        vector<int> cur_level;
        int pre_level = 0;
        while(q.size()){
            Node* cur_node = q.front();
            q.pop();
            if(cur_level.size() == 0){
                cur_level.push_back(cur_node->tree_node->val);
                if(cur_node->tree_node->left){
                    Node* left = new Node;
                    left->tree_node = cur_node->tree_node->left;
                    left->level = cur_node->level + 1;
                    q.push(left);
                }

                if(cur_node->tree_node->right){
                    Node* right = new Node;
                    right->tree_node = cur_node->tree_node->right;
                    right->level = cur_node->level + 1;
                    q.push(right);
                }
            }
            else {
                if(pre_level == cur_node->level){
                    cur_level.push_back(cur_node->tree_node->val);
                }
                else{
                    ret.push_back(cur_level);
                    cur_level.clear();
                    cur_level.push_back(cur_node->tree_node->val);
                    pre_level = cur_node->level;
                }

                if(cur_node->tree_node->left){
                    Node* left = new Node;
                    left->tree_node = cur_node->tree_node->left;
                    left->level = cur_node->level + 1;
                    q.push(left);
                }

                if(cur_node->tree_node->right){
                    Node* right = new Node;
                    right->tree_node = cur_node->tree_node->right;
                    right->level = cur_node->level + 1;
                    q.push(right);
                }

            }
        }    


        if(cur_level.size()){
            ret.push_back(cur_level);
        }    
        return ret;
    }
};