http://bailian.openjudge.cn/practice/2479/

http://algorithm.openjudge.cn/20164/1/

http://algorithm.openjudge.cn/201804/E/



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