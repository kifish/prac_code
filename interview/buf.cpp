#include <iostream>
using namespace std;
struct State
{
    char map[10][10]; //棋盘
    int pre_row_idx; //上一个棋子的行数
};
//st表示开始搜索的棋子所在的那一行,resnum表示剩余可放的棋子数
int n, resnum; //n表示当前的棋盘大小为n*n,k表示可放的总棋子数
int ans;       //摆放的所有可能数
void DFS(State &state, int left)
{
    if (left == 0)
    { //成功放完
        ans++;
        return;
    }
    int row, col;
    for (row = state.pre_row_idx + 1; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (state.map[row][col] == '#')
            {
                State next = state;
                next.pre_row_idx = row;
                for (int j = row + 1; j < n; j++)
                    next.map[j][col] = '.';
                DFS(next, left - 1);
            }
        }
    }
}
int main()
{
    while (cin >> n >> resnum)
    {

        if (n == -1 && resnum == -1)
            break;
        ans = 0;
        State temp;
        temp.pre_row_idx = -1; //此时还未放棋子,初始化为-1
        for (int i = 0; i < n; i++)
        {
            cin >> temp.map[i];
        }
        DFS(temp, resnum);
        cout << ans << endl;
    }
    return 0;
}