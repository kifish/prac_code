
/*

https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/


可以dp也可以栈


dp:
dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2 // 注意要把之前的也算上, 即dp[i−dp[i−1]−2]



栈的方法更清晰



https://leetcode-cn.com/problems/longest-valid-parentheses/solution/python-xu-hao-zhan-jie-fa-de-jian-ji-xie-fa-by-pen/452036

*/

// WA

// 输入:
// ")()())"
// 输出
// 2
// 预期结果
// 4



// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int> S;
//         int ret = 0;
//         for(int i = 0;i<s.size(); i++){
//             if(s[i] == '('){
//                 S.push(i);
//             }
//             else{
//                 if(!S.empty() && s[S.top()] == '('){
//                     ret = max(ret, i - S.top() + 1);
//                     S.pop();
//                 }
//             }
//         }
//         return ret;
//     }
// };




// 执行用时：
// 4 ms
// , 在所有 C++ 提交中击败了
// 94.32%
// 的用户
// 内存消耗：
// 7.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户




class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> S;
        int ret = 0;
        for(int i = 0;i<s.size(); i++){
            if(s[i] == '('){
                S.push(i);
            }
            else{
                if(!S.empty() && s[S.top()] == '('){
                    S.pop(); // 不需要这个信息了, 记住从left开始就是有效的即可
                    int left;
                    if(S.empty()){
                        left = 0;
                    }
                    else{
                        left = S.top() + 1; // 从left开始就是有效的
                    }
                    ret = max(ret, i - left + 1);
                }
                else{
                    S.push(i); // 不有效, 占一个位置, 从而缩小有效的范围
                }
            }
        }
        return ret;
    }
};



// 方法 4也挺巧妙的
// https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/


