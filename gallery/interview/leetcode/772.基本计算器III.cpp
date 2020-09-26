/*


https://leetcode-cn.com/problems/basic-calculator-iii/

https://leetcode-cn.com/problems/basic-calculator-ii/solution/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-ji-/



Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.

这道题是基本计算器系列的第三道，前两道分别为 Basic Calculator 和 Basic Calculator II，
区别是，第一道只有加减法跟括号，第二道只有加减乘除法，而这第三道既有加减乘除法又有括号运算。
其实做过前两道题的话，那么这道题也就没什么问题，因为把前两道题的解法综合一下就是这道题的解法啦。
由于此题既有括号，又有乘除法，我们知道括号是优先级最高的，但是好就好在我们可以将括号里的内容当作一个整体调用递归函数来处理。
而其他部分，就跟第二道一模一样了。



*/