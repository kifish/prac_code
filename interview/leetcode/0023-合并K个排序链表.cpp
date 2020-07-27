
/*

https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1025/

https://leetcode-cn.com/problems/merge-k-sorted-lists/


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 分治加归并
// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists,int begin,int end){
//         if(begin > end) return NULL;
//         else if(begin == end) return lists[begin];
//         int mid = (begin + end) / 2;
//         ListNode* p1 = mergeKLists(lists,begin,mid);
//         ListNode* p2 = mergeKLists(lists,mid+1,end);
//         ListNode dummy_head = ListNode(0);
//         ListNode *cur = &dummy_head;
//         while(p1 && p2){
//             if(p1->val < p2->val){
//                 cur->next = p1;
//                 p1 = p1->next;
//             }
//             else{
//                 cur->next = p2;
//                 p2 = p2->next;
//             }
//             cur = cur->next;
//         }
//         if(p1) cur->next = p1;
//         else cur->next = p2;
//         return dummy_head.next;
//     }


//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         return mergeKLists(lists,0,(int)lists.size() -1);
//     }
// };

// 优先队列 + 贪心

// 这样求topk 是最优的

// 执行用时：
// 56 ms
// , 在所有 C++ 提交中击败了
// 43.04%
// 的用户
// 内存消耗：
// 11 MB
// , 在所有 C++ 提交中击败了
// 67.35%
// 的用户

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

    class Node
    {
    public:
        // 放public可以在外面直接用node.val访问
        int list_idx;
        int idx_in_the_list;
        int val;
        ListNode* listnode_ptr;
        Node(){}
        Node(int list_idx, int idx_in_the_list, int val, ListNode* listnode_ptr):list_idx(list_idx), idx_in_the_list(idx_in_the_list), val(val), listnode_ptr(listnode_ptr) {}
        bool operator < (const Node & x) const{
            return val > x.val; // 小顶堆
        }
    };
    
    priority_queue<Node> q;

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0;i<lists.size();i++){
            if(lists[i]){
                q.push(Node(0,0,lists[i]->val, lists[i]));
            }
        }
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur_node = dummy_head;
        while(!q.empty()){
            Node the_node = q.top();
            q.pop();
            cur_node->next = the_node.listnode_ptr;
            if(the_node.listnode_ptr->next){
                q.push(Node(the_node.list_idx, the_node.idx_in_the_list+1, the_node.listnode_ptr->next->val, the_node.listnode_ptr->next));
            }
            cur_node = cur_node->next;
        }
        return dummy_head->next;
    }
};

