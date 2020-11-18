#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

// simple
/*
LL max_sum(vector<int> nums){
    // corner case
    if(nums.size() == 0) return 0;

    // init
    vector<LL> exclueded_max_sum = vector<LL> (nums.size(), 0);

    vector<LL> inclueded_max_sum = vector<LL> (nums.size(), 0);
    for(int i = 0;i < nums.size(); i++){
        inclueded_max_sum[i] = nums[i];
    }

    // dp
    for(int i = 1; i< nums.size(); i++){
        inclueded_max_sum[i] = nums[i] + exclueded_max_sum[i-1];
        exclueded_max_sum[i] = max(inclueded_max_sum[i-1], exclueded_max_sum[i-1]);
    }

    return max(inclueded_max_sum.back(), exclueded_max_sum.back());
}
*/



// optimized
LL max_sum(vector<int> nums){
    // corner case
    if(nums.size() == 0) return 0;

    // init
    LL exclueded_max_sum = 0;
    LL inclueded_max_sum = nums[0];
    LL next_inclueded_max_sum = 0;

    // dp
    for(int i = 1; i< nums.size(); i++){
        next_inclueded_max_sum = nums[i] + exclueded_max_sum;
        exclueded_max_sum = max(inclueded_max_sum, exclueded_max_sum);
        // update
        inclueded_max_sum = next_inclueded_max_sum;
    }

    return max(inclueded_max_sum, exclueded_max_sum);
}


int main() {
	std::ios::sync_with_stdio(false);
    int n;
    int x;
    cin>>n;
    vector<int> nums;
    while (n--){   
        cin>>x;
        nums.push_back(x);
    }
    
    LL ret = max_sum(nums);
    cout<<ret<<endl;
	return 0;
}

/* test data
➜  c++_code g++ solution.cpp -o buf
➜  c++_code ./buf             
5
2 3 4 5 6
12
➜  c++_code ./buf
4
-1 10 -1 2
12
➜  c++_code ./buf
4
-1 10 2 -1
10
*/






