/*

https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1031/


https://leetcode-cn.com/problems/russian-doll-envelopes/


https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-di-zeng-zi-xu-lie-kuo-zhan-dao-er-wei-er/

这个方法不能拓展到三维及以上的情况

其实这种问题还可以拓展到三维，比如说现在不是让你嵌套信封，而是嵌套箱子，每个箱子有长宽高三个维度，请你算算最多能嵌套几个箱子？

我们可能会这样想，先把前两个维度（长和宽）按信封嵌套的思路求一个嵌套序列，最后在这个序列的第三个维度（高度）找一下 LIS，应该能算出答案。

实际上，这个思路是错误的。这类问题叫做「偏序问题」，上升到三维会使难度巨幅提升，需要借助一种高级数据结构「树状数组」，有兴趣的读者可以自行搜索。

作者：labuladong
链接：https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-di-zeng-zi-xu-lie-kuo-zhan-dao-er-wei-er/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

LIS nlogn 解法:

gallery\动态规划\数列dp\LIS\最长递增子序列.md

*/



class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

    }
};

// https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-di-zeng-zi-xu-lie-kuo-zhan-dao-er-wei-er/434112

