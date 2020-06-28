/*
如果找中位数, 假设只有一个数组, 且这个数组的数的个数是2k+1
那么中位数就是第k+1个数, 比中位数小的数的个数为k个。

只要我们找到k个比中文数小的数, 中位数也就可以确定了。

一个有序数组是很容易做到的。

在2个有序数组里找中位数也是大致的思路


https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/411176

建议看看这个解答: 
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/105344

https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/377751


[2 3 5]

[1 4 7 9]

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2,nums1);
        // 保证m <= n
        int cnt = (m + n + 1) / 2; //小于等于中位数的数的个数
        int lo = 0;
        int hi = m; // not m - 1
        while(lo < hi){
            int mid = (lo + hi) / 2;//mid是nums1中分界线右边的第一个数的index;如果分界线正好分在一个数上, 则把这个数再复制一份, 左边集合有这一个数, 右边集合也有这个数
            int k = cnt - mid;//k是nums2中分界线右边的第一个数的index; 也可以认为是num2中分界线左边的数的个数
            if(nums1[mid] < nums2[k-1]){ // nums1[mid] : Rmin1;nums2[k-1] : Lmax2
                lo = mid + 1; // 说明这个分界线要往右边移动一点; 想象一下把2个数组分成了4个部分, 不想让第二个数组左边部分和第一个数组右边部分出现重叠
            }
            else if(nums1[mid] > nums2[k-1]){ // Rmin1 > Lmax2
                hi = mid; //mid符合要求，并继续缩小范围
            }
            else // Rmin1 == Lmax2 ; 最终追求的状态是 Lmax1<=Rmin2，Lmax2<=Rmin1
                hi = mid; //mid符合要求，并继续缩小范围
        }
        int m1 = lo;//nums1中大于（奇数个数的情况）或等于（偶数个数的情况）中位数的第一个数的index
        int m2 = cnt - m1;//nums2中大于（奇数个数的情况）或等于（偶数个数的情况）中位数的第一个数的index
        int c1 = max(m1==0? INT_MIN:nums1[m1-1], m2==0?INT_MIN:nums2[m2-1]); // max(Lmax1, Lmax2)
        if((m+n)%2 ==1) return c1;
        int c2 = min(m1 == m ? INT_MAX: nums1[m1],
                      m2 == n ? INT_MAX : nums2[m2]); // min(Rmin1, Rmin2)
        return (c1+c2) / 2.0 ;
        
    }
};