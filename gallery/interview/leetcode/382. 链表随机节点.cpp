/*

https://leetcode-cn.com/problems/linked-list-random-node/

https://leetcode-cn.com/problems/linked-list-random-node/solution/monkti-jie-yong-zui-shao-de-yu-yan-he-da-zno0/

蓄水池抽样算法

https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/




algs4

*/

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
    ListNode* m_head;
public:
    Solution(ListNode* head) {
        m_head = head;
    }

    int getRandom() {
        ListNode* cur = m_head;
        int ret = cur->val;
        cur = cur->next;
        int idx = 1;
        while(cur){
            int rand_num = rand() % (idx + 1);
            if(rand_num == idx){
                ret = cur->val;
            }
            cur = cur->next;
            idx++;
        }
        return ret;
    }
};
