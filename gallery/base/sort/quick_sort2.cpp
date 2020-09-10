#include<bits/stdc++.h>
using namespace std;

// AC

pair<int,int> partition(vector<int> & nums, int lo, int hi){
    int cur_idx = lo;
    int less_idx = lo;
    int greater_idx = hi;
    int pivot = nums[lo];
    while(cur_idx <= greater_idx){
        if(nums[cur_idx] < pivot){
            swap(nums[cur_idx], nums[less_idx]);
            less_idx++;
            cur_idx++;
        }
        else if(nums[cur_idx] > pivot){
            swap(nums[greater_idx], nums[cur_idx]);
            greater_idx--;
        }
        else{
            cur_idx++;
        }
    }
    return make_pair(less_idx,greater_idx);
}

// https://en.cppreference.com/w/cpp/utility/pair/make_pair

// 三路快排
void quick_sort(vector<int> & nums, int lo, int hi){
    if(lo >= hi){
        return;
    }

    pair<int,int> pivot_pair = partition(nums, lo, hi);
    int less_idx = pivot_pair.first; // 开区间,因此要-1
    int greater_idx = pivot_pair.second; // 闭区间,因此要+1
    quick_sort(nums, lo, less_idx-1);
    quick_sort(nums, greater_idx+1, hi);
}

void quick_sort(vector<int> & nums){
    quick_sort(nums, 0, (int)nums.size() - 1);
}

void pretty_print(vector<int> & nums){
    for(auto num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

/*
test
https://www.nowcoder.com/questionTerminal/508f66c6c93d4191ab25151066cb50ef

排序	2020-09-10	答案正确	3 ms	504K	C++    (三路快排)     
排序	2020-07-31	答案正确	5 ms	504K	C++    (两路快排)      

leetcode:
gallery/interview/leetcode/912. 排序数组.cpp
*/


int main(){
    int n;
    while(cin>>n){
        vector<int> nums;
        while(n--){
            int tmp;
            cin>>tmp;
            nums.push_back(tmp);
        }
        quick_sort(nums);
        pretty_print(nums);
    }
    return 0;
}