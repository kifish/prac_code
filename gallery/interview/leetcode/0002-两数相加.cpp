
/*

https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1022/

https://leetcode-cn.com/problems/add-two-numbers/

*/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur_node_p = dummy_head;
        int sum =0, carry = 0;
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ListNode* new_node_p = new ListNode(sum % 10);
            cur_node_p->next = new_node_p;
            cur_node_p = cur_node_p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            sum = l1->val + carry;
            carry = sum / 10;
            ListNode* new_node_p = new ListNode(sum % 10);
            cur_node_p->next = new_node_p;
            cur_node_p = cur_node_p->next;
            l1 = l1->next;
        }
        while(l2){
            sum = l2->val + carry;
            carry = sum / 10;
            ListNode* new_node_p = new ListNode(sum % 10);
            cur_node_p->next = new_node_p;
            cur_node_p = cur_node_p->next;
            l2 = l2->next;
        }
        if(carry){
            ListNode* new_node_p = new ListNode(carry);
            cur_node_p->next = new_node_p;
            cur_node_p = cur_node_p->next; //safety; 不加这一行应该也没问题
        }
        return dummy_head->next;
    }
};