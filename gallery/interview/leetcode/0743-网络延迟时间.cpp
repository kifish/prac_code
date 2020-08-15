class Solution
{
private:
    int dist[101][101];
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {   //init
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++){
                if(i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INT_MAX;
            }
        }

        for(auto vec : times){
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            dist[u][v] = cost;
        }
        for(int k = 1;k<=N;k++)
            for(int i = 1;i<=N;i++)
                for(int j = 1;j<=N;j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j]; //relax
                }
        
        int max_dist = 0;
        for(int j = 1;j<=N;j++){
            max_dist = max(max_dist,dist[K][j]);
        }
        if(max_dist == INT_MAX) return -1;
        return max_dist;
    }
};