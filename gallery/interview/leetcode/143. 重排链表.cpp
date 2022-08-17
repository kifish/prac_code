// https://leetcode-cn.com/problems/reorder-list/solution/2019tong-kao-408zhen-ti-jiao-ke-shu-shi-da-an-by-m/

// 上面一个url 是最优解法

// https://leetcode-cn.com/problems/reorder-list/solution/zi-jie-ti-ku-143-zhong-pai-lian-biao-1shua-by-supe/

// https://leetcode-cn.com/problems/reorder-list/comments/94192

// 这个解法简单, 但是用了O(n) 空间

// AC

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
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

    ListNode* partition(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        return slow;
    }

    void merge(ListNode* l1, ListNode* l2){
        ListNode* cur_ptr1 = l1;
        ListNode* cur_ptr2 = l2;
        ListNode* next_ptr1 = nullptr;
        ListNode* next_ptr2 = nullptr;
        while(cur_ptr2){
            next_ptr1 = cur_ptr1->next;
            cur_ptr1->next = cur_ptr2;
            next_ptr2 = cur_ptr2->next;
            cur_ptr2->next = next_ptr1;
            cur_ptr2 = next_ptr2;
            cur_ptr1 = next_ptr1;
        }
    }

    void reorderList(ListNode* head) {
        ListNode* mid = partition(head);
        ListNode* l2 = reverse(mid);
        merge(head, l2);
    }
};