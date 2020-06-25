

// TLE
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//        vector<int> dp(height.size(), 0);
//        for(int i = 0;i<height.size();i++){
//            for(int j = 0;j < i ;j++){
//                int cur_product = min(height[i],height[j]) * (i - j);
//                 dp[i] = max(dp[i], cur_product);
//            }
//        }
//        int ret = 0;
//        for(auto v : dp){
//            ret = max(ret, v);
//        }
//        return ret;
//     }
// };


// https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode-solution/353930

// 执行用时 :
// 16 ms
// , 在所有 C++ 提交中击败了
// 79.98%
// 的用户
// 内存消耗 :
// 7.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    int maxArea(vector<int>& height) {
       int ret = 0;
       int i = 0;
       int j = (int) height.size() - 1;
       while(i < j){
            int cur_product = min(height[i],height[j]) * (j - i);
            ret = max(ret, cur_product);
            if(height[i] <= height[j]){
                i++; // 当前的i不可能作为边界了
            }
            else{
                j--;
            }
       }
       return ret;
    }
};