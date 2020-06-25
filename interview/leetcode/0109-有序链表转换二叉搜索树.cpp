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
//有序链表转换成的BST肯定是高度平衡的。
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {   
        if(head == nullptr) return nullptr;
        ListNode *dummy_start = new ListNode(0);
        dummy_start->next =  head;
        //快慢指针寻找中点
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slow_pre = dummy_start;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow_pre = slow;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        //从中点两边断开，分成2条独立的链表
        slow_pre->next = nullptr;
        root->left = sortedListToBST(dummy_start->next);//不能是head,考虑一个节点的情况。
        root->right = sortedListToBST(slow->next);
        return root;
    }
};