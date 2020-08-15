/*

https://leetcode-cn.com/problems/numbers-with-repeated-digits/solution/zui-kuai-zui-qing-xi-de-jie-fa-by-woodnote/

给定正整数 N，返回小于等于 N 且具有至少 1 位重复数字的正整数的个数。

先看这个理解:
https://leetcode-cn.com/problems/numbers-with-repeated-digits/solution/shu-wei-dp-by-bruceyuj/


对于第二种情况，total的是包含部分重复的情况，也就是第 ii 位的选择不能和前面已定的位数数字重复，因此我们需要剔除掉。
啥意思呢, 比如说这个N是 3367
那么33xx 就必然不满足条件了
只需要考虑到3[0-2]xx即可

实现可以看看这个:

https://leetcode-cn.com/problems/numbers-with-repeated-digits/solution/0msdai-ma-shu-wei-dpmo-ban-ti-by-aleix/

*/


class Solution {
public:
    int numDupDigitsAtMostN(int N) {

    }
};