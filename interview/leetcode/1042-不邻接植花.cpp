class Solution
{   
    vector<vector<int>> g;
    vector<int> answer;
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths)
    {
        //注意这里的花园路径只是指一条边，不考虑多条边相联接的情况
        g.resize(N);
        answer.resize(N,-1);
        for(auto path:paths){
            g[path[0]-1].push_back(path[1]-1);
            g[path[1]-1].push_back(path[0]-1);
        }
        for(int i = 0;i<N;i++){
            set<int> color = {1,2,3,4};
            for(int j = 0;j<g[i].size();j++){
                if(answer[g[i][j]] == -1) continue;
                else color.erase(answer[g[i][j]]);
            }
            answer[i] = *color.begin();
        }
        return answer;
    }
};