/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (node == nullptr)
            return;
        ListNode* to_be_deleted = node->next;
        node->val = to_be_deleted->val;
        node->next = to_be_deleted->next;
        delete to_be_deleted;
    }
};