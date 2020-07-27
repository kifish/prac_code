
/*

https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1024/

https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

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
// 多种方法，一种是构造环，一种是求长度提前走几步
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/lian-biao-xiang-jiao-shuang-zhi-zhen-onshi-jian-fu/
// 双指针也可以
// 记录步数, 算出长度差, 然后重新开始遍历, 先让一个节点提前走几步即可
// 更优的方法
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/intersection-of-two-linked-lists-shuang-zhi-zhen-l/
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