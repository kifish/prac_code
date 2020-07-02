


/*
https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution-2/



https://leetcode-cn.com/problems/super-egg-drop/solution/887-by-ikaruga/
这个url直接看代码来理解吧。有点像刘汝佳那本算法书里的一道题f(x)



*/


// 执行用时：
// 4 ms
// , 在所有 C++ 提交中击败了
// 86.90%
// 的用户
// 内存消耗：
// 5.8 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


// class Solution {
// public:
//     // memo todo

//     //消耗了K个鸡蛋和T次机会, 可以知道鸡蛋在不同的楼层的是否会碎的情况
//     // 例如知道了在[0,1,2,3] 层不会碎, 在第4层会碎, 那么则知道了5个楼层的情况
//     int possible_f_cnt(int K,int T){
//         // 只有一个蛋
//         if(K == 1) {
//             return T+1; // 例如在一共3次机会, [1,2,3] 扔了鸡蛋, 在第三层碎了, 则知道了[0,1,2,3]的情况
//         }
//         // 只有一次机会
//         if(T == 1){
//             return T+1; // 2
//         }

//         return possible_f_cnt(K-1, T-1) + possible_f_cnt(K, T-1);
//     }


//     int superEggDrop(int K, int N) {
//         int T = 1; // 至少要1次机会(次数)
//         // 显然这里可以用二分优化
//         // lo = 1, hi = N;
//         while (possible_f_cnt(K, T) < N+1) // 为什么是N+1,因为可能的楼层数是[0,...,N]
//         {
//             T++; //说明当前的T次数还太少, 不符合条件
//         }
//         // 找到符合条件的T
//         return T;
//     }
// };




// TLE

// input:
// 10
// 100

// 加二分反而慢了, 因为一开始算possible_f_cnt(10,50) 
// 需要算好久

// 而前一种算法是T逐渐增大



// class Solution {
// public:
//     // memo todo

//     //消耗了K个鸡蛋和T次机会, 可以知道鸡蛋在不同的楼层的是否会碎的情况
//     // 例如知道了在[0,1,2,3] 层不会碎, 在第4层会碎, 那么则知道了5个楼层的情况
//     int possible_f_cnt(int K,int T){
//         // 只有一个蛋
//         if(K == 1) {
//             return T+1; // 例如在一共3次机会, [1,2,3] 扔了鸡蛋, 在第三层碎了, 则知道了[0,1,2,3]的情况
//         }
//         // 只有一次机会
//         if(T == 1){
//             return T+1; // 2
//         }

//         return possible_f_cnt(K-1, T-1) + possible_f_cnt(K, T-1);
//     }

//     int superEggDrop(int K, int N) {
//         // 显然这里可以用二分优化
//         int lo = 1, hi = N;
//         int target = N + 1;
//         while(lo < hi){
//             int mid = (lo + hi) / 2;
//             if(possible_f_cnt(K, mid) == target){
//                 return mid;
//             }
//             else if(possible_f_cnt(K,mid) < target){
//                 lo = mid +1; // 有效范围在[mid+1, hi]
//             }
//             else{
//                 hi = mid; // mid是符合条件的, 有效范围在[lo, mid]
//             }
//         }
//         // 找到符合条件的T
//         return hi;
//     }
// };



// https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-xiang-jie-by-shellbye/

// input:
// 10
// 100
// runtime error: signed integer overflow: 465174935 + 2142281575 cannot be represented in type 'int' (solution.cpp)

// 这道题不能用二分
// class Solution {
// public:
//     // memo todo
//     // unordered_map<vector<int>, int> M; // 无法编译; hash不支持这么写
//     map<vector<int>, int> M;

//     //消耗了K个鸡蛋和T次机会, 可以知道鸡蛋在不同的楼层的是否会碎的情况
//     // 例如知道了在[0,1,2,3] 层不会碎, 在第4层会碎, 那么则知道了5个楼层的情况
//     int possible_f_cnt(int K,int T){
//         if(M.count({K,T})){
//             return M[{K,T}];
//         }

//         // 只有一个蛋
//         if(K == 1) {
//             M[{K,T}] = T+1;
//             return T+1; // 例如在一共3次机会, [1,2,3] 扔了鸡蛋, 在第三层碎了, 则知道了[0,1,2,3]的情况
//         }
//         // 只有一次机会
//         if(T == 1){
//             M[{K,T}] = T+1;
//             return T+1; // 2
//         }

//         M[{K,T}] =possible_f_cnt(K-1, T-1) + possible_f_cnt(K, T-1);
//         return M[{K,T}];
//     }

//     int superEggDrop(int K, int N) {
//         // 显然这里可以用二分优化
//         int lo = 1, hi = N;
//         int target = N + 1;
//         while(lo < hi){
//             int mid = (lo + hi) / 2;
//             if(possible_f_cnt(K, mid) == target){
//                 return mid;
//             }
//             else if(possible_f_cnt(K,mid) < target){
//                 lo = mid +1; // 有效范围在[mid+1, hi]
//             }
//             else{
//                 hi = mid; // mid是符合条件的, 有效范围在[lo, mid]
//             }
//         }
//         // 找到符合条件的T
//         return hi;
//     }
// };




// https://leetcode-cn.com/problems/super-egg-drop/comments/341222

// java
// class Solution {
//     public int superEggDrop(int K, int N) {
//         int[][] dp = new int[K + 1][N + 1]; 
//         for (int n = 1; n <= N; n++) {
//             dp[1][n] = n; // 一个鸡蛋, 那么只能逐层扔
//         }
//         for (int k = 2; k <= K; k++) {
//             for (int n = 1; n <= N; n++) {
//                 // dp[k][n] 表示k个鸡蛋、0-n层时的最小移动次数。(最坏情况下的最小移动次数)
//                 // 即 dp[k][n] = min(1 + Math.max( dp[k][n - i], dp[k - 1][i - 1] )); 1 <= i <= n。
                   // 从dp[k - 1][i - 1]转移过来说明第k个蛋正好在i层的时候碎了, 那么探测区间里去掉i. (因为我们此时还未确定扔蛋的顺序策略, 因此并不能确定答案就是i)
                   // 从dp[k][n - i]转移过来说明第k个蛋未碎, 那么只可能在剩下的楼层中碎
                   // 注意这里的相对的概念, 例如目前探测的答案区间是[6,7,8,9]
                   // 第6层未碎, 则只可能在7,8,9里碎掉,问题其实可以划归成[1,2,3]
                   // 这里有个前提, 鸡蛋在每层碎的概率都是相等的
                   // 本来是三重循环, 利用二分加速
//                 // i 增大，dp[k][n - i]减小，dp[k - 1][i - 1]增大。
//                 // 于是找到第 1 个 i 使得 dp[k][n - i] <= dp[k - 1][i - 1]。
//                 int lo = 1, hi = n, mid = 0;
//                 while (lo + 1 < hi) { // 其实这个判断可以优化
//                     mid = (lo + hi) >> 1; // / 2
//                     if (dp[k][n - mid] < dp[k - 1][mid - 1]) { // f(mid) < target
//                         hi = mid;
//                     } else if (dp[k][n - mid] > dp[k - 1][mid - 1]) { // f(mid) > target
//                         lo = mid;
//                     } else {
//                         lo = hi = mid;
//                     }
//                 }
//                 dp[k][n] = 1 + dp[k][n - lo]; // 找到了交叉点, 想象一下一条上升的线和一条下降的线交叉, 然后先取max再取min
//             }
//         }
//         return dp[K][N];
//     }
// }

