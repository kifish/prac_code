#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

typedef long long LL;

using namespace std;


// input:
// 4
// 2 3 6 9
// output:
// 20
// 2 6 3 9

// 4
// 3 6 2 9
// 20
// 3 9 2 6

vector< LL> nums;
vector< LL> raw_nums;

LL abs_dis( LL a, LL b){
    if(a > b){
        return a - b;
    }
    else{
        return b - a;
    }
}

// shit code
// void insert(vector<LL>& a,LL idx,LL v){
//     vector<LL> tmp;
//     for(LL i = idx;i<a.size();i++){
//         tmp.push_back(a[i]);
//     }
//     a[idx] = v;
//     for(LL i = 0;i<tmp.size();i++){
//         a.push_back(tmp[i]); #这里不应该是push_back
//     }
//shoule be:
        // for(int i = idx+1;i<a.size();i++){
        //     a[i] = tmp[i - (idx+1)];
        // }
//     for(auto v : a){
//         cout<<v<<" ";
//     }
//     cout<<endl;
// }

// work
void insert(vector<LL>& a,int idx,LL v){
    vector<LL> tmp;
    for(int i = idx;i<a.size();i++){
        tmp.push_back(a[i]);
    }
    a[idx] = v;
    for(int i = idx+1;i<a.size();i++){
        a[i] = tmp[i - (idx+1)];
    }
    a.push_back(tmp.back());
}

vector<LL> insert_s(vector<LL>& a,int idx,LL v){
    vector<LL> ret;
    for(int i = 0;i<a.size();i++){
        if(i != idx){
            ret.push_back(a[i]);
        }
        else{
            ret.push_back(v);
            ret.push_back(a[i]);
        }
    }
    return ret;
}

int main() {
	LL i = 0;
	std::ios::sync_with_stdio(false);
    LL n;
    LL x;
    cin>>n;
    while (n--)
    {   cin>>x;
        raw_nums.push_back(x);
    }
    
    nums.push_back(raw_nums[0]);
    nums.push_back(raw_nums[0]);
    for(int i = 1;i<raw_nums.size();i++){
        LL max_v = -1;
        int idx = 0;
        LL cur_num = raw_nums[i];
        for(int j = 1;j<nums.size();j++){
            LL v = 0;
            v = abs_dis(nums[j-1], cur_num) + abs_dis(nums[j],cur_num) - abs_dis(nums[j-1],nums[j]);
            if(v > max_v){
                max_v = v;
                idx = j;
            }
        }
        // cout<<"in:"<<idx<<" "<<cur_num<<endl;
        // nums = insert_s(nums,idx,cur_num); // good
        insert(nums,idx,cur_num); 
    }
    LL ret = 0;
    for(int i = 0;i<nums.size()-1;i++){
        ret += abs_dis(nums[i],nums[i+1]);
    }
    cout<<ret<<endl;
    for(int i = 0;i<nums.size()-1;i++){
        if(i != 0)
            cout<<" ";
        cout<<nums[i];
    }
    // cout<<a<<endl;
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
//LL main() {
//	LL i = 0;
//	std::ios::sync_with_stdio(false);
//	while (cin >> a) {
//		k.push_back(a);
//	}
//	for (LL i = 0; i < k.size(); i++) {
//		for (LL j = k[i].size() - 1; j >= 0; j--) {
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
//	LL val;
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
//vector<Node*> construct_trees(LL begin, LL end) {
//	vector<Node*> roots;
//	if (begin > end) {
//		roots.push_back(NULL);
//		return roots;
//	}
//	for (LL i = begin; i <= end; i++) {
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
//LL main() {
//	vector<Node*> roots = construct_trees(1, 3);
//	for (auto root : roots) {
//		preorder(root);
//		cout << endl;
//	}
//	return 0;
//}