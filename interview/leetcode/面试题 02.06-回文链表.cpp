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
    // int get_len(ListNode* head){
    //     int len = 0;
    //     ListNode* curnode = head;
    //     while(curnode){
    //         len++;
    //         curnode = curnode->next;
    //     }
    //     return len;
    // }
    bool isPalindrome(ListNode* head) {
        // int len = get_len(head);
        // int p = len / 2;
        // int q = (len+1)/2 +1;
        if(!head || !head->next) return true;//0;1
        ListNode* pre = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* s = NULL;
        while(fast != NULL && fast->next != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = s;
            s = pre;//头插法
        }
        ListNode* tmp = slow;
        if(fast != NULL) tmp = tmp->next;//奇数个节点
        slow = pre;
        while(tmp){
            if(tmp->val != slow->val) return false;
            else{
                tmp = tmp->next;
                slow = slow->next;
            }
        }
        return true;
    }
};