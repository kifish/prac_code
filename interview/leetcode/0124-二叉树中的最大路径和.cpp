/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* �����д������Ϊ����ʵ�ֵ�maxPathSum���ɰ���rootҲ�ɲ�����root�����³���
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
        return max(left_sum+right_sum+root->val,max(root->val,max(left_sum+root->val,max(right_sum+root->val,max(right_sum,left_sum)))));
    }
};
*/

class Solution
{
private:
    int max_path_sum = INT_MIN;
public:
    int maxPathSum(TreeNode *root)
    {
        max_path_sum_include(root);
        return max_path_sum;
    }

    int max_path_sum_include(TreeNode* root){ // �����õ��·���ͣ�������ͬʱ������������������
        if(!root) return 0;
        int left = max_path_sum_include(root->left);
        left = max(0,left); // 0�൱�ڲ�������������������
        int right = max_path_sum_include(root->right);
        right = max(0,right);
        max_path_sum = max(max_path_sum,root->val + left + right);
        return root->val + max(left,right);
    }
};