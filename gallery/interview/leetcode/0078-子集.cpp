class Solution
{
private:
    vector<int> path;
    int n;
    vector<int> global_nums;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        global_nums = nums;
        dfs(0);
        return res;
    }

    void dfs(int idx){
        if(idx == n)  {
            res.push_back(path);
            return;
        }
        path.push_back(global_nums[idx]);
        dfs(idx+1);
        path.pop_back();
        dfs(idx+1);
    }
};