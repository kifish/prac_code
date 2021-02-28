/*

https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/


给定字符串s="abcdefghijklmnopqrstuvwxyzabcd..."

输入一个字符串 p，输出 p 的子串的数量，满足条件
1，子串同时是 s 的子串
2，重复的子串不计数
3，子串在 p 中是连续的
4，子串在 s 中是连续的
5，子串是非空的

注意：p 不是无限循环字符串的根

举例
输入 p="a"，p 的子串有 "", "a"
满足条件的子串的数量是 1

输入 p="cac"，p的子串有 "", "c", "a", "ca", "ac", "cac"
满足条件的子串的数量是 2，也就是说 "ca"、"ac"、"cac"不是 s 的子串

输入 p="zab"，p的子串有 "", "z", "a", "b", "za", "ab", "zab"
满足条件的子串的数量是 6，也就是说 "z", "a", "b", "za", "ab", "zab" 都是 s 的子串

https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/comments/546182


s是给定的

唯一的输入是p

https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/solution/xi-fa-dai-ni-xue-suan-fa-yi-ci-gao-ding-qian-zhui-/


DP:
https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/solution/dong-tai-gui-hua-c-by-lcoder55455-y3px/




*/