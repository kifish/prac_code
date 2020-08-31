/*

https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1030/

https://leetcode-cn.com/problems/triangle/

*/


// 递归? 但是这个实现起来有点麻烦
// class Solution {
// public:

//     int minimumTotal(vector<vector<int>>& triangle,int i, int j) {
//         if(i + 1 == triangle.size()){
//             if(j+1 == triangle[i].size())
//                 return triangle[i][j];
//             return min(triangle[i][j],triangle[i][j+1]);
//         }

//         if(j+1 == triangle[i+1].size()){
//             //
//         }
//         else{
//             // 
//         }
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {

//     }
// };






// https://leetcode-cn.com/problems/triangle/solution/san-jiao-xing-zui-xiao-lu-jing-he-by-leetcode-solu/491469


// 执行用时：
// 8 ms
// , 在所有 C++ 提交中击败了
// 93.05%
// 的用户
// 内存消耗：
// 8.4 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0; // undifined

        vector<vector<int>> dp(triangle);
        for(int i = 1;i <triangle.size();i++){
            for(int j = 0;j<triangle[i].size();j++){
                // cout<<"i: "<<i<<"\t"<<"j: "<<j<<endl;

                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j + 1 == triangle[i].size()){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        int ret = INT_MAX;
        int e_idx = (int)triangle.size() - 1;
        for(int j = 0;j<dp[e_idx].size();j++){
            ret = min(ret, dp[e_idx][j]);
        }
        return ret;
    }
};

