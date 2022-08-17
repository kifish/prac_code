/*

https://leetcode-cn.com/problems/reverse-linked-list/

https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1038/


gallery\interview\剑指offer\翻转链表.md

gallery\interview\剑指offer\剑指 Offer 24. 反转链表.cpp

*/

// AC

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
        if(head == nullptr){
            return head;
        }

        ListNode* prev_ptr = nullptr;
        ListNode* cur_ptr = head;
        ListNode* next_ptr = nullptr;
        while (cur_ptr){
            next_ptr = cur_ptr->next;
            cur_ptr->next = prev_ptr;
            prev_ptr = cur_ptr;
            cur_ptr = next_ptr;
        }
        return prev_ptr;
    }
};

