/*
1、数字转字符串：使用sprintf()函数

char str[10];
int a=1234321;
sprintf(str,"%d",a);
--------------------
char str[10];
double a=123.321;
sprintf(str,"%.3lf",a);
--------------------
char str[10];
int a=175;
sprintf(str,"%x",a);//10进制转换成16进制，如果输出大写的字母是sprintf(str,"%X",a)
--------------------
char *itoa(int value, char* string, int radix); 
同样也可以将数字转字符串，不过itoa()这个函数是平台相关的（不是标准里的），故在这里不推荐使用这个函数。

2、字符串转数字：使用sscanf()函数

char str[]="1234321";
int a;
sscanf(str,"%d",&a);
.............
char str[]="123.321";
double a;
sscanf(str,"%lf",&a);
.............
char str[]="AF";
int a;
sscanf(str,"%x",&a); //16进制转换成10进制

另外也可以使用atoi(),atol(),atof().
 
if((strlen(str)-i-1)%3==0&&i!=strlen(str)-1)
这一行判断对于正数还是负数意义是不一样的。正数不需考虑符号。负数需要考虑负号。式子是一样的。
http://www.cnblogs.com/luxiaoxun/archive/2012/08/03/2621803.html


*/

#include<cstdio>
#include<cstring>
char str[35];
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int c=a+b;
    bool isp=1;
    if(c<0) isp=0;
    sprintf(str,"%d",c);
    if(c==0) printf("0");
    else if(isp){
        for(int i=0;i<strlen(str);i++){
            printf("%c",str[i]);
            if((strlen(str)-i-1)%3==0&&i!=strlen(str)-1)
                printf(",");
        }    
    }
    else if(!isp){
        for(int i=0;i<strlen(str);i++){
            printf("%c",str[i]);
            if((strlen(str)-i-1)%3==0&&i!=strlen(str)-1&&i!=0)
                printf(",");
        }    
    }
    return 0;
}
