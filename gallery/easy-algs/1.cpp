#include<bits/stdc++.h>

using namespace std;

void pretty_print(vector<int> & v){
    for(auto val : v){
        cout<<val<<endl;
    }
}

/*
num_list = [1, 2, 2, 3]
有序

x = 2

查x出现次数？
*/


int binary_find(vector<int> & nums, int target){
    if(nums.size() == 0) return -1;

    int lo = 0; // 不要初始化成-1
    int hi = nums.size() - 1; // 不要初始化成nums.size()
    while(lo < hi){ // 为啥不会死循环？1 lo < hi; 2 mid always < hi; 3 lo = mid + 1 // 最后退出的状态一定是lo==hi // 另外用循环不变量来说明区间收缩的意义 
        int mid = (lo + hi) / 2;
        if(nums[mid] == target){
            hi = mid;
        }
        else if(nums[mid] > target){
            hi = mid;
        }
        else{ // nums[mid] < target
            lo = mid + 1;
        }
    }
    if(nums[lo] == target){ // 边界情况需要特判
        return lo;
    }
    else return -1;
}



int main(){
    return 0;
}

