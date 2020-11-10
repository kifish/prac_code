// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7


// https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/yong-rand7-shi-xian-rand10-by-leetcode/


// 执行结果：
// 通过
// 显示详情
// 执行用时 :
// 12 ms
// , 在所有 C++ 提交中击败了
// 70.42%
// 的用户
// 内存消耗 :
// 8.1 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int rand10() {
        while(1){
            int row = rand7();
            int col = rand7();  
            // 注意不是直接乘
            // 是通过7进制 10进制的转换
            int a = col + (row - 1) * 7; // row 确定行, col 确定列
            if(a <= 40){
                return a % 10 + 1;
            }
        }
    }
};


/*


rand1() 模拟 rand5()
0-1

0-4
0-9
0-14

这里的情况可能和rand7模拟rand10不同
rand7模拟2次，一定可以通过拒绝采样模拟rand10

https://kifish.visualstudio.com/_git/interview?path=%2F%E4%BA%AC%E4%B8%9C%E4%BA%8C%E9%9D%A2.md&_a=preview

*/