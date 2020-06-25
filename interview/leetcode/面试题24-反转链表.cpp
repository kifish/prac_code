/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* s = NULL;
        ListNode* pre = NULL;
        ListNode* curnode = head;
        while(curnode){
            s = curnode;
            curnode = curnode->next;
            s->next = pre;
            pre = s;
        }
        return s;
    }
};