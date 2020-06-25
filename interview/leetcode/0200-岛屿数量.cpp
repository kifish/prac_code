class Solution {
	int row;
	int col;
	int dummy_node;
	int node_cnt;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	vector<int> parent;
public:
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
			parent.push_back(i);
		}
	}
	bool isvalid(int x, int y) {
		if (x < 0 || y < 0 || x >= row || y >= col) return false;
		return true;
	}
	int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
		row = grid.size();
		col = grid[0].size();
		node_cnt = row * col;
		init();
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == '1') {
					int new_x, new_y;
					for (int k = 0; k < 4; k++) {
						new_x = i + dx[k];
						new_y = j + dy[k];
						if (isvalid(new_x, new_y) && grid[new_x][new_y] == '1') {
							int roota = find_parent(xytoID(new_x, new_y));
							int rootb = find_parent(xytoID(i, j));
							if (roota != rootb) {
								parent[rootb] = roota;
							}
						}
					}
					
				}
			}
		}
		int res = 0;
		set<int> roots;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1') {
					int root = find_parent(xytoID(i, j));
					if (roots.find(root) == roots.end()) {
						res++;
						roots.insert(root);
					}	
				}
			}
		}
		return res;
	}
};