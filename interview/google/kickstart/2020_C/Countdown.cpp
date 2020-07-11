#include<bits/stdc++.h>
using namespace std;

// 并查集

// int count(vector<int> & nums, int k){
//     unordered_set<int> unique_nums;
//     for(auto num : nums){
//         unique_nums.insert(num);
//     }

//     int ret = 0;
//     for(auto num : unique_nums){ // 要去重
//         if(unique_nums.count(num -1) == 0){
//             int cur_num = num + 1;
//             int cur_len = 1;
//             while(unique_nums.count(cur_num)){
//                 cur_len++;
//                 cur_num++;
//             }
//             if(cur_len >= k){
//                 ret += cur_len - k + 1;
//             }
//         }
//     }
//     return ret;
// }

// 看清题意, 这个里面是要求有序的

// 双AC

int count(vector<int> & nums, int k){
    int ret = 0;
    for(int i = 0;i<nums.size();){
        if(nums[i] == k){
            int target = k -1;
            while(i+1 < nums.size() && nums[i+1] == target){
                target--;
                i++;
            }
            if(target == 0){
                ret++;
            }
            i++;
        }
        else{
            i++;
        }
    }
    return ret;
}



int main(){
    int case_num = 0;
    cin>>case_num;
    vector<int> nums;
    for(int i = 1;i<=case_num;i++){
        int n,tmp;
        cin>>n;
        int k;
        cin>>k;
        nums.clear();
        while(n--){
            cin>>tmp;
            nums.push_back(tmp);
        }
        int ret = count(nums,k);
        cout<<"Case #"<<i<<": "<<ret<<endl;
    }
}