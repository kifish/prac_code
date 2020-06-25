


// 88. 合并两个有序数组

// 来自 <https://leetcode-cn.com/problems/merge-sorted-array/> 


// 从大到小合并是最佳解法。



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        int idx = 0;
        vector<int> buf(m+n,0);
        while(i < m && j < n){
            if(nums1[i] < nums2[j]) buf[idx++] = nums1[i++];
            else if(nums1[i] > nums2[j]) buf[idx++] = nums2[j++];
            else buf[idx++] = nums2[j++];
        }
        int tmp = m;
        int shift = idx - i;
        while(i<tmp && shift > 0){
            nums1[tmp -1 + shift] = nums1[tmp-1];
            tmp--;
        }
        for(int k = 0;k<idx;k++) nums1[k] = buf[k];
        while(j<n){
            nums1[idx++] = nums2[j++]; 
        }
    }
};