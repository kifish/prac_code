/*

https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/


https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-by-leetco/


二维二分

https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-by-leetco/


https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-by-leetco/472018

关于为什么二分查找最后返回的值一定在矩阵中

一开始看到通过二分法在矩阵元素的最大值和最小值之间查找恰好使小于等于该值的矩阵元素为k个的值，这个值即为所求结果的方法，觉得有可能查到的值不在矩阵元素中，但后来发现如果并不是一查到符合条件的值（小于等于该值的矩阵元素有k个）就返回，而是继续二分，直到上下界相等，然后返回此时的下界/上界，由于矩阵中均为整数，是可以保证查到的值在矩阵内且小于等于该值的矩阵元素恰好有k个的。

作者：shimura233
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/guan-yu-wei-shi-yao-er-fen-cha-zhao-zui-hou-fan-hu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



*/