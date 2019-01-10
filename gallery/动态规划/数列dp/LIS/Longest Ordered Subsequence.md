http://algorithm.openjudge.cn/algorithmc/C/


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
#include <utility>
#include <cmath>
using namespace std;

int num[1005];
int dp[1005];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>num[i];
    }

    fill(dp,dp+n+1,1);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            if(num[i] <= num[j]) continue;
            if(dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    int max_len = 1;
    for(int i = 1;i<=n;i++) max_len = max(max_len,dp[i]);
    cout<<max_len<<endl;
    return 0;
}
```

