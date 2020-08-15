/*

https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1023/

https://leetcode-cn.com/problems/linked-list-cycle-ii/


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode/

// 对于步骤二fast和slow分别从相遇结点和头结点同时同步长走，他们的相遇结点就是入环结点。
// 我是这样理解的：首先，头结点到入环结点的距离为a，入环结点到相遇结点的距离为b，
// 相遇结点到入环结点的距离为c。
// 然后，当f以s的两倍速度前进并和s相遇时，f走过的距离是s的两倍，
// 即有等式：a+b+c+b = 2(a+b) ，可以得出 a = c ，
// 所以说，让fast和slow分别从相遇结点和头结点同时同步长出发，他们的相遇结点就是入环结点。


// 执行用时 :
// 12 ms
// , 在所有 C++ 提交中击败了
// 73.18%
// 的用户
// 内存消耗 :
// 7.7 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }

        bool has_circle = false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                has_circle = true;
                break;
            }
        }

        ListNode* across_node = head;
        if(has_circle){
            while(across_node != slow){
                slow = slow->next;
                across_node = across_node->next;
            }
        }

        if(has_circle){
            return across_node;
        }
        else{
            return nullptr;
        }
    }
};


 