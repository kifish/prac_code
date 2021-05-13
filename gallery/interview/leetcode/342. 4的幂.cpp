/*

https://leetcode-cn.com/problems/power-of-four/


https://leetcode-cn.com/problems/power-of-four/solution/4de-mi-by-leetcode/

执行结果：
通过
显示详情
添加备注

执行用时：
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗：
5.8 MB
, 在所有 C++ 提交中击败了
51.23%
的用户


class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        if(n == 4) return true;

        if(n % 4 != 0)
            return false;
        return isPowerOfFour(n / 4);
    }
};




*/