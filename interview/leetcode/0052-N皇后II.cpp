class Solution
{
    vector<vector<char>> board;
    int cnt = 0;
public:
    void init(int n){
        for(int i = 0;i<n;i++){
            vector<char> buf;
            for(int j = 0;j<n;j++){
                buf.push_back('.');
            }
            board.push_back(buf);
        }
    }
    bool isvalid(int cur_row,int cur_col,int n){
        for(int j = 0;j<cur_col;j++){
            if(board[cur_row][j] == 'Q') return false;
        }
        for(int x = cur_row-1, y = cur_col -1;x>=0 && y>=0;x--,y--){
            if(board[x][y] == 'Q') return false;
        }
        for (int x = cur_row + 1,y = cur_col - 1; x <= n-1 && y >= 0; x++, y--)
        {
            if (board[x][y] == 'Q') return false;
        }
        return true;
    }

    void dfs(int cur_col,int n){
        if(cur_col == n){
            cnt++;
            return;
        }

        for (int r = 0; r < n; r++)
        {
            board[r][cur_col] = 'Q';
            if (isvalid(r, cur_col, n))
            {
                dfs(cur_col + 1, n);
            }
            board[r][cur_col] = '.';
        }
    }

    int totalNQueens(int n){
        init(n);
        dfs(0, n);
        return cnt;
    }
};