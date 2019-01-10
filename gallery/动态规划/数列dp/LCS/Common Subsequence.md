http://algorithm.openjudge.cn/algorithmc/D/



这里不要求序列必须连续，只要顺次从原序列里挑选即可。


https://blog.csdn.net/u013480600/article/details/40741333

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


int dp[1005][1005];
string s1,s2;

int main(){
    while (cin>>s1>>s2){
        fill(dp[0],dp[0] + 1005 * 1005,0);
        for(int i = 0;i<s1.size();i++){
            for(int j = 0;j<s2.size();j++){
                if(s1[i] == s2[j]){
                    if(i && j)//处理数组下标可能越界的问题。
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = 1;
                }
                else{
                    if(i && j)
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    else{
                        if(i == 0 && j != 0)
                            dp[i][j] = dp[i][j-1];
                        else if(i != 0 && j == 0)
                            dp[i][j] = dp[i-1][j];
                        else
                            dp[i][j] = 0;
                    }
                }
            }
        }
        cout<<dp[s1.size()-1][s2.size()-1]<<endl;
    }
    return 0;
}
```

