/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
//��������ת���ɵ�BST�϶��Ǹ߶�ƽ��ġ�
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {   
        if(head == nullptr) return nullptr;
        ListNode *dummy_start = new ListNode(0);
        dummy_start->next =  head;
        //����ָ��Ѱ���е�
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slow_pre = dummy_start;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow_pre = slow;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        //���е����߶Ͽ����ֳ�2������������
        slow_pre->next = nullptr;
        root->left = sortedListToBST(dummy_start->next);//������head,����һ���ڵ�������
        root->right = sortedListToBST(slow->next);
        return root;
    }
};