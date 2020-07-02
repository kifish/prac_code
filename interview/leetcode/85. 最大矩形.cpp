
// https://leetcode-cn.com/problems/maximal-rectangle/solution/dan-diao-di-zeng-zhan-dpqiao-miao-jie-jue-by-wallc/

/*
先联系 LeetCode 84这道题目

https://leetcode-cn.com/problems/maximal-rectangle/solution/dan-diao-di-zeng-zhan-dpqiao-miao-jie-jue-by-wallc/




执行用时：
44 ms
, 在所有 C++ 提交中击败了
35.22%
的用户
内存消耗：
9.3 MB
, 在所有 C++ 提交中击败了
100.00%
的用户



*/


class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;
        // heights 前面的0和 最后的0 从调用的地方补
        // 前后补0处理边界情况; 否则边界情况会写起来很麻烦
        // 单调栈求最大矩形
        // 单调递增栈
        int ret = 0;
        for(int i =  0;i<heights.size();i++){
            int cur_height = heights[i];
            while(!S.empty() && cur_height < heights[S.top()]){
                int right = i - 1; // 可以确认heights[S.top()]的右边界了
                int the_height = heights[S.top()];
                S.pop();
                int left = S.top() + 1; // 这里的+1很关键, 注意是left才是左边界
                ret = max(ret, (right - left + 1) * the_height);
            }
            S.push(i);
        }
        return ret;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;


        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n+2,0); // dp[j]存的是到目前为止 第j列的高度
        int ret = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int the_col = j + 1;
                if(matrix[i][j] == '1'){
                    dp[the_col]++;
                }
                else{
                    dp[the_col] = 0;
                }
            }
            ret = max(ret, largestRectangleArea(dp));
        }
        return ret;
    }
};




// https://leetcode-cn.com/problems/maximal-rectangle/solution/geng-zhi-bai-yi-dian-de-dong-tai-gui-hua-by-vsym/

// 纯dp的思路可以看看这个, 不过里面错误不少