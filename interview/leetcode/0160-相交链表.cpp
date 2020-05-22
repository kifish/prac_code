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
//多种方法，一种是构造环，一种是求长度提前走几步
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {   
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* last = headB;
        while(last->next){
            last = last->next;
        }
        last->next = headB;
        ListNode *fast = headA,*slow = headA;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                fast = headA;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                last->next = NULL;
                return fast;
            }
        }
        last->next = NULL;
        return NULL;
    }
};