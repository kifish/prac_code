/*


https://leetcode-cn.com/problems/trapping-rain-water/

https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1047/


https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/





*/

// TLE

// O(n^2) : 遍历每个位置，统计每个位置最多装多少雨水, 然后加起来。
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int sum = 0;
//         for(int i = 1;i < height.size(); i++){
//             int max_left = height[i], max_right = height[i];
//             for(int j = i - 1; j >= 0; j--){
//                 max_left = max(max_left, height[j]);
//             }
//             for(int j = i + 1; j < height.size(); j++){
//                 max_right = max(max_right, height[j]);
//             }
//             sum += min(max_left,max_right) - height[i];
//         }
//         return sum;
//     }
// };



/*
https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/





*/

// O(n)

// 用dp优化即可

// 执行用时 :
// 4 ms
// , 在所有 C++ 提交中击败了
// 94.90%
// 的用户
// 内存消耗 :
// 6.8 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int sum = 0;
        // vector<int> dp_left = vector<int> (height.size(), 0);
        vector<int> dp_right = vector<int> (height.size(), 0);
        int max_left = 0, max_right = 0;
        for(int j = (int) height.size() - 1;j>=0;j--){
            max_right = max(max_right,height[j]);
            dp_right[j] = max_right;
        }
        max_left = height[0];
        for(int i = 1;i < height.size(); i++){
            max_left = max(max_left, height[i]);
            max_right = dp_right[i];
            sum += min(max_left,max_right) - height[i];
        }
        return sum;
    }
};



// 最优解法是双指针

//  https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/327718 

// 这个讲解的非常好

