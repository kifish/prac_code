/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 执行用时：
// 12 ms
// , 在所有 C++ 提交中击败了
// 68.83%
// 的用户
// 内存消耗：
// 8.4 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == nullptr);

//         ListNode* pre = nullptr;
//         ListNode* cur = head;
//         ListNode* next = head;
//         while(next){ // 这种写法 while next 效果和 while cur 是一样的
//             next = cur->next;

//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//         return pre;
//     }
// };




// 执行用时：
// 16 ms
// , 在所有 C++ 提交中击败了
// 23.44%
// 的用户
// 内存消耗：
// 8.8 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 如果使用递归, 那么得有这2个边界情况的考虑, 既考虑0个节点, 也考虑1个节点
        if(head == nullptr) return nullptr; // 0
        if(head->next == nullptr){ // 1
            return head; // 这样递归到最后就会返回合法的head而不是nullptr
        }

        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};


// 这里的题解基本和我的思路一致: https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-yi-dong-de-shuang-zhi-zhen-jia/

