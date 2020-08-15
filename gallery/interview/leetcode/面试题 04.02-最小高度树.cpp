class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> res;
        vector<vector<int>> G(n, vector<int>());
        queue<int> Q;
        int degree[n];
        for (int i = 0; i < n; i++)
            degree[i] = 0;
        for (auto edge : edges)
        {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
                Q.push(i);
        }
        //每次删掉叶子节点

        //特殊情况，只有一个节点，且无边
        if (n == 1)
        {
            res.push_back(0);
            return res;
        }

        int left_node_num = n;
        while (left_node_num > 2)
        { //最小高度树的根节点最多有2个
            left_node_num -= Q.size();
            int cnt = Q.size();
            while (cnt--) // 一轮一轮删掉叶子节点，不能用while(!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (auto v : G[u])
                {
                    if (degree[v] > 0)
                    {
                        degree[v]--;
                        if (degree[v] == 1)
                            Q.push(v);
                    }
                }
            }
        }

        while (!Q.empty())
        {
            int root = Q.front();
            Q.pop();
            res.push_back(root);
        }
        return res;
    }
};