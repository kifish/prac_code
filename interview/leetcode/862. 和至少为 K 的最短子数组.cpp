
/*
滑动窗口解决不了 （滑动窗口能解决的是非负整数组, 如果出现负数, 左端点可以往左边后退）

下面来说说, 为啥不行, 收缩窗口的时候 while(window_sum >= target ){//计算窗口长度; left++;window_sum -= nums[i];}
但是这样的问题是并不是说left往右移就能让这个循环终止(准确地说left的可信区间并不是连续的, 循环即使结束了, left 再往右移动也是有可能让窗口符合条件的,
这就导致了提前终止循环可能会漏掉 可行解)


https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/comments/120984

如果题目没有负权的话，这就纯粹是一个时间复杂度为N的题目。
从左右一端出发，累加(反正是递增数列)，如果找到满足的数列后，成为一个滚动数组，
不同的从右侧向左侧挪动， while (sum - A[begin] >= K || A[begin] <= 0) sum -= A[begin++];
 但是题目中存在负权，如果要解决负权问题，就需要确定入口点从右侧或者从左侧作为入口将负权消灭掉。 
比如 6 -1 -1 -1 -1 可以看作 2 0 0 0 0这是从左侧当作输入口，之后转化为第一类问题。


想想暴力的方法, O(N^3) 通过前缀和可以优化到O(N^2), 再通过二分可以优化到O(N*logN)? 但是有负值, 前缀和并不是单调递增的, 没法直接二分.


https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/solution/bian-li-hua-jian-by-yu-jie-15/


可以看看这个:
https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/solution/wei-shi-yao-yao-shi-yong-dan-diao-zhan-by-user5707/


单调队列
https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/solution/cyu-yan-jie-ti-si-kao-guo-cheng-by-w00469410/


cur - pre >= K 即 cur - K >= pre。由于1 <= K <= 10 ^ 9，那么pre必然是比cur小的数。

也就是说可行的解必然是 pre < cur
换句话说这个栈必须单增, 问, 如果 cur 比 pre 小咋办, 那就是说cur必然不会和pre组成可行解, 那就把cur直接去掉即可。
问, cur 能否和前前前面的元素组成可行解, 可能可以吧, 但是, cur必然没有pre更优, 如果cur可以, 那么pre一定可以且更优, 也就可以扔掉cur.

但是实际实现的时候代码逻辑还得再变一变

*/

class Solution {
public:
    struct Node
    {
        int pre_sum; // 包含nums[index]
        int index;
        Node(){}
        Node(int pre_sum, int index):pre_sum(pre_sum), index(index){}
    };

    // [2,-1,2]
    // 3
    // 这一版实现的二分有问题, 
    // int binary_search(vector<Node> & stack, int target){
    //     if(stack.size() == 0) return -1;
    //     int lo = 0;
    //     int hi = stack.size() - 1;
    //     while(lo < hi){ // 加入lo=7, hi = 8, 且mid对应元素正好符合target, 那么会死循环
    //         int mid = (lo + hi) / 2; // 原因是这个版本是让hi = mid -1的, 而不是让lo = mid + 1; 要注意一点, 这里的mid 永远 < hi
    //         if(stack[mid].pre_sum == target){ // 分支可以合并
    //             lo = mid;
    //         }
    //         else if(stack[mid].pre_sum > target){
    //             hi = mid - 1;
    //         }
    //         else{ // stack[mid].pre_sum < target
    //             lo = mid;
    //         }
    //     }

    //     if(stack[lo].pre_sum <= target){
    //         return lo;
    //     }
    //     else return -1;
    // }

    // 执行用时：
    // 348 ms
    // , 在所有 C++ 提交中击败了
    // 26.00%
    // 的用户
    // 内存消耗：
    // 59.9 MB
    // , 在所有 C++ 提交中击败了
    // 100.00%
    // 的用户
    // int binary_search(vector<Node> & stack, int target){
    //     if(stack.size() == 0) return -1;
    //     int lo = 0;
    //     int hi = stack.size() - 1;
    //     // stack[lo-hi] 里的pre.sum 都<= target, 区间左右两端都闭
    //     do{ // 假如lo=7, hi = 8, 且mid对应元素正好符合target, 那么会死循环
    //         int mid = (lo + hi) / 2; // 原因是这个版本是让hi = mid -1的, 而不是让lo = mid + 1; 要注意一点, 这里的mid 永远 < hi
    //         if(stack[mid].pre_sum == target){ // 分支可以合并
    //             lo = mid;
    //         }
    //         else if(stack[mid].pre_sum > target){
    //             hi = mid - 1;
    //         }
    //         else{ // stack[mid].pre_sum < target
    //             lo = mid;
    //         }
    //     }while(hi - lo > 1); // 如果区间长度为1, 那么肯定已经找到解或者无解了, 也就是说没必要缩小范围了

    //     // 如果只有一个元素, lo初始化为0, hi初始化为0, hi结束的时候有可能是-1
    //     if(hi >= 0 && stack[hi].pre_sum <= target){
    //         return hi;
    //     }
    //     else if(stack[lo].pre_sum <= target){
    //         return lo;
    //     }
    //     else return -1;
    // }

    // 上面这个二分虽然对了, 但是不够优雅
    // 执行用时：
    // 360 ms
    // , 在所有 C++ 提交中击败了
    // 23.76%
    // 的用户
    // 内存消耗：
    // 60 MB
    // , 在所有 C++ 提交中击败了
    // 100.00%
    // 的用户
    // 求最大的index, 且该index对应的元素满足 <= target
     int binary_search(vector<Node> & stack, int target){
        if(stack.size() == 0) return -1;
        int lo = 0;
        int hi = stack.size() - 1;
        while(lo < hi){ // 加入lo=7, hi = 8, 且mid对应元素正好符合target, 那么会死循环
            int mid = (lo + hi + 1) / 2; // 原因是这个版本是让hi = mid -1的, 而不是让lo = mid + 1; 要注意一点, 这里的mid 永远 < hi; 所以改进的方法就是mid = (lo + hi + 1) / 2, 让mid永远> lo
            if(stack[mid].pre_sum == target){ // 分支可以合并
                lo = mid;
            }
            else if(stack[mid].pre_sum > target){
                hi = mid - 1;
            }
            else{ // stack[mid].pre_sum < target
                lo = mid;
            }
        }

        if(stack[lo].pre_sum <= target){
            return lo;
        }
        else return -1;
    }   

    int shortestSubarray(vector<int>& A, int K) {
        int pre_sum = 0;
        vector<Node> stack;
        stack.push_back(Node(pre_sum,-1)); // 处理边界情况, 第一个元素自己组成最短子数组

        int ret = INT_MAX;
        for(int i = 0;i<A.size();i++){
            pre_sum += A[i]; // cur_sum
            while(!stack.empty() && stack.back().pre_sum >= pre_sum){
                stack.pop_back(); // 如果以cur_sum作为右边界, 则弹出的元素是不可能作为左边界的
            }
            // 以cur_sum 作为右边界
            // 然后二分查找左边界
            // cur_sum - pre_sum >= K
            // pre_sum <= cur_sum - K
            // pre_sum <= target
            int target = pre_sum - K;
            int left_node_idx = binary_search(stack, target);
            if(left_node_idx != -1){ // 找到可行的左边界
                int len = i - stack[left_node_idx].index;
                ret = min(ret, len);
                if(ret == 1) break; // 优化
            }
            stack.push_back(Node(pre_sum, i));
        }

        if(ret == INT_MAX){
            return -1;
        }
        else return ret;
    }
};