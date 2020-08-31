/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 6.4 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

// 利用dummy head 可以更简洁

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;

        while(n--){
            fast =  fast->next;
        }
        while(fast){
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        if(pre == nullptr){ // 说明要删除的是头结点 
            bool only_one = false;
            if(head->next == nullptr){
                only_one = true; // 长度为1
            }
            ListNode* ret = slow->next;
            head->next == nullptr;
            delete head;
            // WA
            // if(slow) // 说明链表长度为1且n==1; if slow 并不能判断链表长度为1, 所指向的位置已经被是否, 但是slow里面存的地址的值并不是0
            //     return slow->next;
            // else 
            //     return nullptr;

            // WA 不只是要考虑链表长度为1的情况, 实际上只是要考虑删除头结点怎么处理
            // if(only_one){
            //     return nullptr;
            // }
            // else{
            //     return slow->next;
            // }
            return ret;
        }
        else{
            pre->next = slow->next;
            // cout<<"slow : "<<slow->val<<endl;
            slow->next = nullptr;
            delete slow;
            return head;
        }
    }
};

