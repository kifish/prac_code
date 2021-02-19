/*

相当经典的题目

https://leetcode-cn.com/explore/interview/card/bytedance/247/bonus/1045/

https://leetcode-cn.com/problems/sqrtx/



二分 or 梯度下降

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
//         while(lo < hi){
//             int mid = lo + (hi - lo) / 2;
//             if(mid > x / mid){
//                 hi = mid - 1;
//             }
//             else if(mid < x / mid){
//                 lo = mid + 1;
//             }
//             else{
//                 return mid;
//             } 
//         }
//         // 执行到这里说明 (发生过lo == hi的情形, 或者是 mid * mid > x, 导致hi最终是lo-1, 从而终止循环 或者是 mid * mid < x, 导致lo最终是hi+1, 从而终止循环) 或发生过lo = mid + 1 从而大于hi 或 ...
//         if(lo > x / lo)
//             return lo - 1;
//         else return lo;
//     }
// };

// 上面的实现里还是要特判, 很不优雅


// 最上面的实现不需要特判, 用了2个变量来辅助判断, 有点tricky


/*

class Solution {
public:

    // double f(double x, double target){
    //     cout<<"diff: "<< x*x - target<<endl;
    //     return x*x - target;
    // }

    double f(double x, double target){
        cout<<"diff: "<< x - target / x <<endl;
        return x - target / x;
    }


    double abs(double x){
        if(x < 0){
            return -x;
        }
        else return x;
    }

    bool good(double guess, double target, double eps = 1){
        if(abs(f(guess, target)) <= eps){
            return true;
        }
        else return false;
    }

    int mySqrt(int x) {
        // 需要特判
        if(x == 0) return 0;
        if(x == 1) return 1;
        double guess = x;
        double step_size = 0.01;
        while(!good(guess, x)){
            guess = guess - step_size * 2 * guess;
            cout<<guess<<endl;
        }
        return (int)guess;
    }
};




/*

f(x) = x*x - target
求x使得f(x)为0
f'(x) = 2*x

梯度下降

x = x - lambda * f'(x) * dx
x = x - lambda * 2 * x * dx

牛顿迭代

x = x - lambda * f'(x) / f''(x) * dx
x = x - lambda * 2 * x / x * dx
x = x - lambda * 2 * dx




(x+1)^2 - x*2 = 2x + 1


https://leetcode-cn.com/problems/sqrtx/solution/mei-ri-suan-fa-day-67-jing-dian-mian-shi-ti-shou-d/



*/

#include<bits/stdc++.h>
using namespace std;


/*

f(x) = x*x - target
求x使得f(x)为0
f'(x) = 2*x

梯度下降

x = x - lambda * f'(x) * dx
x = x - lambda * 2 * x * dx

牛顿迭代

x = x - lambda * f'(x) / f''(x) * dx
x = x - lambda * 2 * x / x * dx
x = x - lambda * 2 * dx




(x+1)^2 - x*2 = 2x + 1


https://leetcode-cn.com/problems/sqrtx/solution/mei-ri-suan-fa-day-67-jing-dian-mian-shi-ti-shou-d/

*/

// 目前这样的实现里面 梯度下降 由于eps 设定为0.01, 有时候会错过一些正确的解

// 例如 sqrt(4) 就没法收敛
class Solution {
public:

    // double f(double x, double target){
    //     cout<<"diff: "<< x*x - target<<endl;
    //     return x*x - target;
    // }

    double f(double x, double target){
        cout<<"diff: "<< x - target / x <<endl;
        return x - target / x;
    }


    double abs(double x){
        if(x < 0){
            return -x;
        }
        else return x;
    }

    bool good(double guess, double target, double eps = 0.01){
        if(abs(f(guess, target)) <= eps){
            return true;
        }
        else return false;
    }

    int mySqrt(int x) {
        // 需要特判
        if(x == 0) return 0;
        if(x == 1) return 1;
        double guess = x;
        double step_size = 0.01;
        while(!good(guess, x)){
            guess = guess - step_size * 2 * guess; 
            // 显然这里迭代没有用到target 信息, 迭代速度在target较大的情况下自然很慢
            // 为啥这里的梯度下降求解在x较大的情况下收敛很慢且容易出现求解错误? 想象一下y = x^2 和 y = target 这2条曲线相交的情形, x从初始值target一直在减少, 但如果target很大, 则2条曲线相交处 y= x^2 的梯度很大, 导致很容易错过精确解, 错过该解之后, x持续下降, 则无法再找到精确解
            cout<<guess<<endl;
        }
        cout<<"expected answer: "<<(int) sqrt(x)<<endl;
        return (int)guess;
    }
};


int main(){

    int x;
    Solution solution = Solution();
    cin>>x;
    cout<<solution.mySqrt(x)<<endl;

}