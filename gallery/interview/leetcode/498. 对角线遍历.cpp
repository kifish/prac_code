/*
https://leetcode-cn.com/problems/diagonal-traverse/

模拟

https://leetcode.cn/problems/diagonal-traverse/solution/er-wei-shu-zu-de-hua-shi-bian-li-by-elle-8i3n/
https://leetcode.cn/problems/diagonal-traverse/solution/by-lzxjack-p2d0/
https://leetcode-cn.com/problems/diagonal-traverse/solution/dui-jiao-xian-bian-li-fen-xi-ti-mu-zhao-zhun-gui-l/
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ret;
        if(mat.size() == 0) return ret;
        int m = mat.size();
        int n = mat[0].size();
        int iter_cnt = m + n - 1;
        bool is_odd = 0;
        for(int i = 0; i < iter_cnt; i++){
            if(is_odd){
                for(int row_idx = 0, col_idx = i; col_idx >= 0; row_idx++, col_idx--){
                    if(row_idx >= m || col_idx >= n) continue;
                    ret.push_back(mat[row_idx][col_idx]);
                }
            }
            else{
                for(int row_idx = i, col_idx = 0; row_idx >= 0; row_idx--, col_idx++){
                    if(row_idx >= m || col_idx >= n) continue;
                    ret.push_back(mat[row_idx][col_idx]);
                }
            }
            is_odd = !is_odd;
        }
        return ret;
    }
};