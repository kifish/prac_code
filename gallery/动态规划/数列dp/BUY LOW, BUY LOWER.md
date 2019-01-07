最长下降子序列。

http://algorithm.openjudge.cn/200603/4/

https://github.com/kifish/prac_code/blob/master/gallery/pat/pat-a/1045.md


诡异的问题，无法return。
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

vector<int> pre[5001];
int num[5001];
int dp[5001];

set<vector<int>> res;

vector<int> path;
void dfs(int idx){
    path.push_back(idx);
    //到达边界。
    if(pre[idx].size() == 0){
        res.insert(path);
        path.pop_back();
        return;
    }
    //未到达边界。
    for(int i = 0;i<pre[idx].size();i++){
        dfs(pre[idx][i]);
        path.pop_back();
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d",&num[i]);
    for(int i = 1;i<=n;i++){
        int max_len = 1;
        vector<int> pre_idxs;
        for(int j = 1;j < i;j++){
            if(num[i] >= num[j]) continue;

            if(dp[j] + 1 > max_len){
                max_len = dp[j] + 1;
                pre_idxs.clear();
                pre_idxs.push_back(j);
            }
            else if(dp[j] + 1 == max_len)
                pre_idxs.push_back(j);
        }

        dp[i] = max_len;
        pre[i] = pre_idxs;
    }
    int max_len = 1;
    vector<int> end_idxs;
    for(int i = 1;i<=n;i++){
        if(dp[i] > max_len){
            max_len = dp[i];
            end_idxs.clear();
            end_idxs.push_back(i);
        }
        else if(dp[i] == max_len)
            end_idxs.push_back(i);
    }
    //return 0;这里可以正常退出。
    for(int i= 1;i<=n;i++){
        if(dp[i] == max_len){
            path.clear();
            dfs(i);
        }
    }
    printf("here\n");
    return 0;//这里不会结束!
    printf("%d %d\n",max_len,res.size());
    return 0;
}
```


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

vector<int> pre[5001];
int num[5001];
int dp[5001];

set<vector<int> > res;

vector<int> path;
void dfs(int idx)
{
    path.push_back(idx);
    //到达边界。
    if (pre[idx].size() == 0)
    {
        res.insert(path);
        path.pop_back();#1
        return;
    }
    //未到达边界。
    for (int i = 0; i < pre[idx].size(); i++) {
        dfs(pre[idx][i]);
        path.pop_back(); //#2; #1和#2导致边界的地方出问题了，只加入了一次，却pop了两次，这样的话必然导致报错。
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (int i = 1; i <= n; i++)
    {
        int max_len = 1;
        vector<int> pre_idxs;
        for (int j = 1; j < i; j++)
        {
            if (num[i] >= num[j])
                continue;

            if (dp[j] + 1 > max_len)
            {
                max_len = dp[j] + 1;
                pre_idxs.clear();
                pre_idxs.push_back(j);
            }
            else if (dp[j] + 1 == max_len)
                pre_idxs.push_back(j);
        }

        dp[i] = max_len;
        pre[i] = pre_idxs;
    }
    int max_len = 1;
    vector<int> end_idxs;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > max_len)
        {
            max_len = dp[i];
            end_idxs.clear();
            end_idxs.push_back(i);
        }
        else if (dp[i] == max_len)
            end_idxs.push_back(i);
    }
    //return 0;这里可以正常退出。
//    for (int i = 0; i < end_idxs.size(); i++)
//    {
//        path.clear();
//        dfs(end_idxs[i]);
//    }
    printf("here\n");
    return 0; //这样可以结束!
    //printf("%d %d\n", max_len, (int)res.size());
    //return 0;
}
```


看来dfs写的有问题。for循环中一层可能只执行了一层dfs，然后递归的dfs一直没有返回？
不是这样。是dfs写错了，导致出现了vector的size为0，但有pop的情况。
mac clion上这种情况不会报错，但也不会终止main函数，就出现了诡异的情况。
vs上可以正常报错。


结果应该已经对了，但还是TLE.
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

vector<int> pre[5001];
int num[5001];
int dp[5001];

set<vector<int> > res;


vector<int> path;
void dfs(int idx)
{
    //到达边界。
    if (pre[idx].size() == 0)
    {   path.push_back(idx);
        res.insert(path);
        path.pop_back();
        return;
    }
    //未到达边界。
    path.push_back(idx);
    for (int i = 0; i < pre[idx].size(); i++) {
        dfs(pre[idx][i]);
    }
    path.pop_back();
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (int i = 1; i <= n; i++)
    {
        int max_len = 1;
        vector<int> pre_idxs;
        for (int j = 1; j < i; j++)
        {
            if (num[i] >= num[j])
                continue;

            if (dp[j] + 1 > max_len)
            {
                max_len = dp[j] + 1;
                pre_idxs.clear();
                pre_idxs.push_back(j);
            }
            else if (dp[j] + 1 == max_len)
                pre_idxs.push_back(j);
        }

        dp[i] = max_len;
        pre[i] = pre_idxs;
    }
    int max_len = 1;
    vector<int> end_idxs;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > max_len)
        {
            max_len = dp[i];
            end_idxs.clear();
            end_idxs.push_back(i);
        }
        else if (dp[i] == max_len)
            end_idxs.push_back(i);
    }
    for (int i = 0; i < end_idxs.size(); i++)
    {
        path.clear();
        dfs(end_idxs[i]);
    }
    printf("%d %d\n", max_len, (int)res.size());
    return 0;
}
```


TLE
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

vector<int> pre[5001];
int num[5001];
int dp[5001];

set<string> res;


vector<int> path;
void dfs(int idx)
{
    //到达边界。
    if (pre[idx].size() == 0)
    {   path.push_back(idx);
        string s = "";
        for(int i = 0;i<path.size();i++){
            s += to_string(path[i]);
            if(i != path.size() -1) s += ",";
        }
        res.insert(s);
        path.pop_back();
        return;
    }
    //未到达边界。
    path.push_back(idx);
    for (int i = 0; i < pre[idx].size(); i++) {
        dfs(pre[idx][i]);
    }
    path.pop_back();
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (int i = 1; i <= n; i++)
    {
        int max_len = 1;
        vector<int> pre_idxs;
        for (int j = 1; j < i; j++)
        {
            if (num[i] >= num[j])
                continue;

            if (dp[j] + 1 > max_len)
            {
                max_len = dp[j] + 1;
                pre_idxs.clear();
                pre_idxs.push_back(j);
            }
            else if (dp[j] + 1 == max_len)
                pre_idxs.push_back(j);
        }

        dp[i] = max_len;
        pre[i] = pre_idxs;
    }
    int max_len = 1;
    vector<int> end_idxs;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > max_len)
        {
            max_len = dp[i];
            end_idxs.clear();
            end_idxs.push_back(i);
        }
        else if (dp[i] == max_len)
            end_idxs.push_back(i);
    }
    for (int i = 0; i < end_idxs.size(); i++)
    {
        path.clear();
        dfs(end_idxs[i]);
    }
    printf("%d %d\n", max_len, (int)res.size());
    return 0;
}
```

https://blog.csdn.net/kenden23/article/details/41047779

AC
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

vector<int> pre[5001];
int num[5001];
int dp[5001];
int cnt[5001];


int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    fill(cnt,cnt + 5001, 1);
    for (int i = 1; i <= n; i++)
    {
        int max_len = 1;
        for (int j = 1; j < i; j++)
        {
            if (num[i] >= num[j])
                continue;

            if (dp[j] + 1 > max_len)
            {
                max_len = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if (dp[j] + 1 == max_len)
                cnt[i] += cnt[j];
        }
        dp[i] = max_len;
        //修正。需要去掉相同的序列。
        for(int j = 1;j<i;j++){
            //仅检查最后一项。利用递推的性质，实际上检查了所有项。
            if(num[j] == num[i] && dp[j] == dp[i])
                cnt[i] -= cnt[j];
        }
    }
    int max_len = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > max_len)
        {
            max_len = dp[i];
        }

    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if(dp[i] == max_len)
            sum += cnt[i];
    }
    printf("%d %d\n", max_len, sum);
    return 0;
}
```

