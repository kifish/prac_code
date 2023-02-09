#include<bits/stdc++.h>

using namespace std;

/*
test

https://www.nowcoder.com/questionTerminal/508f66c6c93d4191ab25151066cb50ef



*/

// AC 
// int partition(vector<int> & nums, int lo, int hi){
//     if(lo == hi) return lo;

//     int pivot = nums[lo];
//     int i = lo;
//     int j = hi + 1;
//     while(i < j){
//         i++; 
//         j--; 
//         while(nums[i] < pivot && i < hi) i++; // nums[i] < pivot 加了等号会出现bug; 具体如何优化相等的数过多的情况见三路快排
//         while(nums[j] > pivot && j > lo) j--; // nums[j] > pivot 加了等号会出现bug; 具体如何优化相等的数过多的情况见三路快排

//         if(i < j){
//             swap(nums[i], nums[j]);
//         }
//         else break;
//         // nums[lo-i) 必然 <= pivot
//         // nums(j, hi] 必然 >= pivot
//     }

//     swap(nums[lo], nums[j]);
//     return j;
// }

// WA
// int partition(vector<int> & nums, int lo, int hi){
//     if(lo == hi) return lo;

//     int pivot = nums[lo];
//     int i = lo;
//     int j = hi + 1;
//     while(i < j){
//         i++; 
//         j--; 
//         while(nums[i] < pivot && i < j) i++; // 加了等号会出现bug; 具体如何优化相等的数过多的情况见三路快排
//         while(nums[j] > pivot && j > i) j--; // 加了等号会出现bug; 具体如何优化相等的数过多的情况见三路快排
//     i<j 和 j>i 会导致交界处有点问题
//     就拿j > i 举例, 如果出现一种情况 nums[j] > pivot 且j == i, 然后j不会-1, 接着往下执行的时候循环break, 导致实际返回了j, 而此时nums[j] > pivot 导致出错
//         if(i < j){
//             swap(nums[i], nums[j]);
//         }
//         else break;
//         // nums[lo-i) 必然 <= pivot
//         // nums(j, hi] 必然 >= pivot
//     }

//     swap(nums[lo], nums[j]);
//     return j;
// }
// bug case举例
// 1 0 0 0 0 0 2 2
// 做第一次交换的时候
// 1 0 0 0 0 0 2 2
//             i j
// 完成交换  
// 1 0 0 0 0 0 2 2
// 下一次循环
// 1 0 0 0 0 0 2 2
//             j i

// 2 0 0 0 0 0 1 2
// 出现bug



// AC
int partition(vector<int> & nums, int lo, int hi){
    if(lo == hi) return lo;

    int pivot = nums[lo];
    int i = lo;
    int j = hi + 1;
    while(i < j){
        i++; 
        j--; 
        while(nums[i] < pivot && i <= j && i < hi) i++; // 加了等号会出现bug; 具体如何优化相等的数过多的情况见三路快排; WA: i <= j
        while(nums[j] > pivot && j >= i) j--; // 加了等号会出现bug; 具体如何优化相等的数过多的情况见三路快排

        if(i < j){
            swap(nums[i], nums[j]);
        }
        else break;
        // nums[lo-i) 必然 <= pivot
        // nums(j, hi] 必然 >= pivot
    }

    swap(nums[lo], nums[j]);
    return j;
}





void quick_sort(vector<int> & nums, int lo, int hi){
    if(lo >= hi) return;

    int pivot_idx = partition(nums, lo, hi);
    quick_sort(nums, lo, pivot_idx - 1);
    quick_sort(nums, pivot_idx + 1, hi);
}

void quick_sort(vector<int> & nums){
    if(nums.size() == 0) return;

    quick_sort(nums, 0, nums.size() - 1);
}

void pretty_print(vector<int> & nums){
    for(auto num : nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

// 三路快排见: base/sort/快排.md; 这里三路的意思是指三个指针

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
        // sort(nums.begin(), nums.end());
        pretty_print(nums);
    }
    return 0;
}
