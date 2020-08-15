/*

https://leetcode-cn.com/problems/read-n-characters-given-read4-ii-call-multiple-times/



vip 题


https://www.cnblogs.com/lowkeysingsing/p/11361473.html

read 方法：

通过使用 read4 方法，实现 read 方法。该方法可以从文件中读取 n 个字符并将其存储到缓存数组 buf 中。您 不能 直接操作文件。

返回值为实际读取的字符。

read 的定义：

参数: char[] buf, int n
返回值: int

注意: buf[] 是目标缓存区不是源缓存区，你需要将结果写入 buf[] 中。
 

示例 1：

File file("abc");
Solution sol;
// 假定 buf 已经被分配了内存，并且有足够的空间来存储文件中的所有字符。
sol.read(buf, 1); // 当调用了您的 read 方法后，buf 需要包含 "a"。 一共读取 1 个字符，因此返回 1。
sol.read(buf, 2); // 现在 buf 需要包含 "bc"。一共读取 2 个字符，因此返回 2。
sol.read(buf, 1); // 由于已经到达了文件末尾，没有更多的字符可以读取，因此返回 0。
Example 2:

File file("abc");
Solution sol;
sol.read(buf, 4); // 当调用了您的 read 方法后，buf 需要包含 "abc"。 一共只能读取 3 个字符，因此返回 3。
sol.read(buf, 1); // 由于已经到达了文件末尾，没有更多的字符可以读取，因此返回 0。
注意：

你 不能 直接操作该文件，文件只能通过 read4 获取而 不能 通过 read。
read  函数可以被调用 多次。
请记得 重置 在 Solution 中声明的类变量（静态变量），因为类变量会 在多个测试用例中保持不变，影响判题准确。请 查阅 这里。
你可以假定目标缓存数组 buf 保证有足够的空间存下 n 个字符。 
保证在一个给定测试用例中，read 函数使用的是同一个 buf。




*/