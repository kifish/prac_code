http://algorithm.openjudge.cn/200603/1/


https://blog.csdn.net/zhao5502169/article/details/69681030


http://bailian.openjudge.cn/practice/1163/


可以直接左对齐，没必要存成原始的三角形。

```C
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int num[101][101];
int dp[101][101] = {0};


int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(int j = 1;j<=n;j++) dp[n][j] = num[n][j];
    for(int i = n -1;i>=1;i--){
        for(int j = 1;j<=i;j++){
            dp[i][j] = num[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d\n",dp[1][1]);
    return 0;
}
```


