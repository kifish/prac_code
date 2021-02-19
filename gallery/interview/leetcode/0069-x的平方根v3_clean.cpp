#include<bits/stdc++.h>
using namespace std;

#define DEBUG

// AC
// https://leetcode-cn.com/submissions/detail/146847123/


class Solution {
private:
    double pre_guess = 0.;

public:

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

    // 这样判断是否应该停止迭代的方法是错误的; 如果输入2147395599会陷入死循环
    // bool good(double guess, double target, double eps = 1e-7){
    //     if(abs(f(guess, target)) <= eps){ 
    //         return true;
    //     }
    //     else return false;
    // }


    bool good(double guess, double target, double eps = 1e-7){
        if(abs(guess - pre_guess) < eps){ 
            return true;
        }

        else{
            pre_guess = guess;
            return false;
        } 
    }

    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;

        double guess = x;
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

        // while(1){
        //     // guess = 0.5 * (guess + target / guess); 
        //     double tmp = 0.5 * (guess + target / guess); 
        //     if(fabs(guess - tmp) < 1e-7) {
        //         break;
        //     }

        //     guess = tmp;

        //     #ifdef DEBUG
        //     iter_cnt++;
        //     cout<<"iter_cnt: "<<iter_cnt<<endl;
        //     cout<<"guess: "<<guess<<endl;
        //     #endif
        // }


        #ifdef DEBUG
        cout<<"expected answer: "<<(int) sqrt(x)<<endl;
        cout<<"iter_cnt: "<<iter_cnt<<endl;
        cout<<"guess: "<<guess<<endl;
        #endif
        return (int)guess;
    }
};



// AC
// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x == 0) {
//             return 0;
//         }

//         // double target = x, guess = x;
//         double target = x;
//         double guess = x;

//         while (true) {
//             double tmp = 0.5 * (guess + target / guess);
//             if (fabs(guess - tmp) < 1e-7) {
//                 break;
//             }
//             guess = tmp;
//         }
//         return int(guess);
//     }
// };




int main(){
    int x;
    Solution solution = Solution();
    cin>>x;
    cout<<solution.mySqrt(x)<<endl;
}