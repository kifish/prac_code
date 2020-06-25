/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 执行用时 :
// 76 ms
// , 在所有 C++ 提交中击败了
// 49.27%
// 的用户
// 内存消耗 :
// 29.8 MB
// , 在所有 C++ 提交中击败了
// 8.33%
// 的用户


// class Solution {
// public:
//     ListNode* merge_sort(ListNode* head){
//         // 边界条件
//         if(head == nullptr || head->next == nullptr) return head;

//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         //找中点
//         while(fast && fast->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode* tmp = slow->next;
//         slow->next = nullptr;
//         ListNode* left_head = merge_sort(head);
//         ListNode* right_head = merge_sort(tmp);

//         ListNode* dummy_head = new ListNode;
//         ListNode* cur_node = dummy_head;
//         // dummy_head->next = head; // 可以去掉
//         while(left_head && right_head){
//             if(left_head->val < right_head->val){
//                 cur_node->next = left_head;
//                 cur_node = cur_node->next;
//                 left_head = left_head->next;
//             }
//             else{
//                 cur_node->next = right_head;
//                 cur_node = cur_node->next;
//                 right_head = right_head->next;
//             }
//         }
//         while(left_head) {
//             cur_node->next = left_head;
//             cur_node = cur_node->next;
//             left_head = left_head->next;
//         }
//         while(right_head){
//             cur_node->next = right_head;
//             cur_node = cur_node->next;
//             right_head = right_head->next;
//         }

//         return dummy_head->next;
//     }

//     ListNode* sortList(ListNode* head) {
//         return merge_sort(head);
//     }
// };

// https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/


// 优化

// 执行用时 :
// 72 ms
// , 在所有 C++ 提交中击败了
// 57.74%
// 的用户
// 内存消耗 :
// 29.7 MB
// , 在所有 C++ 提交中击败了
// 8.33%
// 的用户


class Solution {
public:
    ListNode* merge_sort(ListNode* head){
        // 边界条件
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        //找中点
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        ListNode* left_head = merge_sort(head);
        ListNode* right_head = merge_sort(tmp);

        ListNode* dummy_head = new ListNode;
        ListNode* cur_node = dummy_head;
        // dummy_head->next = head; // 可以去掉
        while(left_head && right_head){
            if(left_head->val < right_head->val){
                cur_node->next = left_head;
                cur_node = cur_node->next;
                left_head = left_head->next;
            }
            else{
                cur_node->next = right_head;
                cur_node = cur_node->next;
                right_head = right_head->next;
            }
        }
        if(left_head){
            cur_node->next = left_head;
        }
        else{
            cur_node->next = right_head;
        }

        return dummy_head->next;
    }

    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};


// 如果是要O(1)的空间则不能使用递归, 这个写起来比较麻烦之后复习下。