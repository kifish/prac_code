https://blog.csdn.net/m0_37975647/article/details/77505390



http://algorithm.openjudge.cn/200601/1/
http://dsalgo.openjudge.cn/string/2/

看清题目要求。

C程序的注释用/*...*/来表示。请写一个程序，将输入的C程序源代码中的注释去掉，输出去掉注释之后的源代码。

用于测试的C代码保证符合语法，不使用C++的//注释语法。

注意，C语言不允许出现嵌套注释。具体来说，对于/*/**/"*/"，如果不允许嵌套注释，那么它表示字符串"*/"；如果允许嵌套注释，它表示一个引号"。

还请注意，字符串中出现的注释符/*属于字符串的一部分，注释中出现的双引号"属于注释的一部分。


搞清楚转义的规则即可。这道题用getchar输入反而简单。



```C
#include <cstdio>

int main(){
    int ch;
    while ((ch = getchar()) != EOF){
        if(ch == '/'){
            int ch1 = getchar();
            if(ch1 == '*'){
                int ch2 = getchar();
                int ch3 = getchar();
                //不允许嵌套定义的意思是，遇到第一个配对*/即停止
                while(!(ch2 == '*' && ch3 == '/')){
                    ch2 = ch3;
                    ch3 = getchar();
                }
            }
        }
        //判断是否是单引号（c语言中使用单引号必须转义）或者是双引号
        else if(ch == '\'' || ch == '"'){
            putchar(ch);
            int next;
            while ((next = getchar()) != ch){
                putchar(next);
                if(next == '\\') putchar(getchar());//有可能出现"\\"abc\\""，中间的引号要输出。
            }
            putchar(next);//输出配对的单引号或者是双引号
        }
        else putchar(ch);
    }
    return 0;
}
```