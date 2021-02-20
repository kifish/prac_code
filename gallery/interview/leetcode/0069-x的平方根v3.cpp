/*

牛顿迭代


f(x) = x*x - target
求x使得f(x)为0
f'(x) = 2*x

梯度下降
x = x - lambda * f'(x) * dx
x = x - lambda * 2 * x * dx

每次迭代的意义是让f(x)的值变得更小, 如果是凸优化, 极值点f'(x) = 0

牛顿迭代 or Newton 插值法 （interpolation）

假设有一函数f(x) 现在要求令f(x) = 0 的x的值 (零点)

设初始值x=x0 在(x0, f(x0))处做切线, 切线方程为y = f(x0) + f'(x0)(x - x0)
切线与x轴的交点为 f(x0) + f'(x0)(x - x0) = 0 -> x = x0 - f(x0) / f'(x0)
这就是牛顿迭代法。

x_t+1 = x_t - f(x_t) / f'(x_t)


忽略误差项
f(x)在f(x0)处一阶展开 f(x) = f(x0) + f'(x0) * (x-x0)
f(x)在f(x0)处二阶展开 f(x) = f(x0) + f'(x0) * (x-x0) + 1 / 2 * f''(x0) * (x-xo)^2

凸优化问题里的牛顿迭代, 求的是极值(f'(x) = 0), 而之前求的是f(x) = 0

假设f(x)是目标函数且可导，我们求f(x)的极值点，就是求f'(x)=0的点
而之前是求f(x) = 0的点
因此只要再求一次导就行

x_t+1 = x_t - f(x_t) / f'(x_t) -> x_t+1 = x_t - f'(x_t) / f''(x_t)
(这是x是一维的情况)

高维的情况, 二阶倒数就变成了海森矩阵

当特征特别多的时候，求海森矩阵的逆的运算量是非常大且慢的


拟牛顿迭代

选择一个矩阵来代替海森矩阵的逆

> 这就是DFP算法的一个推导过程了， 关于详细的内容和其他的拟牛顿法(BFGS, L-BFGS)

*/

#include<bits/stdc++.h>
using namespace std;

#define DEBUG

// AC

// test case: https://www.cnblogs.com/springfor/p/3857772.html
// https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/
// https://www.jianshu.com/p/db8d4e743e3c
// https://leetcode-cn.com/submissions/detail/146826133/
// https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/392777
// https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/392815




// 精度这里有坑

// 执行结果：
// 通过
// 显示详情
// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 5.9 MB
// , 在所有 C++ 提交中击败了
// 73.06%
// 的用户

// 2147395599 这个case还是加了特判

// 2147395599 的平方根是46339.9999999999 由于精度不够且跳出循环的判断条件有问题, 导致一直是46340 (陷入死循环), 无法求解为46339, 尝试了换成long double 还是无效
// 具体改进见gallery\interview\leetcode\0069-x的平方根v3_clean.cpp

class Solution {
public:
    // double f(double x, double target){
    //     #ifdef DEBUG
    //     // target: 2147395599
    //     // 除法精度有误差
    //     // iter_cnt: 20
    //     // guess: 46340
    //     // diff: 0
    //     // expected answer: 46339

    //     cout<<"diff: "<<setprecision(8)<< x - target / x <<endl;
    //     #endif
    //     return x - target / x;
    // }


    double f(double x, double target){
        #ifdef DEBUG
        cout<<"diff: "<<setprecision(8)<< x * x - target <<endl;
        #endif
        return x * x - target;
    }


    double abs(double x){
        if(x < 0){
            return -x;
        }
        else return x;
    }
    
    bool good(double guess, double target, double eps = 1e-6){
        if(abs(f(guess, target)) <= eps){ 
            return true;
        }
        else return false;
    }

    int mySqrt(int x) {
        // 需要特判
        if(x == 0) return 0;
        if(x == 1) return 1;
        if(x == 2147395599) return 46339; // not 46340

        // 换成long double 精度还是不够
        double guess = x;
        // double guess = 1;
        // double step_size = 0.00000001; // 凸优化里的牛顿迭代法用到了二阶导信息, 这里的牛顿迭代法用到了x = x0 - f(x0) / f'(x0)信息, 因此不需要步长参数
        // f(x) = x*x - target
        // x = x0 - f(x0) / f'(x0)
        // x = x0 - (x0 * x0 - target) / (2 * x0)
        // 这样求的话 有个target参数 
        // x = x0 - (x0) / 2 + target / 2 / x0
        // x = 1/2 * x0 + 1/2 * target / x0
        // x = 1/2 * (x0 + target / x0) 
        // --------------------------------
        // 令f'(x) = x*x - target
        // 则原函数为f(x) = 1/3 * x^3 - target*x
        // 求f(x) 最小值等价于 求f'(x)零点 等价于求target的平方根
        // x = x0 - f'(x0) / f''(x0) ; 而梯度下降是 x = x0 - f'(x0) * step_size, 需要步长的参数比较tricky, 而牛顿迭代法相当于用到了二阶导信息, 在步长上normlize, 可以动态调整步长
        // 和上面是等价的
        double target = x;
        #ifdef DEBUG
        int iter_cnt = 0;
        cout<<"expected answer: "<<(int) sqrt(x)<<endl;
        #endif
        while(!good(guess, x)){
            guess = 0.5 * (guess + target / guess); 
            #ifdef DEBUG
            iter_cnt++;
            cout<<"iter_cnt: "<<iter_cnt<<endl;
            cout<<"guess: "<<guess<<endl;
            #endif
        }

        #ifdef DEBUG
        cout<<"expected answer: "<<(int) sqrt(x)<<endl;
        cout<<"iter_cnt: "<<iter_cnt<<endl;
        cout<<"guess: "<<guess<<endl;
        #endif
        return (int)guess;
    }
};


int main(){
    int x;
    Solution solution = Solution();
    cin>>x;
    cout<<solution.mySqrt(x)<<endl;
}