#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main() {
	int i = 0;
	std::ios::sync_with_stdio(false);
    int a;
    cin>>a;
    cout<<a<<endl;
	return 0;
}


//
//#include<cstdio>
//#include<string>
//#include<iostream>
//#include<vector>
//using namespace std;
//string a;
//vector <string> k;
//int main() {
//	int i = 0;
//	std::ios::sync_with_stdio(false);
//	while (cin >> a) {
//		k.push_back(a);
//	}
//	for (int i = 0; i < k.size(); i++) {
//		for (int j = k[i].size() - 1; j >= 0; j--) {
//			cout << k[i][j];
//			if (j == 0 && (i != k.size() - 1)) cout << " ";
//			//if(j==0&&i==k.size()-1) cout<<'\n';
//		}
//	}
//
//
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
////考虑例子，[1,2,3],每个数字都可以作为BST的根节点。
//
//struct Node {
//	int val;
//	struct Node* left;
//	struct Node* right;
//};
//
//void preorder(Node* root) {
//	if (root) {
//		cout << root->val <<" ";
//		preorder(root->left);
//		preorder(root->right);
//	}
//}
//
//vector<Node*> construct_trees(int begin, int end) {
//	vector<Node*> roots;
//	if (begin > end) {
//		roots.push_back(NULL);
//		return roots;
//	}
//	for (int i = begin; i <= end; i++) {
//		vector<Node*> left_subtree_roots = construct_trees(begin, i - 1);
//		vector<Node*> right_subtree_roots = construct_trees(i + 1, end);
//		for (auto left_subtree_root : left_subtree_roots) {
//			for (auto right_subtree_root : right_subtree_roots) {
//				struct Node* root = new Node;
//				root->val = i;
//				root->left = left_subtree_root;
//				root->right = right_subtree_root;
//				roots.push_back(root);
//			}
//		}
//	}
//	return roots;
//}
//
//int main() {
//	vector<Node*> roots = construct_trees(1, 3);
//	for (auto root : roots) {
//		preorder(root);
//		cout << endl;
//	}
//	return 0;
//}