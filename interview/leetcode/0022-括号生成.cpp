class Solution {
public:
    vector<string> paths;
    void dfs(int left_l_p,int need_r_p,vector<string>& path){
        if(left_l_p == 0){
            string ret = "";
            for(auto c:path){
                ret += c;
            }
            while (need_r_p--)
            {
                ret += ")";
            }
            paths.push_back(ret);
            return;
        }

        path.push_back("(");
        dfs(left_l_p-1,need_r_p+1,path);
        path.pop_back();
        if(need_r_p){
            path.push_back(")");
            dfs(left_l_p,need_r_p-1,path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> path;
        dfs(n,0,path);
        return paths;
    }
};