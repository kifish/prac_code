负环检测。
http://algorithm.openjudge.cn/2018finalsim/5/

C语言里没有log0.5,要用换底公式。

```C
#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF = 0x3fffffff;
const double DINF = 10000000000.0;

map<string, int> name_to_idx;


const double base = log2(0.5);
double tran(double x) {
	return log2(x) / base;
}

struct Node {
	int v;
	double w;
};
vector<Node> adj[35];

double d[35];

bool bf(int n) {
	for (int i = 0; i < n; i++) d[i] = DINF;
	d[0] = 0;
	int times = n - 1;
	while (times--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int u = i, v = adj[i][j].v;
				double w = adj[i][j].w;
				if (d[u] != DINF && d[u] + w < d[v]) {
					d[v] = d[u] + w;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int u = i, v = adj[i][j].v;
			double w = adj[i][j].w;
			if (d[u] != DINF && d[u] + w < d[v]) {
				return false;//circle
			}
		}
	}
	return true;
}

int main() {
	int n, m;
	int case_n = 0;
	while (cin >> n && n) {
		case_n++;
		name_to_idx.clear();
		for (int i = 0; i <= n; i++) adj[i].clear();

		int idx = 0;
		int times = n;
		string s;
		while (times--) {
			cin >> s;
			if (name_to_idx.count(s) == 0) {
				name_to_idx[s] = idx;
				idx++;
			}
		}
		cin >> m;
		times = m;
		while (times--) {
			string a, b;
			double x;
			cin >> a >> x >> b;
			x = tran(x);
			int u, v;
			u = name_to_idx[a];
			v = name_to_idx[b];
			Node tmp;
			tmp.v = v;
			tmp.w = x;
			adj[u].push_back(tmp);
		}
		bool res = bf(n);
		if (res) {
			cout << "Case " << case_n << ": " << "No" << endl;
		}
		else {
			cout << "Case " << case_n << ": " << "Yes" << endl;
		}
	}
	
	//while (1);
	return 0;
	
}
```

