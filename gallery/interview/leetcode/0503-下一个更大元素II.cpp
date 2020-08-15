class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // map<int,int> M;//不能再用map了，因为不唯一
        stack<int> S;//index为item的元素（需确定该元素的next greater num）
        vector<int> res(nums.size(),-1);
        vector<int> nums_copy;
        for(int num:nums) nums_copy.push_back(num);
        for(int num:nums) nums_copy.push_back(num);
       
        for(int i = 0;i<nums_copy.size();i++){
            while(!S.empty() && nums[S.top()] < nums_copy[i]){
                res[S.top()] = nums_copy[i];
                S.pop();
            }
            if(i<nums.size())
                S.push(i);
        }
        
        return res;
    }
};