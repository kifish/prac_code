TLE

```C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int num[50000+1];
int dp_from_left[50000 + 1];
int dp_from_right[50000 + 1];
int sum[50000+1];
int main() {
    int t;
    scanf("%d",&t);
        while (t--){
        int n;
        scanf("%d",&n);
        dp_from_right[n+1] = 0;
        dp_from_left[0] = 0;
        sum[0] = 0;
        for(int i = 1;i<=n;i++){
            scanf("%d",&num[i]);
            sum[i] = sum[i-1] + num[i];
        }
        for(int i = 1;i<=n;i++){
            int max_sum;
            for(int j = i;j<=n;j++){
                if(j == i) {
                    max_sum = sum[j] - sum[i-1];
                }
                else{
                    if(max_sum < sum[j] - sum[i-1]){
                        max_sum = sum[j] - sum[i-1];
                    }
                }
            }
            dp_from_left[i] = max_sum;
        }
        for(int i = n;i>=1;i--){
            int max_sum;
            for(int j = i;j>=1;j--){
                if(j == i){
                    max_sum = sum[i] - sum[j-1];
                }
                else{
                    if(max_sum < sum[i] - sum[j-1])
                        max_sum = sum[i] - sum[j-1];
                }
            }
            dp_from_right[i] = max_sum;
        }
        int res = -1000000;
        for(int s1 = 1;s1<=n;s1++){
            int right_sum = dp_from_left[s1 + 1];
            for(int s2 = s1 + 1;s2 <= n;s2 ++){
                if(dp_from_left[s2] > right_sum)
                    right_sum = dp_from_left[s2];
            }
            if(res < dp_from_right[s1] + right_sum)
                res = dp_from_right[s1] + right_sum;
        }
        printf("%d\n",res);
    }
    return 0;
}
```


AC

```C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int num[50000+1];
int dp_from_left[50000 + 1];
int dp_from_right[50000 + 1];
int sum[50000+1];
int main() {
    int t;
    scanf("%d",&t);
        while (t--){
        int n;
        scanf("%d",&n);
        dp_from_right[n+1] = 0;
        dp_from_left[0] = 0;
        sum[0] = 0;
        int a = -100010;
        int b = -100010;
        for(int i = 1;i<=n;i++){
            scanf("%d",&num[i]);
            sum[i] = sum[i-1] + num[i];
            if(num[i] > a){
                b = a;
                a = num[i];
            }
            else{
                if(num[i] > b) b = num[i];
            }
        }

        int min_sum = 0;
        int max_sum = -100010;
        for(int i = 1;i<=n;i++){
            if(sum[i] < min_sum) min_sum = sum[i];
            max_sum = max(max_sum,sum[i] - min_sum);
            dp_from_left[i] = max_sum;
        }
        min_sum = sum[n];
        max_sum = -100010;
        for(int i = n;i>=1;i--){
            if(sum[i] > min_sum)
                min_sum = sum[i];
            max_sum = max(max_sum,min_sum-sum[i]);
            dp_from_right[i] = max_sum;
        }
        int res = -1000000;
        for(int s1 = 1;s1<=n;s1++){
            res = max(res,dp_from_left[s1] + dp_from_right[s1]);
        }
        if(res == 0 && a < 0)
            res = a + b;
        else if(res == a)
            res = a + b;
        printf("%d\n",res);
    }
    return 0;
}
```

这道题本质上还是股票买卖，认为原始序列是股票价格的差分序列。做一个预处理，前缀和作为股票价格，然后进行两次股票买卖即可。并且必须买卖2次。


如下这样写是错的。
```C
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;
int a[50005];
int dp_from_left[50005];//考虑过以a[i]结尾但不一定要以a[i]结尾的最大连续子数组和，从左边开始
int dp_from_right[50005];//考虑过以a[i]结尾但不一定要以a[i]结尾的最大连续子数组和，从右边开始
//如果以a[i]结尾，最后还得遍历一遍（n^2），导致超时。
int n;

int solve(){
    for(int i = 1;i<=n;i++){
        if(i == 1){
            dp_from_left[i] = a[i];
        }
        else{
            if(dp_from_left[i-1] + a[i] >= 0){//如果dp_from_left[i-1]加上a[i]之后没有dp_from_left[i-1]大呢？没有关系，这样的操作是为了后面铺路的;之前的较大值已经保存在dp_from_left[i-1]里了
                dp_from_left[i] = dp_from_left[i-1] + a[i];
            }
            else{
                dp_from_left[i] = max(dp_from_left[i-1],a[i]);
            }
        }
        printf("dp_from_left[%d]: %d\n",i,dp_from_left[i]);
    }

    for(int i = n;i>=1;i--){
        if(i == n){
            dp_from_right[n] = a[i];//边界处强制选；参考题意
        }
        else{
            if(dp_from_right[i+1] + a[i] >= 0){
                dp_from_right[i] = dp_from_right[i+1] + a[i];
            }
            else{
                dp_from_right[i] = max(dp_from_right[i+1],a[i]);
            }
        }
        printf("dp_from_right[%d]: %d\n",i,dp_from_right[i]);
    }

    int opt = -10000000;
    for(int i = 1;i<=n-1;i++){
        opt = max(opt,dp_from_left[i] + dp_from_right[i+1]);
    }
    return opt;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
        int res = solve();
        printf("%d\n",res);
    }
    return 0;
}
```
