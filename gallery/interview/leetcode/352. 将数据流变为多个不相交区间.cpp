/*

https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/

https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/comments/652933

输入: 1 得到区间[1,1] ，因为只有一个数

输入: 1 3 得到区间[1,1] [3,3]，因为1和3之间没有数，所以是两个区间[1,1]和[3,3]

输入:1 3 7 得到区间[1,1] [3,3] [7,7]，因为区间不存在连续的数，所以无法进行合并，因此，这里是3个区间

输入:1 3 7 2 得到区间[1,3][7,7]，因为1 2 3是连续的，所以合并为一个区间[1,3]，还剩一个7是单独的一个区间[7,7]


https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/solution/bao-li-mei-xue-setyong-fa-by-qia-si-ming-yue-qing-/



*/