class Solution
{
private:
    vector<vector<int>> adj;
    vector<vector<double>> memo;
    vector<bool> visited;
    map<string,int> ch2id;
    int ch_num;
public:
    //建图
    //字母即节点
    //公式的值即边
    void init(vector<vector<string>> equations,vector<double> values){
        for(int i = 0;i<equations.size();i++){
            if(!ch2id.count(equations[i][0])) ch2id[equations[i][0]] = ch2id.size();
            if(!ch2id.count(equations[i][1])) ch2id[equations[i][1]] = ch2id.size();
        }
        ch_num = ch2id.size();
        visited.resize(ch_num);
        for(int i = 0;i<ch_num;i++) visited[i] = false;
        adj.resize(ch_num);
        memo = vector<vector<double>>(ch_num,vector<double>(ch_num,-1.0));
        for(int i =0;i<equations.size();i++){  
            int u = ch2id[equations[i][0]];
            int v = ch2id[equations[i][1]];
            double w = values[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
            memo[u][v] = w;
            memo[v][u] = 1 / w;
            memo[u][u] = 1.0;
            memo[v][v] = 1.0;
        }
    }

    vector<int> dfs(int u){ //返回从u点可达的所有点，不包括visited为true的点
        visited[u] = true;
        vector<int> reach = {u}; // 从u点可达的所有点,不包括visited为true的点
        vector<vector<int>> groups;
        for(auto v :adj[u]){
            if(!visited[v]){ //访问过则会被或已经被确定相关的值
                auto nodes = dfs(v); // 从v点可达的所有点,不包括visited为true的点
                for(auto reach_node:nodes){
                    if(memo[u][reach_node] < 0) memo[u][reach_node] = memo[u][v] * memo[v][reach_node]; // 避免浮点数相等判断
                    if(memo[reach_node][u] < 0) memo[reach_node][u] = 1 / memo[u][reach_node]; 
                    reach.push_back(reach_node);
                }
                groups.push_back(nodes);
            }
        }

        //这里的计算是必须的。
        //因为,并没计算完连通分量中的所有点对的值。例如以u为中转点可达的点对。
        int n = groups.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(auto s:groups[i]){
                    for(auto e:groups[j]){
                        if(memo[s][e] < 0) memo[s][e] = memo[s][u] * memo[u][e];
                        if(memo[e][s] < 0) memo[e][s] = 1 / memo[s][e];
                    }
                }
            }
        }
        return reach;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {   
        init(equations,values);

        for(int i = 0;i<ch_num;i++){
            if(!visited[i])
                dfs(i);
        }

        vector<double> res;
        for(auto query:queries){
            if(ch2id.count(query[0]) && ch2id.count(query[1])){
                int u = ch2id[query[0]];
                int v = ch2id[query[1]];
                res.push_back(memo[u][v]);
            }
            else res.push_back(-1.0);
        }
        return res;
    }
};