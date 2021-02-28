/*

https://leetcode-cn.com/problems/number-complement/


计算机组成原理


https://leetcode-cn.com/problems/number-complement/solution/yi-huo-by-im-me/


class Solution {
public:
    int findComplement(int num) {
        int n=num,cnt=0;
        while(n){++cnt;n>>=1;}
        return num^((long)(1<<cnt)-1);
    }
};

作者：YBvOYoQ2q9
链接：https://leetcode-cn.com/problems/number-complement/solution/shuang-bai-by-ybvoyoq2q9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

补数和补码不是一个概念。

给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。

x取反只需要x与同位数的11111相加即可得到。这里的补数就是指反码。

https://leetcode-cn.com/problems/complement-of-base-10-integer/












https://zh.wikipedia.org/wiki/%E8%A1%A5%E6%95%B0#2%E8%BF%9B%E5%88%B6%E7%9A%84%E4%B8%BE%E4%BE%8B

https://zh.wikipedia.org/w/index.php?title=%E4%BA%8C%E8%A3%9C%E6%95%B8&useFormat=mobile&variant=zh-sg
另外，补码系统的0就只有一个表示方式，这和反码系统不同（在反码系统中，0有二种表示方式），因此在判断数字是否为0时，只要比较一次即可。


正数和0的补码就是该数字本身。负数的补码则是将其对应正数按位取反再加1。

在n位元的补码加减法中，忽略第n+1个位元的作法在各种有号数加法下都适用（不过在判断是否溢出（overflow）时，仍然会用到第n+1个位元）。因此在补码的系统，加法电路就可以处理有负数的加法，不需另外处理减法的电路。而且，只要有电路负责数字的变号（例如将1变换为 -1），也可以用加法电路来处理减法。而数字的变号就用计算数字的补码来完成。





*/