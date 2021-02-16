/*

https://leetcode-cn.com/problems/water-and-jug-problem/


有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/water-and-jug-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


算水的总量 + gcd
https://leetcode-cn.com/problems/water-and-jug-problem/solution/cyu-yan-shu-xue-jie-fa-tai-xiu-liao-dai-ma-jian-ji/


BFS 只考虑 倒水 或者 加水 对应的水的总量
https://leetcode-cn.com/problems/water-and-jug-problem/solution/hu-dan-long-wei-liang-zhang-you-yi-si-de-tu-by-ant/




*/