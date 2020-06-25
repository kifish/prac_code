// https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 做对称变化
        for(int i = 0;i< matrix.size();i++){
            for(int j = i;j<matrix[i].size();j++){ // 注意是j=i而不是j=0; 如果是从0开始,则后面的修改会覆盖前面的修改,导致最后完全没变换
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        // 每一行逆序
        for(int i = 0;i<matrix.size();i++){
            int p = 0;
            int q = (int) matrix[i].size() - 1;
            while(p < q){
                swap(matrix[i][p],matrix[i][q]);
                p++;
                q--;
            }
        }
    }
};