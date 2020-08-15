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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n == 1 || m == n) return head;
        int i = 1;
        ListNode* curnode = head;
        ListNode* p = NULL;
        ListNode* pre = NULL;
        ListNode* s = NULL;
        bool flag = false;
        while(i<m){
            p = curnode;
            curnode = curnode->next;
            i++;
            if(!flag)
                flag = true;
        }
        ListNode* q = NULL;
        if(flag)
            q = curnode;
        else if(m == 1) q = head;
        bool flag2 = false;
        while(i<=n){
            pre = curnode;
            if(curnode->next)
                curnode = curnode->next;
            else
                flag2 = true;
            pre->next = s;
            s = pre;
            i++;
        }
        if((flag || m == 1) && !flag2)
            q->next = curnode;
        if(p)
            p->next = s;
        if(m == 1) return s;
        else return head;
    }
};