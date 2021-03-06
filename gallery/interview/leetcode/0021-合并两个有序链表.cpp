
/*

https://leetcode-cn.com/problems/merge-two-sorted-lists/

https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1048/


*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy_head(0);
        ListNode* cur = &dummy_head;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        else cur->next = l2;
        return dummy_head.next;
    }
};