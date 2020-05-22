class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> G(numCourses);
        vector<int> flag(numCourses, 0); //1�޻���0δ������-1���ڱ���
        bool nocircle = true;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            G[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0;i<numCourses;i++){
            nocircle = nocircle && !findcircle(i,flag,G);
            if(!nocircle) break;
        }
        return nocircle;
    }
    //dfs
    bool findcircle(int i,vector<int>& flag,vector<vector<int>>& G){
        if(flag[i] == -1) return true;//has circle
        if(flag[i] == 1) return false;
        flag[i] = -1;
        for(int j = 0;j<G[i].size();j++){
            if(findcircle(G[i][j],flag,G)) return true;
        }
        flag[i] = 1;
        return false;
    }
};