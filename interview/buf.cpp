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
        path.pop_back();
        return;
    }
    //未到达边界。
    for (int i = 0; i < pre[idx].size(); i++)
    {
        dfs(pre[idx][i]);
        path.pop_back();
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
    for (int i = 0; i < end_idxs.size(); i++)
    {
        path.clear();
        dfs(end_idxs[i]);
    }
    printf("here\n");
    return 0; //这里不会结束!
    printf("%d %d\n", max_len, (int)res.size());
    return 0;
}