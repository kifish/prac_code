#include<stdio.h>
#include<string.h>
#define maxn 20
int a[maxn][maxn];
int main()
{
    int n,x,y,tot = 0; 
    scanf("%d", &n);
    memset(a, 0, sizeof(a));  //初始化数组
    tot = a[x=0][y=n-1] = 1;
    while(tot < n*n) //实际上tot的最大值为n^2,对应++tot 
    {
        while(x+1<n && !a[x+1][y])  a[++x][y] = ++tot;//先改变再判断是否移动 
        while(y-1>=0 && !a[x][y-1])  a[x][--y] = ++tot;//此处可以将"<n"理解为"<=n-1", 
        while(x-1>=0 && !a[x-1][y])  a[--x][y] = ++tot;//n-1是二维数组的边界 
        while(y+1<n && !a[x][y+1])   a[x][++y] = ++tot;//对应填字顺序 
    }
    for(x=0; x<n; x++)
    {
        for(y=0; y<n; y++) printf("%3d", a[x][y]); //%3d 为了空格 
        printf("\n");
    }
    return 0;
}
