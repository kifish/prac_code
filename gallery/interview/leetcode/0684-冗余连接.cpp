class Solution {
	int n;
	vector<int> parent;
public:
	int find_parent(int x) {
		if (parent[x] != x) {
			int tmp = find_parent(parent[x]);
			parent[x] = tmp;
			return  tmp;
		}
		else return x;
	}

	void init() {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
		}
	}

	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		n = edges.size();
		init();
		vector<int> res;
		for (int i = 0; i < edges.size(); i++) {
			int a = edges[i][0];
			int b = edges[i][1];
			int roota = find_parent(a);
			int rootb = find_parent(b);
			if (roota != rootb) {
				parent[rootb] = roota;//ºÏ²¢
			}
			else{//ÈßÓà
				res.clear();
				res.push_back(a);
				res.push_back(b);
			}
		}
		return res;
	}
};