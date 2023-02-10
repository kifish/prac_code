/*


https://leetcode-cn.com/problems/permutations-ii/


剪枝

https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/


https://leetcode-cn.com/problems/permutations-ii/solution/shuang-bai-si-lu-chao-ji-jian-ji-by-tai-yang-tian/


https://leetcode-cn.com/problems/permutations-ii/solution/shuang-bai-si-lu-chao-ji-jian-ji-by-tai-yang-tian/466507





https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/


*/

class Solution {
    vector<int> m_nums;
    vector<int> visited;
    vector<vector<int>> paths;
public:
    void dfs(vector<int> & path){
        if(path.size() == m_nums.size()){
            paths.push_back(path);
            return;
        }

        for(int idx = 0; idx < m_nums.size(); idx++){
            // 实现1
            // if(idx > 0 && m_nums[idx] == m_nums[idx - 1] && visited[idx - 1]){
            //     continue;
            // }

            // 实现2            
            if(idx > 0 && m_nums[idx] == m_nums[idx - 1] && !visited[idx - 1]){
                continue;
            }

            // 实现1和实现2都正确

            if(!visited[idx]){
                path.push_back(m_nums[idx]);
                visited[idx] = 1;
                dfs(path);
                path.pop_back();
                visited[idx] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        m_nums = nums;
        sort(m_nums.begin(), m_nums.end());
        visited.resize(nums.size(), 0);
        vector<int> path;
        dfs(path);
        return paths;
    }
};
