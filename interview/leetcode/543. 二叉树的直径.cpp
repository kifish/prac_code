/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 基于直觉的解法,应该有更优的解法
// 执行用时 :
// 64 ms
// , 在所有 C++ 提交中击败了
// 7.52%
// 的用户
// 内存消耗 :
// 20.6 MB
// , 在所有 C++ 提交中击败了
// 23.53%
// 的用户
// class Solution {
// public:

//     // cross or not cross
//     int max_len_of_tree_1(TreeNode* root){
//         if(root == nullptr){
//             return 0;
//         }
//         int max_len_2 = max_len_of_tree_2(root->left) + max_len_of_tree_2(root->right); //不应该在这里+2,而是需要在max_len_of_tree_2里+1
//         int len_left_1 = max_len_of_tree_1(root->left);
//         int len_right_1 = max_len_of_tree_1(root->right);
//         int max_len_1 = max(len_left_1,len_right_1);
//         return max(max_len_1,max_len_2);
//     }

//     // not cross
//     int max_len_of_tree_2(TreeNode* root){
//         if(root == nullptr){
//             return 0;
//         }
//         return max(max_len_of_tree_2(root->left),max_len_of_tree_2(root->right)) + 1;
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         return max_len_of_tree_1(root);
//     }
// };

// 参考官方题解:

// https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/shi-pin-jie-shi-di-gui-dai-ma-de-yun-xing-guo-chen/

// 把求最终答案当作一个副产物


// 执行用时 :
// 16 ms
// , 在所有 C++ 提交中击败了
// 59.39%
// 的用户
// 内存消耗 :
// 20.6 MB
// , 在所有 C++ 提交中击败了
// 23.53%
// 的用户

// 可以看到这个解法比第一个解法快了很多

class Solution {
public:

    int ret;
    int depth(TreeNode* root){ //depth求的不是边数,而是从这个root出发最多的节点数,包含root
        if(root == nullptr){
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);

        ret = max(ret,left + right);

        return max(left,right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ret = 0; // 需考虑root为null的情况
        depth(root);
        return ret;
    }
};