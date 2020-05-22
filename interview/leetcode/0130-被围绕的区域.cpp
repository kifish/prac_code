//#include <vector>
//#include <iostream>
//using namespace std;
class Solution {
public:
	int row;
	int col;
	int dummy_node;
	int node_cnt;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	vector<int> parent;
	int xytoID(int x, int y) {
		return x * col + y;
	}
	int find_parent(int x) {
		if (parent[x] != x) {
			int tmp = find_parent(parent[x]);
			parent[x] = tmp;
			return  tmp;
		}
		else return x;
	}

	void init() {
		for (int i = 0; i < node_cnt; i++) {
			//parent[i] = i;
            parent.push_back(i);
		}
	}
	bool isvalid(int x, int y) {
		if (x < 0 || y < 0 || x >= row || y >= col) return false;
		return true;
	}
	void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
		row = board.size();
		col = board[0].size();
		dummy_node = row * col; //与dummynode联通的O不需要修改;与dummynode不联通的O（说明被X包围了）需要修改
		node_cnt = row * col + 1;
		init();

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'O') {
					if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
						int roota = find_parent(xytoID(i, j));
						parent[roota] = dummy_node;
					}
					else {
						//上下左右
						int new_x, new_y;
						for (int k = 0; k < 4; k++) {
							new_x = i + dx[k];
							new_y = j + dy[k];
							if (isvalid(new_x, new_y) && board[new_x][new_y] == 'O') {
								int roota = find_parent(xytoID(new_x, new_y));
								int rootb = find_parent(xytoID(i, j));
								if (roota != rootb) {
									//避免dummy_node根被修改
									if (roota != dummy_node)
										parent[roota] = rootb;
									else parent[rootb] = roota;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (board[i][j] == 'O') {
					if (find_parent(xytoID(i, j)) != dummy_node)
						board[i][j] = 'X';
				}
			}
		}
	}
};


//int main() {
//	vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'} };
//	for (int i = 0; i < board.size(); i++) {
//		for (int j = 0; j < board[i].size(); j++) {
//			cout << board[i][j];
//		}
//		cout << endl;
//	}
//	Solution().solve(board);
//	for (int i = 0; i < board.size(); i++) {
//		for (int j = 0; j < board[i].size(); j++) {
//			cout << board[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}