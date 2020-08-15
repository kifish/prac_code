
/*


https://leetcode-cn.com/problems/divide-two-integers/


https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/

*/


// -2147483648
// 2


// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 5.8 MB
// , 在所有 C++ 提交中击败了
// 87.55%
// 的用户


class Solution {
public:

    long abs(long x){
        if(x < 0) return -1 * x;
        return x;
    }
    int divide(int dividend, int divisor) {
        // divisor != 0
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend != INT_MIN){
                return -1 * dividend;
            }
            else
            {
                return INT_MAX; // 溢出了
            }
        }      
        bool pos = true;
        if((dividend < 0 && divisor > 0) || (dividend >0 && divisor < 0)){
            pos = !pos;
        }
        int tmp = div(abs(dividend), abs(divisor));
        if(pos){
            return tmp;
        }
        return -1 * tmp;
    }

    int div(long a, long b){ // a / b
        if(a < b) return 0;

        int cnt = 1;
        long big = b;
        while(big + big <= a) { // 可优化
            cnt += cnt;
            big += big;
        }
        return cnt + div(a - big, b); // a-big 可能会变很小的负值
    }
};