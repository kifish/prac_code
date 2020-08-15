
/*

https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-19/

https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-19/

官方写的是比较优雅的


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 执行用时：
// 4 ms
// , 在所有 C++ 提交中击败了
// 65.26%
// 的用户
// 内存消耗：
// 6.4 MB
// , 在所有 C++ 提交中击败了
// 75.98%
// 的用户

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* pre = dummy_head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* left = head->next->next;
        while (second){
            first->next = left;
            second->next = first;
            pre->next = second;

            swap(first, second);

            if(left){
                left = left->next;
            }

            if(left){
                left = left->next;
            }

            if(second){
                second = second->next;
            }
            if(second){
                second = second->next;
            }

            if(first){
                first = first->next;
            }
            if(first){
                first = first->next;
            }

            pre = pre->next->next;
        }
        

        return dummy_head->next;
    }
};