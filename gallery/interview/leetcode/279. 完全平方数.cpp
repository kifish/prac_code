
// slow
// 执行用时 :
// 472 ms
// , 在所有 C++ 提交中击败了
// 11.59%
// 的用户
// 内存消耗 :
// 6 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// class Solution {
// public:
//     int opt_cnt = 1 << 31 -1; // 1<<31是负数
//     void dfs(int cur_num, int cnt, int left){
//         if(left < 0 ) return;

//         if(left == 0){
//             if(cnt < opt_cnt){
//                 opt_cnt = cnt;
//             }
//             return;
//         }

//         if(cur_num <= 0) return;

//         if(cnt > opt_cnt) return;

//         dfs(cur_num, ++cnt, left-cur_num*cur_num);
//         cnt--;
//         dfs(cur_num-1,cnt,left);
//     }
//     int numSquares(int n) {
//         int start = (int) sqrt(n);
//         dfs(start, 0, n);
//         return opt_cnt;
//     }
// };

// 这道题的解法非常多
// https://leetcode-cn.com/problems/perfect-squares/solution/wan-quan-ping-fang-shu-by-leetcode/

// https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/

// 从小到大dp

// 执行用时 :
// 308 ms
// , 在所有 C++ 提交中击败了
// 26.54%
// 的用户
// 内存消耗 :
// 8.9 MB
// , 在所有 C++ 提交中击败了
// 88.46%
// 的用户

// 复杂度O(n*sqrt(n))
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int target = 1; target<=n;++target){
            dp[target] = target; // 最坏情况,全有1组成
            for(int last_num = 1; last_num*last_num <= target; ++last_num){
                dp[target] = min(dp[target], dp[target - last_num*last_num] + 1);
            }
        }
        return dp[n];
    }
};
