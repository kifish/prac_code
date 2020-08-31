class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<vector<int>> G(numCourses);
        //��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ����: [0,1]����γ�1ָ��γ�0
        int degree[numCourses]; //indegree
        //�����ʼ����һ��ȫΪ0
        fill(degree,degree+numCourses,0);
        for (int i = 0;i<prerequisites.size();i++){
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);//�����ָ����ı�
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