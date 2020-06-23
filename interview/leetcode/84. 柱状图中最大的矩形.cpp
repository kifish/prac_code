

// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhao-liang-bian-di-yi-ge-xiao-yu-ta-de-zhi-by-powc/




// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/xiang-jie-dan-diao-zhan-bi-xu-miao-dong-by-sweetie/

// 上述写法中，我们需要再嵌套一层 while 循环来向左找到第一个比柱体 i 高度小的柱体，这个过程是O(N)的

// 先暴力找到O(n^2)的解法再来优化



// 输入:
// [1,1]
// 输出
// 1
// 预期结果
// 2



// class Solution {
// public:
//     stack<int> S; // 存单调递增的子序列的对应的index

//     int largestRectangleArea(vector<int>& heights) {
//         int ret = 0;
//         for(int i = 0;i<heights.size();i++){
//             int cur_height = heights[i];

//             if(S.empty()){
//                 // 特殊情况// 例如第一个数
//                 int left = 0;
//                 int right = i;
//                 int width = right - left + 1;
//                 int the_height = cur_height;
//                 ret = max(ret, width * the_height);
//             }
//             else{
//                 while(!S.empty() && cur_height < heights[S.top()]){
//                     // 说明S.top()对应的数可以作为矩形的高度,且此时它的右边界可以确定了(右边第一个比heights[S.top()]小的位置)
//                     // 右边界即i-1(包含i-1)
//                     // 左边界呢?
//                     // 即栈中的下一个元素
//                     int right = i - 1;
//                     int the_height = heights[S.top()];
//                     S.pop(); // 为什么可以直接出栈了, 因为这个idx已经不可能再次成为the height对应的idx, 没有价值了
//                     int left;
//                     if(S.empty()){
//                         left = 0;
//                     }
//                     else{
//                         left = S.top() + 1;
//                     }
//                     int width = right - left + 1;
//                     ret = max(ret, width * the_height);
//                 }
//                 // 为什么是单调自增栈, 因为while(!S.empty() && cur_height < heights[S.top()])
//                 // 只要满足这个条件, 栈顶元素都会被弹出
//                 // 因为最终入栈的时候, 要么栈为空要么当前idx对应的元素是>=栈顶的idx对应的元素的
//             }
//             S.push(i);
//         }
//         return ret;
//     }
// };






// 输入:
// [2,4]
// 输出
// 2
// 预期结果
// 4

// 还得特判最后一个数

// class Solution {
// public:
//     stack<int> S; // 存单调递增的子序列的对应的index

//     int largestRectangleArea(vector<int>& heights) {
//         int ret = 0;
//         for(int i = 0;i<heights.size();i++){
//             int cur_height = heights[i];

//             if(S.empty()){
//                 // 特殊情况// 例如第一个数
//                 int left = 0;
//                 int right = i;
//                 int width = right - left + 1;
//                 int the_height = cur_height;
//                 ret = max(ret, width * the_height);
//             }
//             else{
//                 while(!S.empty() && 
//                         (cur_height < heights[S.top()] || 
//                             (cur_height == heights[S.top()] && i == (int)heights.size() - 1))){
//                     // 说明S.top()对应的数可以作为矩形的高度,且此时它的右边界可以确定了(右边第一个比heights[S.top()]小的位置)
//                     // 右边界即i-1(包含i-1)
//                     // 左边界呢?
//                     // 即栈中的下一个元素
//                     int right;
//                     if(i == (int)heights.size() - 1){
//                         right = i;
//                     }
//                     else{
//                         right = i - 1;
//                     }

//                     int the_height = heights[S.top()];
//                     S.pop(); // 为什么可以直接出栈了, 因为这个idx已经不可能再次成为the height对应的idx, 没有价值了
//                     int left;
//                     if(S.empty()){
//                         left = 0;
//                     }
//                     else{
//                         left = S.top() + 1;
//                     }
//                     int width = right - left + 1;
//                     ret = max(ret, width * the_height);
//                 }
//                 // 为什么是单调自增栈, 因为while(!S.empty() && cur_height < heights[S.top()])
//                 // 只要满足这个条件, 栈顶元素都会被弹出
//                 // 因为最终入栈的时候, 要么栈为空要么当前idx对应的元素是>=栈顶的idx对应的元素的
//             }
//             S.push(i);
//         }
//         return ret;
//     }
// };



// 执行用时：
// 16 ms
// , 在所有 C++ 提交中击败了
// 79.00%
// 的用户
// 内存消耗：
// 8.6 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    stack<int> S; // 存单调递增的子序列的对应的index

    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        // 添加2个dummy node
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        for(int i = 0;i<heights.size();i++){
            int cur_height = heights[i];
            while(!S.empty() && (cur_height < heights[S.top()])){
                // 说明S.top()对应的数可以作为矩形的高度,且此时它的右边界可以确定了(右边第一个比heights[S.top()]小的位置)
                // 右边界即i-1(包含i-1)
                // 左边界呢?
                // 即栈中的下一个元素
                int right = i - 1;
                int the_height = heights[S.top()];
                S.pop(); // 为什么可以直接出栈了, 因为这个idx已经不可能再次成为the height对应的idx, 没有价值了
                int left;
                // 由于有padding, S不可能为空
                left = S.top() + 1;
                int width = right - left + 1;
                ret = max(ret, width * the_height);
            }
                // 为什么是单调自增栈, 因为while(!S.empty() && cur_height < heights[S.top()])
                // 只要满足这个条件, 栈顶元素都会被弹出
                // 因为最终入栈的时候, 要么栈为空要么当前idx对应的元素是>=栈顶的idx对应的元素的
            S.push(i);
        }
        // 最终stack里面一定是两个0对应的index
        

        return ret;
    }
};
