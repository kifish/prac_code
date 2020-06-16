class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2,nums1);
        // 保证m <= n
        int cnt = (m + n + 1) / 2; //小于等于中位数的数的个数
        int lo = 0;
        int hi = m;
        while(lo < hi){
            int mid = (lo + hi) / 2;//mid是nums1中分界线右边的第一个数的index
            int k = cnt - mid;//k是nums2中分界线右边的第一个数的index
            if(nums1[mid] < nums2[k-1]){
                lo = mid + 1;
            }
            else if(nums1[mid] > nums2[k-1]){
                hi = mid; //mid符合要求，并继续缩小范围
            }
            else
                hi = mid; //mid符合要求，并继续缩小范围
        }
        int m1 = lo;//nums1中大于（奇数个数的情况）或等于（偶数个数的情况）中位数的第一个数的index
        int m2 = cnt - m1;//nums2中大于（奇数个数的情况）或等于（偶数个数的情况）中位数的第一个数的index
        int c1 = max(m1==0? INT_MIN:nums1[m1-1], m2==0?INT_MIN:nums2[m2-1]);
        if((m+n)%2 ==1) return c1;
        int c2 = min(m1 == m ? INT_MAX: nums1[m1],
                      m2 == n ? INT_MAX : nums2[m2]);
        return (c1+c2) / 2.0 ;
        
    }
};