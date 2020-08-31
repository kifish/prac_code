/*


https://leetcode-cn.com/problems/missing-ranges/

vip 题


Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]


https://www.cnblogs.com/grandyang/p/5184890.html
这道题让我们求缺失区间，跟之前那道 Summary Ranges 很类似，给了一个空间的范围 [lower upper]，缺失的区间的范围需要在给定的区间范围内。遍历 nums 数组，假如当前数字 num 大于 lower，说明此时已经有缺失区间，至少缺失一个 lower 数字，此时若 num-1 大于 lower，说明缺失的是一个区间 [lower, num-1]，否则就只加入一个数字即可。由于 OJ 之后加入了许多 tricky 的 test cases，使得论坛上很多解法都 fail 了。其实很多是跪在了整型溢出，当数组中有整型最大值时，此时 lower 更新为 num+1 时就会溢出，所以在更新之前要先判断一下，若 num 已经是整型最大值了，直接返回结果 res 即可；否则才更新 lower 继续循环。for 循环退出后，此时可能还存在缺失区间，就是此时 lower 还小于等于 upper 时，可以会缺失 lower 这个数字，或者 [lower, upper] 区间，最后补上这个区间就可以通过啦，参见代码如下：


*/