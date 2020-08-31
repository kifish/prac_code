// bellman-ford
// recall that 常见的bf算法其实已经优化过了
//dp[n][i][j] = min(dp[n-1][i][k] + dp[n-1][k][j], dp[n-1][i][j])
//n代表了最多经过的边数
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        int cnt = K + 1; // K = 0则代表必须直达,K=0时要做一轮relax
        while(cnt--){
            vector<int> new_dist(dist);
            for(auto flight : flights){
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];
                if(dist[u] == INT_MAX || cost == INT_MAX) continue;
                new_dist[v] = min(new_dist[v], dist[u] + cost); //注意这里的relax
            }
            dist = new_dist;//滚动数组，防止relax用到了已经优化后的结果
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};