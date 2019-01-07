http://algorithm.openjudge.cn/200602/4/


https://blog.csdn.net/qq_36306833/article/details/55504978

原题的要求为啥可以等价地转化为求逆序对？
原题的是交换相邻的序列而不是相邻的两个数。非相邻的两个数可以直接交换吗？
比如2 3 1.
想交换2 和 1，那么可以交换“2 3”和“1”变为1 2 3，这样虽然3的位置没有固定，但仍然是把2 和 1 这个逆序对消除了。
因此还是可以等价的，最少的交换次数就等于逆序对个数。

http://bailian.openjudge.cn/practice/2299/

注意这道题一开始数组开小了，报的错竟然是TLE。改了数组大小，就AC了。

```C
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int num[500005];
typedef long long LL;
//merge_sort 交换的次数就等于逆序对！
LL merge_sort(int a[],int lo,int hi){
    if(lo == hi)
        return 0;
    int mid = (lo + hi) / 2;
    LL sum_inv = 0;
    sum_inv += merge_sort(a,lo,mid);
    sum_inv += merge_sort(a,mid+1,hi);
    int i = lo,j = mid+1;
    int *buf = new int[hi- lo + 1];
    int idx = 0;
    while(i <= mid && j<= hi){
        if(a[i] <= a[j]){
            buf[idx++] = a[i++];
        }
        else{
            sum_inv += mid - i + 1;
            buf[idx++] = a[j++];
        }
    }
    while(i <= mid) buf[idx++] = a[i++];
    while(j <= hi) buf[idx++] = a[j++];
    for(i = lo;i<=hi;i++) a[i] = buf[i - lo];
    return sum_inv;
}

LL cal(int a[],int lo,int hi){
    return merge_sort(a,lo,hi);
}

int main(){
    int n;
    while(scanf("%d",&n) == 1 && n){
        for(int i = 0;i<n;i++)
            scanf("%d",&num[i]);
        printf("%lld\n",cal(num,0,n-1));
    }
    return 0;
}
```

