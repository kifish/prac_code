class Solution
{   
    int row,col;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
public:
    bool isvalid(int x,int y){
        if(x >= 0 && x < row && y >=0 && y <col) return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {   
        queue<pair<int,int>> q;//队列中存放的待确定最小距离的点
        //原始matrix即输入数据，正在修改的matrix即对应每个点的最小距离
        //最小距离可以逐步被优化。某个点最小距离被优化了则将该点加入队列
        row = matrix.size();
        col = matrix[0].size();
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    q.push({i,j});
                }
                else matrix[i][j] = INT_MAX;
            }
        }
        while (!q.empty())
        {
            pair<int,int> point = q.front();
            q.pop();
            int x = point.first;
            int y = point.second;
            int new_x,new_y;
            for(int i = 0;i<4;i++){
                new_x = x + dx[i];
                new_y = y + dy[i];
                if(isvalid(new_x,new_y) && matrix[x][y] < matrix[new_x][new_y]){
                    matrix[new_x][new_y] = matrix[x][y] + 1;
                    q.push({new_x,new_y});
                }
            }
        }
        return matrix;
    }
};