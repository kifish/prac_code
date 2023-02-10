/*


https://leetcode-cn.com/problems/combination-sum-ii/



经典dfs + 回溯

https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/

*/

class Solution {
    vector<int> m_candidates;
    int m_target;
    vector<vector<int>> paths;
public:
    /*
    // WA
    void dfs(int idx, int cur_sum, vector<int> & path){
        if(cur_sum == m_target){
            paths.push_back(path);
            return;
        }

        if(idx == m_candidates.size()){
            return;
        }
        if(cur_sum > m_target){
            return;
        }

        path.push_back(m_candidates[idx]);
        dfs(idx + 1, cur_sum + m_candidates[idx], path);
        path.pop_back();
        dfs(idx + 1, cur_sum, path);
    }
    */

    void dfs(int start_idx, int cur_sum, vector<int> & path){
        if(cur_sum == m_target){
            paths.push_back(path);
            return;
        }

        if(start_idx == m_candidates.size()){
            return;
        }
        if(cur_sum > m_target){
            return;
        }

        for(int idx = start_idx; idx < m_candidates.size(); idx++){
            if(idx > start_idx && m_candidates[idx] == m_candidates[idx - 1]){
                continue;
            }
            path.push_back(m_candidates[idx]);
            dfs(idx + 1, cur_sum + m_candidates[idx], path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        m_candidates = candidates;
        sort(m_candidates.begin(), m_candidates.end());
        m_target = target;
        vector<int> path;
        dfs(0, 0, path);
        return paths;
    }
};
