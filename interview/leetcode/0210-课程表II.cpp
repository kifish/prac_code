class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<vector<int>> G(numCourses);
        //想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]；令课程1指向课程0
        int degree[numCourses]; //indegree
        //数组初始化不一定全为0
        fill(degree,degree+numCourses,0);
        for (int i = 0;i<prerequisites.size();i++){
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);//存的是指向外的边
            degree[prerequisites[i][0]]++;
        }
        queue<int> Q;
        for(int i = 0;i<numCourses;i++){
            if(degree[i] == 0){
                Q.push(i);
            }
        }
        while(!Q.empty()){
            int cur = Q.front();
            res.push_back(cur);
            Q.pop();
            for(int i = 0;i<G[cur].size();i++){
                degree[G[cur][i]]--;
                if(degree[G[cur][i]] == 0){
                    Q.push(G[cur][i]);
                }
            }
        }
        if(res.size() != numCourses) res.clear();
        return res;
    }
};