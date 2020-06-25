// bellman-ford
// recall that ������bf�㷨��ʵ�Ѿ��Ż�����
//dp[n][i][j] = min(dp[n-1][i][k] + dp[n-1][k][j], dp[n-1][i][j])
//n��������ྭ���ı���
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        int cnt = K + 1; // K = 0��������ֱ��,K=0ʱҪ��һ��relax
        while(cnt--){
            vector<int> new_dist(dist);
            for(auto flight : flights){
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];
                if(dist[u] == INT_MAX || cost == INT_MAX) continue;
                new_dist[v] = min(new_dist[v], dist[u] + cost); //ע�������relax
            }
            dist = new_dist;//�������飬��ֹrelax�õ����Ѿ��Ż���Ľ��
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};