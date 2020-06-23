class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    int n;
    vector<int> global_nums;
    vector<bool> visited;
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        global_nums = nums;
        visited = vector<bool>(n,false);
        dfs();
        return res;
    }

    void dfs(){
        if(path.size() == n) {
            res.push_back(path);
            return;
        }
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                path.push_back(global_nums[i]);
                visited[i] = true;
                dfs();
                path.pop_back();
                visited[i] = false;
                //dfs();//注意这里无需再做dfs，注意这里和LeetCode78的区别
            }
            else continue;
        }
    }
};