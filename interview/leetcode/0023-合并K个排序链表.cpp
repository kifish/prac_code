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
    ListNode *mergeKLists(vector<ListNode *> &lists,int begin,int end){
        if(begin > end) return NULL;
        else if(begin == end) return lists[begin];
        int mid = (begin + end) / 2;
        ListNode* p1 = mergeKLists(lists,begin,mid);
        ListNode* p2 = mergeKLists(lists,mid+1,end);
        ListNode dummy_head = ListNode(0);
        ListNode *cur = &dummy_head;
        while(p1 && p2){
            if(p1->val < p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(p1) cur->next = p1;
        else cur->next = p2;
        return dummy_head.next;
    }


    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return mergeKLists(lists,0,(int)lists.size() -1);
    }
};