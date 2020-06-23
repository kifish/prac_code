// 暴力的办法, 优先队列

// 这样写有2个问题, 优先队列的 比较函数没法这样实现, 其次直接用堆的api可能更好, 每次窗口变化进行堆调整, 目前的写法能否正确的堆调整呢? 
// stl的优先队列没有删除的api

// class Solution {
// public:

//     vector<int> in_window = vector<int> (1e5, 0);
//     struct Node
//     {
//         int idx;
//         int val;
//         Node(int x,int y): idx(x), val(y){}

//         bool operator < (const Node & x) const{
//             if(in_window[idx] != in_window[x.idx]){
//                 return in_window[idx] < in_window[x.idx];
//             }
//             else{
//                 return val < x.val;
//             }
//         }
//     };
    
//     priority_queue<Node> q;
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         in_window = vector<int> (nums.size(), 0);
//         vector<int> ret;
//         int right = 0, left = 0;
//         while(k--){
//             in_window[right] = 1;
//             q.push(Node(right,nums[right]));
//             right++;
//         }
//         ret.push_back(q.front().val);

//         for(; right < nums.size();right++){
//             in_window[right] = 1;
//             in_window[left] = 0;
//             q.push(Node(right,nums[right]));
//             ret.push_back(q.front().val);
//         }
//         return ret;
//     }
// };


/*

https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/




https://en.cppreference.com/w/cpp/container/deque


https://leetcode-cn.com/problems/sliding-window-maximum/solution/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-z/379631

*/


// 执行用时：
// 104 ms
// , 在所有 C++ 提交中击败了
// 31.25%
// 的用户
// 内存消耗：
// 28.3 MB
// , 在所有 C++ 提交中击败了
// 5.88%
// 的用户


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        // front ... back
        // 按从大到小排序
        vector<int> res;
        if(k == 0) return res;
        // 常规思路, 加入right对应的元素然后删除left对应的元素, 但是left对应的元素在dq中哪个位置? 这个不知道。
        // 因此换个思路

        int right = 0;
        // 注意这不是插入排序, 最终的复杂度还是O(n)的, 因为在不停的删除元素
        while(right < nums.size()){
            int cur_num = nums[right];
            while (!dq.empty() && nums[dq.back()] <= cur_num)
            {
                dq.pop_back(); // 如果一个数出现的比当前数早且还不比当前数大, 那么这个数之后不可能成为窗口中最大的数
            }
            dq.push_back(right);
            
            if(right - k + 1 >= 0){
                // 合法的元素的index范围为[right-k+1, right]
                while(dq.front() < right - k + 1){ // 似乎这里用if也行?
                    dq.pop_front();
                }
                res.push_back(nums[dq.front()]);
            }

            right++;
        }
        return res;
    }
};


// dp方法可以看看这个: 
// https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/