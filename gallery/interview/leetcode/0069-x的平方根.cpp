/*

相当经典的题目

https://leetcode-cn.com/explore/interview/card/bytedance/247/bonus/1045/

https://leetcode-cn.com/problems/sqrtx/


*/


// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x == 0) return 0;
//         if(x == 1) return 1;
//         int lo = 0,hi = x;
//         int mid;
//         while(lo<hi){
//             mid = (hi-lo)/2 + lo;
//             int tmp = x / mid;
//             int tmp2 = x / (mid + 1);
//             if(tmp == mid) return mid; // x == mid * mid
//             else if(tmp > mid && tmp2 < mid) return mid; // x > mid * mid && x < (mid + 1) * mid ; x < (mid + 1) * mid 这里卡的不是特别严, 如果最终答案是>= mid + 1, 那么tmp2一定>= mid + 1, 如果tmp2 < mid 说明最终答案一定< mid + 1, 配合前面的条件tmp > mid, 就可以直接返回mid了
//             else if(tmp < mid) hi = mid; // tmp 过小 -> mid 过大 -> 缩小hi; hi是取不到的上界; x < mid * mid
//             else lo = mid + 1; // lo可能会越过正确的解; 当因为lo == hi 退出循环, 而hi是取不到的上界, 因此lo-1是最终答案   // x >= (mid + 1)*mid
//         }
//         return lo-1;//IMPORTANT
//     }
// };

// mid == 2 x == 8


// (mid+dx)^2 = mid ^ 2 + dx ^ 2 + 2 dx * mid < mid^2 + 1 + 2 * mid



// https://leetcode-cn.com/explore/interview/card/bytedance/247/bonus/1045/


// WA

// INPUT 8
// 输出      1
// 预期      2

// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x == 0){
//             return 0;
//         }

//         if(x <= 3){
//             return 1;
//         }
//         if(x == 4){
//             return 2;
//         }

//         int lo = 1;
//         int hi = x / 2;
//         int ret = 1;
//         while(lo <= hi){
//             int mid = lo + (hi - lo) / 2;
//             if(mid * mid > x){
//                 hi = mid - 1;
//             }
//             else if(mid * mid < x){
//                 lo = mid + 1;
//             }
//             else{
//                 ret = mid;
//                 break;
//             } 
//         }
//         return ret;
//     }
// };



// 1017 / 1017 个通过测试用例
// 状态：通过
// 执行用时: 4 ms
// 内存消耗: 5.7 MB
// 提交时间：几秒前


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }

        if(x <= 3){
            return 1;
        }
        if(x == 4){
            return 2;
        }

        int lo = 1;
        int hi = x / 2;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(mid > x / mid){
                hi = mid - 1;
            }
            else if(mid < x / mid){
                lo = mid + 1;
            }
            else{
                return mid;
            } 
        }
        // 执行到这里说明 (发生过lo == hi的情形, 或者是 mid * mid > x, 导致hi最终是lo-1, 从而终止循环 或者是 mid * mid < x, 导致lo最终是hi+1, 从而终止循环) 或发生过lo = mid + 1 从而大于hi 或 ...
        if(lo > x / lo)
            return lo - 1;
        else return lo;
    }
};

// 上面的实现里还是要特判, 很不优雅


// 最上面的实现不需要特判, 用了2个变量来辅助判断, 有点tricky
