/*

https://leetcode-cn.com/problems/one-edit-distance/

vip 题


[LeetCode] 161. One Edit Distance 一个编辑距离
 

Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
 

这道题是之前那道 Edit Distance 的拓展，然而这道题并没有那道题难，这道题只让我们判断两个字符串的编辑距离是否为1，那么只需分下列三种情况来考虑就行了：

1. 两个字符串的长度之差大于1，直接返回False。

2. 两个字符串的长度之差等于1，长的那个字符串去掉一个字符，剩下的应该和短的字符串相同。

3. 两个字符串的长度之差等于0，两个字符串对应位置的字符只能有一处不同。

分析清楚了所有的情况，代码就很好写了，参见如下：





https://www.cnblogs.com/grandyang/p/5184698.html


*/