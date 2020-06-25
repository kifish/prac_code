class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int i,j;
        int num = 1;
        for(int row = 0, i = j = row;row < n; row++,i = j = row){ // col == row
            while(j < n-row) res[i][j++] = num++;
            j--;
            while(i < n-row-1) res[++i][j] = num++;
            while(j > row) res[i][--j] = num++;
            while(i > row + 1) res[--i][j] = num++;
        }
        return res;
    }
};