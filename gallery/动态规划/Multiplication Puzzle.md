```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dp[110][110];
int num[110];
int main() {
    scanf("%d",&n);
    num[0] = 1;
    num[n+1] = 1;
    fill(dp[0],dp[0]+110*100,0x3f3f3f3f);
    for(int i = 1;i<=n;i++) scanf("%d",&num[i]);
    for(int h = 0;h<=n;h++){
        for(int i = 1;i<=n;i++){
            int j = i + h;
            if(j > n) break;
            for(int k = i;k<=j;k++){
                int temp = 0;
                if(i - 1 >= 1 && j + 1 <= n){
                    temp +=num[i-1]*num[k]*num[j+1];
                    if(k - 1 >= i) temp += dp[i][k-1];
                    if(k + 1 <= j) temp += dp[k+1][j];
                    dp[i][j] = min(dp[i][j],temp);
                }
            }
        }
    }
    printf("%d\n",dp[2][n-1]);
    return 0;
}
```