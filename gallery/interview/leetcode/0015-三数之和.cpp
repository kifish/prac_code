/*

https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1020/

https://leetcode-cn.com/problems/3sum/

排序肯定是省不了的,

这样就有n^2logn 的解法了

还能更优吗?

枚举a

然后寻找 b和c的组合

让b + c = -a
而 b + c > a
如果a > 0, 则会推出矛盾, 因此a>0直接跳过


然后用双指针
这种方法的复杂度为nlogn + n*n = n^2



*/


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {   
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<(int)nums.size() -2;i++){
            if(nums[i] > 0) continue;
            if(i && nums[i] == nums[i-1]) continue; // 加速
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0){
                    l++;
                }
                else if(sum > 0){
                    r--;
                }
                else{
                    res.push_back(vector<int> {nums[i],nums[l],nums[r]});
                    while(l < r && nums[++l] == nums[l-1]);
                    while(l < r && nums[--r] == nums[r+1]);
                }
            }
        }
        return res;
    }
};