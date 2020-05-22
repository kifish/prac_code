class Solution
{
public:
    int nthUglyNumber(int n){
        vector<int> nums(1,1);
        int idx2 = 0,idx3 = 0,idx5 = 0;
        int cnt = 1;
        while(cnt<n){
            int next = min(2*nums[idx2],min(3*nums[idx3],5*nums[idx5]));
            if(next == 2*nums[idx2]) idx2++;
            if(next == 3*nums[idx3]) idx3++;
            if(next == 5*nums[idx5]) idx5++;
            nums.push_back(next);
            cnt++;
        }
        return nums.back();
    }
};
