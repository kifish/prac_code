class Solution
{
private:
    vector<string> path;
    vector<string> cur_path;
    map<string, map<string,int>> M;
    int edge_n;
public:
    //这道题不是拓扑排序，因为可能存在环;求的是欧拉路径,机票相当于边数，因此最终经过的节点数(包括起点)必定是机票数+1
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {   
        edge_n = tickets.size();
        for(auto ticket:tickets){
            M[ticket[0]][ticket[1]]++;
        }
        cur_path.push_back("JFK");
        dfs();
        return path;
    }

    void dfs(){
        if(path.size() == edge_n + 1) return;
        if(cur_path.size() == edge_n + 1){
            path = cur_path;
            return;
        }
        string u = cur_path.back();
        for(auto &item: M[u]){ //要加引用才能修改
            if(item.second > 0){
                cur_path.push_back(item.first);
                item.second--;
                dfs();
                cur_path.pop_back();
                item.second++;
            }
        }
    }
};