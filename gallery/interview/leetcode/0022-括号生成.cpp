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

class Solution {
    vector<string> paths;
public:
    void dfs(string cur_str, int left_p_cnt, int right_p_cnt){
        if(left_p_cnt == 0 && right_p_cnt == 0){
            paths.push_back(cur_str);
            return;
        }

        if(left_p_cnt > right_p_cnt){
            return;
        }

        if(left_p_cnt > 0){
            dfs(cur_str + "(", left_p_cnt - 1, right_p_cnt);
        }
        if(right_p_cnt > 0){
            dfs(cur_str + ")", left_p_cnt, right_p_cnt -1);
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return paths;
    }
};
