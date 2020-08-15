#include<bits/stdc++.h>

typedef long long LL;
// or #define LL long long

using namespace std;




const int MOD = 1e9 + 3;
const int MAXN = 1e5 + 5;


int root_idx;
int n;
struct Node
{
    int val;
    vector<int> children;
}nodes[MAXN];


int ret_opt;

void cal(int root_idx){
    cal_recur(root_idx);
}


int cal_recur(int idx){
    int ret = nodes[idx].val % MOD;

    for(auto child : nodes[idx].children){
        int tmp = cal_recur(child) % MOD;
        if(tmp > 0){
            ret += tmp % MOD;
            ret %= MOD;
        }
    }

    ret_opt = max(ret_opt, ret);
    return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
    int n;
    Node tmp;
    while (cin>>n){   

        for(int i = 1;i<=n;i++){
            nodes[i].children.clear();
        }

        for(int i = 1;i<=n;i++){
            int val;
            int from;
            cin>>val>>from;
            nodes[i].val = val;
            if(from == 0){
                root_idx = i;
            }
            else{
                from = from - 1;
                nodes[from].children.push_back(i);
            }
        }
        ret_opt = INT_MIN;
        cal(root_idx);
        cout<<ret_opt<<endl;
    }
	return 0;
}

/*

3
2 0
1 2
-1 2





3

*/



