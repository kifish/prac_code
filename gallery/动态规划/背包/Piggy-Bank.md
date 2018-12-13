
http://algorithm.openjudge.cn/2018finalsim/4/

无穷背包。
```c
#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<algorithm>


using namespace std;


const int INF = 0x3fffffff;

int dp[10005];
int coins[505];
int weight[505];

int main() {
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int m;
		int e, f;
		scanf("%d %d", &e, &f);
		m = f - e;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &coins[i]);
			scanf("%d", &weight[i]);
		}
		for (int i = 0; i <= m; i++) {
			dp[i] = INF;
		}
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = weight[i]; j <= m; j++) {
				if (dp[j - weight[i]] != INF  && dp[j - weight[i]] + coins[i] < dp[j]) {
					dp[j] = dp[j - weight[i]] + coins[i];
				}
			}
		}
		if (dp[m] != INF) {
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
		}
		else {
			printf("This is impossible.\n");
		}
	}

	//while (1);
	return 0;
	
}
```


