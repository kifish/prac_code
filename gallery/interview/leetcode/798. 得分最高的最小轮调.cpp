
// https://leetcode-cn.com/problems/smallest-rotation-with-highest-score/solution/c-qu-jian-qu-zui-da-zhong-he-dian-by-da-li-wang/


// 找规律
// n = 5
// k = 2
// a[2] a[3] a[4] a[0] a[1]
// k = 3
// a[3] a[4] a[0] a[1] a[2]
// k = 4
// a[4] a[0] a[1] a[2] a[3]
// k = 5
// a[0] a[1] a[2] a[3] a[4]
// k == n的时候 数组不变, 可以不用考虑
// k < n 的时候k每增大一个单位, 数组则往左移动一个单位


// 执行用时：
// 48 ms
// , 在所有 C++ 提交中击败了
// 82.43%
// 的用户
// 内存消耗：
// 18.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        vector<int> buf(n,0);
        // vector<pair<int,int>> valid_intervals;
        // k只可能是0,1,2,...,n-1中的一个
        for(int i = 0;i<A.size();i++){
            int right_idx_limit = A[i];
            // A[i] <= the final index : points + 1
            // 如果A[i] 最终的位置的index >= A[i] 则加一分
            // 把A[i]放在right_idx_limit及之后即可
            // 每个数都有他对应的安全区间
            // 处于这个安全区间, 则可以得分
            // 现在就是求所有的安全区间重叠了几次
            // 不一定要显性地求出安全区间再算重叠次数
            // k 增大一个单位, 则数组整体往左移动一个单位
            int left_k_for_the_num = ((A[i] -i) * -1 + n) % n;  // 如果不考虑跨边界, 这里的k较大
            int right_k_for_the_num = ((n-1- i) * -1 + n) % n; // (i+1) % n // 如果不考虑跨边界, 这里的k较小
            // 这2个数不一定是left >= right
            // k的这个得分区间是连续的, 但是可能是跨边界的
            // 也可以认为在区间left_k_for_the_num起点处开始得分
            // 区间中部不得分
            // 在区间末端的右边一个位置扣分
            // buf[k]
            // +n   %n 这2个操作组合起来是为了处理跨边界的情况
            int end_idx_plus_one = (left_k_for_the_num + 1 + n) % n; // k再大一个单位, 就脱离了安全区间
            buf[right_k_for_the_num]++;
            buf[end_idx_plus_one]--;            
        }
        int cur_score = 0;// cur_score实际上应该是该数组的初始得分, 但是这里写0也不影响结果的求解
        int max_k;
        int max_score = INT_MIN;
        for(int k = 0;k<n;k++){
            cur_score += buf[k];
            if(cur_score > max_score){
                max_k = k;
                max_score = cur_score;
            }
        }
        return max_k;
    }
};