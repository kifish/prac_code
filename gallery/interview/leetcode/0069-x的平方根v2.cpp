/*

https://leetcode-cn.com/problems/sqrtx/comments/2683

https://leetcode-cn.com/problems/sqrtx/comments/387749


https://leetcode-cn.com/problems/sqrtx/solution/mei-ri-suan-fa-day-67-jing-dian-mian-shi-ti-shou-d/

梯度下降

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

每次迭代的意义是让f(x)的值变得更小, 如果是凸优化, 极值点f'(x) = 0

牛顿迭代

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

// 目前这样的实现里面 梯度下降 由于eps 和step size 的设定, 有时候会错过一些正确的解
// 例如 sqrt(2147395599) 就没法收敛
// step_size 要设定的非常小才行, 如果x原始就很大，则step size 较大则会导致求解错误
// step_size 太小则一定会超时
// 这里有一个trade off, 因此需要用牛顿迭代法
// 初始值 step_size eps 这三者要调整地比较合适才行


// TLE
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

    double f_v2(double x, double target){
        double diff = x * x - target;
        cout<<"diff: "<< diff <<endl;
        return diff;
    }

    double abs(double x){
        if(x < 0){
            return -x;
        }
        else return x;
    }

    bool good(double guess, double target, double eps = 0.2){
        // if(abs(f(guess, target)) <= eps){ // 这样算还是容易错过精确的解; 例如2147395599的平方根
        //     return true;
        // }

        if(abs(f_v2(guess, target)) <= 0.001){ 
            return true;
        }
        else return false;
    }
    
    int mySqrt(int x) {
        // 需要特判
        if(x == 0) return 0;
        if(x == 1) return 1;
        double guess = x;
        double step_size = 0.00000001;
        cout<<"expected answer: "<<(int) sqrt(x)<<endl;
        // return 0;
        while(!good(guess, x)){
            guess = guess - step_size * 2 * guess; // 这里的step size其实是公式里的lambda * dx; dx要够小, 迭代求解才会精确; step_size 是0.01容易错过精确的解
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