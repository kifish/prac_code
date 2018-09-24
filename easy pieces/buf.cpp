#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int> line;
stack<int> s;

int judge(vector<int> line, int n) {
	int pre = 0;
	int start = 0;
	bool decreasing = false;
	if (n == 1) {
		if (line[0] == 1)
			return true;
		else
			return false;
	}
	pre = line[0];
	int i = 1;
	for (; i < line.size(); i++) {
		if (line[i] < pre) {
			if (line[i] == pre - 1) {
				if (decreasing)
					continue;
				else {
					decreasing = true;
					start = i - 1;
				}
			}
			else {
				if (decreasing) {
					decreasing = !decreasing;
					reverse(line.begin() + start, line.begin() + i);
				}
			}
		}
		pre = line[i];
	}
	if (decreasing)
		reverse(line.begin() + start, line.begin() + i);
	int one_idx = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == 1)
			one_idx = i;
	}
	int num = 1;
	while (num <= n) {
		if (line[(one_idx + num - 1) % n] == num) {
			num++;
		}
		else
			return false;
	}
	return true;
}

/*
 合法的出栈序列是很多的，无法穷举。
 只能模拟。
 */
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		line.clear();

		int tmp;
		int tmp2 = n;
		while (tmp2--) {
			cin >> tmp;
			line.push_back(tmp);
		}
		if (judge(line, n)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}
