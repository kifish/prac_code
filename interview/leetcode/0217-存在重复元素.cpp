class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> S;
        for(auto num : nums) S.insert(num);
        if(S.size() < nums.size()) return true;
        return false;
    }
};