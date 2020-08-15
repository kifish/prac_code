//pass
// class Solution
// {
//     int abs(int a, int b)
//     {
//         if (a > b)
//             return a - b;
//         else
//             return b - a;
//     }

// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         int m = (int)nums.size() - k;
//         int lo = 0, hi = (int)nums.size() - 1;
//         // int mid = (lo + hi) / 2;
//         while (lo <= hi)
//         {
//             int idx = partition(nums, lo, hi);
//             if (m < idx)
//             {
//                 hi = idx - 1;
//             }
//             else if (m > idx)
//             {
//                 lo = idx + 1;
//             }
//             else
//             {
//                 return nums[idx];
//             }
//         }
//         return -1; //不会进入该分支
//     }
//     int partition(vector<int> &nums, int lo, int hi)
//     {
//         //特判
//         if (lo == hi - 1)
//         {
//             if (nums[lo] <= nums[hi])
//             {
//                 return lo;
//             }
//             else
//             {
//                 swap(nums[lo], nums[hi]);
//                 return lo;
//             }
//         }

//         swap(nums[lo], nums[(lo + hi) / 2]);
//         int pivot = nums[lo];
//         int i = lo + 1;
//         int j = hi;
//         while (i <= j)
//         { //这里是i<=j 不是 i<j;举例 对[2,1,3]partition
//             while (i < hi && nums[i] <= pivot)
//                 i++;
//             while (j > lo && nums[j] >= pivot)
//                 j--;
//             if (i < j)
//                 swap(nums[i++], nums[j--]);
//             else
//                 break;
//         }
//         swap(nums[lo], nums[j]); //当lo = hi - 1的时候，这么写会出错。
//         return j;
//     }

//     int smallestDistancePair(vector<int> &nums, int k)
//     {
//         vector<int> dists;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 dists.push_back(abs(nums[i], nums[j]));
//             }
//         }
//         return findKthLargest(dists, dists.size() - k + 1); //TLE
//     }
// };


class Solution {
    int abs(int a,int b){
        if(a > b) return a -b;
        else return b - a;
    }
public:
    int kth(vector<int> &nums, int k, int lo, int hi){
    int idx = partition(nums, lo, hi);
    if (idx == k - 1)
        return nums[idx];
    else if (idx > k - 1)
    {
        return kth(nums, k, lo, idx - 1);
    }
    else
    {
        return kth(nums, k - (idx + 1), idx + 1, hi);
    }
}

//wrong
int partition(vector<int> &nums, int lo, int hi)
{   
        if (lo == hi - 1)  //特判
        {
            if (nums[lo] <= nums[hi])
            {
                return lo;
            }
            else
            {
                swap(nums[lo], nums[hi]);
                return lo;
            }
        }
    int mid = (lo + hi) / 2;
    int pivot = nums[mid];
    swap(nums[mid], nums[lo]);
    int i = lo + 1;
    int j = hi;
    while (i <= j)
    {
        while (nums[i] <= pivot && i < hi)
            i++;
        while (nums[j] > pivot && j > lo)
            j--;
        if (i < j)
        {
            swap(nums[i++], nums[j++]);
        }
        else break;
    }
    int idx = j;
    swap(nums[lo], nums[idx]);
    return idx;
}


    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> dists;
        for(int i =0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                dists.push_back(abs(nums[i],nums[j]));
            }
        }
        return kth(dists,k,0,(int) dists.size() -1);
        
        //nth_element(dists.begin(),dists.begin()+k,dists.end());
        //return dists[k-1];
    }
};

// http://www.cplusplus.com/reference/algorithm/nth_element/
