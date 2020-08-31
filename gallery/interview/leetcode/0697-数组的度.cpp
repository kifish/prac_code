class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int,vector<int>> val2idxs;
        for(int i =0;i<nums.size();i++){
            val2idxs[nums[i]].push_back(i);
        }
        int du = 0;
        for(auto item : val2idxs){
            du = max(du,(int)item.second.size());
        }
        int min_len = nums.size();
        for(auto item : val2idxs){
            if(du == item.second.size()){
                min_len = min(min_len, item.second[item.second.size() - 1] - item.second[0] + 1);
            }
        }
        return min_len;
    }
};