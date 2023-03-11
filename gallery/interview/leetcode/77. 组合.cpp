/*
https://leetcode-cn.com/problems/combinations/

https://leetcode-cn.com/problems/combinations/solution/zu-he-by-leetcode/

https://leetcode-cn.com/problems/combinations/solution/zu-he-by-leetcode/157419
*/

class Solution {
    vector<int> candidates;
    int m_k;
    vector<vector<int>> paths;

    void dfs(int idx, int cnt, vector<int> & path){
        if(cnt == m_k){
            paths.push_back(path);
            return;
        }

        if(idx == candidates.size()){
            return;
        }
        path.push_back(candidates[idx]);
        dfs(idx + 1, cnt + 1, path);
        path.pop_back();
        dfs(idx + 1, cnt, path);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        for(int i = 1; i <= n; i++){
            candidates.push_back(i);
        }
        m_k = k;
        vector<int> path;
        dfs(0, 0 , path);
        return paths;
    }
};
