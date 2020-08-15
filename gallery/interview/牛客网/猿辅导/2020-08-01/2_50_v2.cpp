#include<bits/stdc++.h>

typedef long long LL;
// or #define LL long long

using namespace std;


const int MOD = 1e9 + 3;
// const int MAXN = 1e5 + 5;
const int MAXN = 1e6 + 5;


int root_idx;
struct Node
{
    int val;
    vector<int> children;
}nodes[MAXN];


LL ret_opt;


// 先序遍历
// 左右根
LL cal_recur(int idx){
    LL ret = nodes[idx].val % MOD;

    for(auto child : nodes[idx].children){
        LL tmp = cal_recur(child);
        if(tmp > 0){
            tmp %= MOD;
            ret += tmp;
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
    while(cin>>n){   

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
        cal_recur(root_idx);
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



AC 50%


https://www.nowcoder.com/discuss/464541?type=post&order=create&pos=&page=0&channel=0&source_id=search_post


https://exam.nowcoder.com/cts/17086792/summary?id=F9BC69729C67A272

出题人的意思是自己的奖券也可以不选。 :)


这里给的解法是, root的奖券必须选, 必须从root出发。
https://blog.csdn.net/qq_22522375/article/details/107736641


看题意怎么理解了  :)


*/



