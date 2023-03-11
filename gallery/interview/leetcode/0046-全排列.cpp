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

class Solution {
    vector<int> m_nums;
    vector<int> visited;
    vector<vector<int>> paths;
public:
    /*
    void dfs(int start_idx, vector<int> & path){
        if(path.size() == m_nums.size()){
            paths.push_back(path);
            return;
        }

        if(start_idx == m_nums.size()){
            return;
        }

        for(int idx = start_idx; idx < m_nums.size(); idx++){
            if(!visited[idx]){
                path.push_back(m_nums[idx]);
                visited[idx] = 1;
                dfs(0, path);
                path.pop_back();
                visited[idx] = 0;
            }
        }
    }
    */

    void dfs(vector<int> & path){
        if(path.size() == m_nums.size()){
            paths.push_back(path);
            return;
        }

        for(int idx = 0; idx < m_nums.size(); idx++){
            if(!visited[idx]){
                path.push_back(m_nums[idx]);
                visited[idx] = 1;
                dfs(path);
                path.pop_back();
                visited[idx] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        m_nums = nums;
        visited.resize(nums.size(), 0);
        vector<int> path;
        // dfs(0, path);
        dfs(path);
        return paths;
    }
};
