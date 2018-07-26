#include<stdio.h>
#include<string.h>
int main()
{
    int count = 0;
    char s[20], buf[99];//buf可以保存字符个数为98的字符串 
    scanf("%s", s);
    for(int abc = 111; abc<=999; abc++)
        for(int de= 11; de<=99; de++)
        {
            int x=abc*(de%10), y=abc*(de/10), z=abc*de;
            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);//printf输出到屏幕，fprintf输出到文件 
            int ok= 1;                                  //sprintf输出到字符串 
            for(int i = 0; i<strlen(buf); i++)//strlen计算字符个数，不包括结束标记"\0" 
                if(strchr(s, buf[i]) == NULL) ok = 0;   //strchr 在字符串中查找单个字符 
            if(ok)
            {
                printf("<%d>\n", ++count);              //'X'表示乘号 
                printf("%5d\nX%4d\n-----\n%5d\n%4d \n-----\n%5d\n\n", abc, de, x, y, z);
            }                                          //"%5d"表示按照5位数打印，不足5位 
        }                                               //在前面补空格                
    printf("The number of solutions = %d\n", count);
    return 0;
} 
