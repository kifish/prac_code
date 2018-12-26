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


