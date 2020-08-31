class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        int min_val = min(m,n);
        for(int start=0,row = 0,col = 0;start < min_val - start;start++,row = col = start){
            while(col < n - start) res.push_back(matrix[row][col++]);
            col--;
            while(row < m - start - 1) res.push_back(matrix[++row][col]);
            if(col == start) continue;//想象只有一列数，若满足这个条件，则无需往下执行
            while(col > start && row > start) res.push_back(matrix[row][--col]);
            while(row > start + 1 && col >= start) res.push_back(matrix[--row][col]);
        }
        return res;
    }
};