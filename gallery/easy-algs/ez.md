
约分最简分式  

```c
#include<stdio.h>
int gcd(int a,int b){
    while(b){
        int temp=a%b;
        a=b;
         b=temp;
    }    
    return a;
}
int main(){
    int a,b;
    scanf("%d/%d",&a,&b);
    int tmp;
    while((tmp=gcd(a,b))!=1){
        a/=tmp;
        b/=tmp;
    }
    printf("%d/%d",a,b);
    return 0;
} 

```





有时候人们用四位数字表示一个时间，比如1106表示11点零6分。现在，你的程序要根据起始时间和流逝的时间计算出终止时间。
读入两个数字，第一个数字以这样的四位数字表示当前时间，第二个数字表示分钟数，计算当前时间经过那么多分钟后是几点，结果也表示为四位数字。当小时为个位数时，没有前导的零，即5点30分表示为530。注意，第二个数字表示的分钟数可能超过60，也可能是负数。
输入格式：
输入在一行中给出2个整数，分别是四位数字表示的起始时间、以及流逝的分钟数，其间以空格分隔。注意：在起始时间中，当小时为个位数时，没有前导的零，即5点30分表示为530；流逝的分钟数可能超过60，也可能是负数。
输出格式：
输出四位数字表示的终止时间。题目保证起始时间和终止时间在同一天内。
输入样例：
1120 110
 
输出样例：
1310 





```c

#include<cstdio>
#include<cmath>
int main(){
    int timest,hourst,minst,dt,k;
    while(scanf("%d %d",&timest,&dt)!=EOF){
        hourst = timest/100;
        minst = timest%100;
        dt+=minst;
        if(dt>0){
        k = dt/60;
        dt = dt%60;
        hourst +=k;
        printf("%d%02d",hourst,dt); 
        }
        else if(dt<0){
            dt = (int)fabs(dt);
            k = dt/60;
            dt = dt%60;
            hourst -=k;
            hourst--;
            dt = 60-dt;
        printf("%d%02d",hourst,dt); 
        
        }
        else {printf("%d%02d",hourst,dt); }
    }
    return 0;
} 


```
```c
```
```c
```
```c
```
```c
```



```c
```


```c
```


```c
```


```c
```


```c
```
