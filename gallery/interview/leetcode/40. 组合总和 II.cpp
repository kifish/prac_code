/*
https://leetcode-cn.com/problems/combination-sum-ii/

经典dfs + 回溯

https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
*/

/*
// TLE
class Solution {
    vector<int> path;
    set<vector<int>> paths;
public:
    void dfs(vector<int> & candidates, int index, int sum, int target){
        if(sum == target){
            paths.insert(path);
            return;
        }

        if(index == candidates.size()){
            return;
        }

        path.push_back(candidates[index]);
        dfs(candidates, index + 1, sum + candidates[index], target);
        path.pop_back();
        dfs(candidates, index + 1, sum, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target);
        vector<vector<int>> ret;
        for(auto path : paths){
            ret.push_back(path);
        }
        return ret;
    }
};
*/

// AC
class Solution {
    vector<int> path;
    vector<vector<int>> paths;
public:
    void dfs(vector<int> & candidates, int begin, int sum, int target){
        if(sum == target){
            paths.push_back(path);
            return;
        }

        if(begin == candidates.size()){
            return;
        }

        for(int index = begin; index < candidates.size(); index++){
            if(index > begin && candidates[index] == candidates[index-1]){
                continue;;
            }
            int cur_sum = sum + candidates[index];
            if(cur_sum > target){ //须剪枝，否则会TLE
                return;
            }
            path.push_back(candidates[index]);
            dfs(candidates, index + 1, cur_sum, target);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target);
        vector<vector<int>> ret;
        for(auto path : paths){
            ret.push_back(path);
        }
        return ret;
    }
};