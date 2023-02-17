class Solution {
public:
    map<int,int> rob_left;
    // map<int,int> rob_right;
    // int rob_left(vector<int>& nums,int l){
    //     if(rob_left.count(l)){
    //         return rob_left[l];
    //     }
    //     if(l ==  0) {
    //         rob_left[0] = nums[l];
    //         return nums[l];
    //     } 
    //     int v = nums[l];
    //     int ll_all = 0;
    //     if(l - 2 >= 0){
    //         ll_all += rob_left(nums, l - 2);
    //     }
    //     int l_all = 0;
    //     if(l - 1 >= 0){
    //         l_all += rob_left(nums,l - 1);
    //     }
    //     int ret = 0;
    //     if(l_all > ll_all + v){
    //         ret = l_all;
    //     }
    //     else ret = ll_all + v;
    //     rob_left[l] = ret;
    //     return ret;
    // }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i = 0;i<nums.size();++i){
            if(i == 0){
                rob_left[i] = nums[i];
            }
            else if(i == 1){
                rob_left[i] = max(nums[0],nums[1]);
            }
            else{
                if(rob_left[i-2] + nums[i] > rob_left[i-1]){
                    rob_left[i] = rob_left[i-2] + nums[i];
                }
                else rob_left[i] = rob_left[i-1];
            }
        }
        return rob_left[nums.size() - 1];
    } 
};

class Solution {
    vector<vector<int>> dp; // dp[i][0]表示考虑到nums[i]后不选nums[i]的最大和, dp[i][1]表示考虑到nums[i]后选nums[i]的最大和
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        dp.resize(n, vector<int>(2, 0));
        dp[0][1] = nums[0];
        dp[1][0] = dp[0][1];
        dp[1][1] = nums[1];
        for(int i = 2; i < n; i++){
            dp[i][1] = dp[i-1][0] + nums[i];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

class Solution {
    vector<vector<int>> dp; // dp[i][0]表示考虑到nums[i]后不选nums[i]的最大和, dp[i][1]表示考虑到nums[i]后选nums[i]的最大和, dp[i][1]表示考虑到nums[i]后选或不选nums[i]的最大和
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        dp.resize(n, vector<int>(3, 0));
        dp[0][1] = nums[0];
        dp[0][2] = nums[0];
        dp[1][0] = dp[0][1];
        dp[1][1] = nums[1];
        // dp[1][2] = max(nums[0], nums[1]);
        // dp[1][2] = max(dp[0][2], 0 + nums[1]);
        dp[1][2] = max(dp[0][2], nums[1]);
        for(int i = 2; i < n; i++){
            // dp[i][1] = dp[i-1][0] + nums[i];
            // dp[i][1] = dp[i-2][2] + nums[i];
            // dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            // dp[i][0] = dp[i-1][2];
            // dp[i][2]= max(dp[i][0], dp[i][1]);
            // dp[i][2]= max(dp[i-1][2], dp[i][1]);
            dp[i][2]= max(dp[i-1][2], dp[i-2][2] + nums[i]);
        }
        return dp[n-1][2];
    }
};

class Solution {
    vector<int> dp; // dp[i]表示考虑到nums[i]后选或不选nums[i]的最大和
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        dp.resize(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};
