class Solution
{
	//转化成图，然后bfs即可。也有直接用二叉树做的方法,没看懂。
private:
	vector<vector<int>> G;//private初始化可能有限制
	bool was_inqueue[501];//在队列中或已经出队列
	int k;
	vector<int> res;
public:
	void bfs(int s) {
		queue<int> Q;
		Q.push(s);
		was_inqueue[s] = true;
		int level = 0;
		while (level != k && !Q.empty()) {
			int cnt = Q.size();
			while (cnt--) {
				int u = Q.front();
				Q.pop();
				for (auto v : G[u]) {
					if (!was_inqueue[v]) {
						Q.push(v);
						was_inqueue[v] = true;
					}
				}
			}
			level++;
		}
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			res.push_back(u);
		}
	}
	void add_edge(TreeNode* root) {
		if (!root) return;
		if (root->left) {
			G[root->val].push_back(root->left->val);
			G[root->left->val].push_back(root->val);
			add_edge(root->left);
		}
		if (root->right)
		{
			G[root->val].push_back(root->right->val);
			G[root->right->val].push_back(root->val);
			add_edge(root->right);
		}
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
	{	
		for (int i = 0; i < 501; i++) {
			was_inqueue[i] = false;
			G.push_back(vector<int>());
		}
		add_edge(root);
		k = K;
		bfs(target->val);
		return res;
	}
};

/*

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
class Solution
{
	//转化成图，然后bfs即可。也有直接用二叉树做的方法,没看懂。
private:
	vector<vector<int>> G;//private初始化可能有限制
	bool was_inqueue[501];//在队列中或已经出队列
	int k;
	vector<int> res;
public:
	void bfs(int s) {
		queue<int> Q;
		Q.push(s);
		was_inqueue[s] = true;
		int level = 0;
		while (level != k && !Q.empty()) {
			int cnt = Q.size();
			while (cnt--) {
				int u = Q.front();
				Q.pop();
				for (auto v : G[u]) {
					if (!was_inqueue[v]) {
						Q.push(v);
						was_inqueue[v] = true;
					}
				}
			}
			level++;
		}
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			res.push_back(u);
		}
	}
	void add_edge(TreeNode* root) {
		if (!root) return;
		if (root->left) {
			G[root->val].push_back(root->left->val);
			G[root->left->val].push_back(root->val);
			add_edge(root->left);
		}
		if (root->right)
		{
			G[root->val].push_back(root->right->val);
			G[root->right->val].push_back(root->val);
			add_edge(root->right);
		}
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
	{	
		for (int i = 0; i < 501; i++) {
			was_inqueue[i] = false;
			G.push_back(vector<int>());
		}
		add_edge(root);
		k = K;
		bfs(target->val);
		return res;
	}
};

void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		getline(cin, line);
		TreeNode* target = stringToTreeNode(line);
		getline(cin, line);
		int K = stringToInteger(line);

		vector<int> ret = Solution().distanceK(root, target, K);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}

*/