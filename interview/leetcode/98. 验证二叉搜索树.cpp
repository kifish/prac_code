/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// WA 

// 输入:
// [10,5,15,null,null,6,20]
// 输出
// true
// 预期结果
// false


// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(root == nullptr){
//             return true;
//         }
        
//         bool ret = true;
//         if(root->left){
//             if(root->val > root->left->val){
//                 ret = ret && isValidBST(root->left);
//             }
//             else{
//                 ret = false;
//             }
//         }

//         if(!ret) return ret;

//         if(root->right){
//             if(root->val < root->right->val){
//                 ret = ret && isValidBST(root->right);
//             }
//             else{
//                 ret = false;
//             }
//         }
//         return ret;
//     }
// };




// 执行用时：
// 12 ms
// , 在所有 C++ 提交中击败了
// 92.37%
// 的用户
// 内存消耗：
// 18.3 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户



// class Solution {
// public:
//     vector<int> nums;
//     void print(vector<int> & nums){
//         for(auto num : nums){
//             cout<<num<<" ";
//         }
//         cout<<endl;
//     }
//     void inorder(TreeNode* root){
//         if(root == nullptr) return;

//         inorder(root->left);
//         nums.push_back(root->val);
//         inorder(root->right);
//     }
//     bool isValidBST(TreeNode* root) {
//         inorder(root);
//         // print(nums);
//         for(int i = 1;i<nums.size();i++){
//             if(nums[i] <= nums[i-1]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };


// 更快的方法
// https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode-solution/


// long long int 的最大值是LONG_MAX, 最小值是LONG_MIN



// [2147483647]
// 输出
// false
// 预期结果
// true



// class Solution {
// public:

//     bool is_valid(TreeNode* root, int low_bound, int up_bound){
//         if(root == nullptr) return true;

//         if(root->val <= low_bound || root->val >= up_bound){
//             return false;
//         }

//         return is_valid(root->left, low_bound, root->val) && is_valid(root->right, root->val, up_bound);
//     }
//     bool isValidBST(TreeNode* root) {
//         return is_valid(root, INT_MIN, INT_MAX);
//     }
// };




// 执行用时：
// 8 ms
// , 在所有 C++ 提交中击败了
// 99.03%
// 的用户
// 内存消耗：
// 18 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    #define LL long long

    bool is_valid(TreeNode* root, LL low_bound, LL up_bound){
        if(root == nullptr) return true;

        if(root->val <= low_bound || root->val >= up_bound){
            return false;
        }

        return is_valid(root->left, low_bound, root->val) && is_valid(root->right, root->val, up_bound);
    }
    bool isValidBST(TreeNode* root) {
        return is_valid(root, LONG_MIN, LONG_MAX);
    }
};
