// AC
// class Solution {
// public:
//     set<vector<int>> paths;
//     int g_target;
//     int len;
//     void dfs(vector<int>& candidates,int cur_idx,int cur_sum,vector<int>& path){
//         if(cur_sum > g_target){
//             return;
//         }
//         if(cur_sum == g_target){
//             paths.insert(path);
//             return;
//         }
//         if(cur_idx == len){
//             return;
//         }

//         path.push_back(candidates[cur_idx]);
//         //这样写的话，解答数中某些路径会被多次遍历
//         dfs(candidates,cur_idx+1,cur_sum+candidates[cur_idx],path);
//         dfs(candidates,cur_idx,cur_sum+candidates[cur_idx],path);
          // 如果上面两行只有一个dfs那么就不会出现路径被多次遍历的情况;当前的解法需要去重
          // 因此这个解法还可以优化
//         path.pop_back();
//         dfs(candidates,cur_idx+1,cur_sum,path);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         g_target = target;
//         len = candidates.size();
//         vector<int> path;
//         dfs(candidates,0,0,path);
//         vector<vector<int>> ret;
//         for(auto& p : paths){
//             ret.push_back(p);
//         }
//         return ret;
//     }
// };


// https://leetcode-cn.com/problems/combination-sum/solution/dfs-jian-zhi-by-happy_yuxuan/


class Solution {
public:
    vector<vector<int>> paths;
    int len;
    void dfs(vector<int>& candidates,int cur_idx,int cur_target,vector<int>& path){
        if(cur_target < 0){
            return;
        }
        if(cur_target == 0){
            paths.push_back(path);
            return;
        }
        if(cur_idx == len){
            return;
        }

        path.push_back(candidates[cur_idx]);
        dfs(candidates,cur_idx,cur_target-candidates[cur_idx],path);
        path.pop_back();
        dfs(candidates,cur_idx+1,cur_target,path);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        len = candidates.size();
        vector<int> path;
        dfs(candidates,0,target,path);
        return paths;
    }
};