/*

工程题

dfs + path 回溯

https://leetcode-cn.com/problems/restore-ip-addresses/solution/fu-yuan-ipdi-zhi-by-leetcode/

https://leetcode-cn.com/problems/restore-ip-addresses/
https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1044/



https://leetcode-cn.com/problems/restore-ip-addresses/solution/hui-su-suan-fa-hua-tu-fen-xi-jian-zhi-tiao-jian-by/


c++实现:
https://leetcode-cn.com/problems/restore-ip-addresses/solution/dfszi-fu-chuan-cao-zuo-93-fu-yuan-ipdi-zhi-by-zxre/


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> paths;
    vector<string> path;

    void dfs(int idx, string chunk, string & s){
        if(idx == s.size()){
            path.push_back(chunk);
            paths.push_back(path);
            path.pop_back();
            return;
        }


        if(idx == 0){
            chunk += s[idx];
            dfs(idx + 1, chunk, s);
        }

        else{

            if(chunk.size() && chunk[0] == '0'){
                path.push_back(chunk);
                chunk = "";
                chunk += s[idx];
                dfs(idx + 1, chunk, s);
                path.pop_back();
            }
            else{
                if(chunk.size() == 3){
                    if(chunk > "255"){
                        return;
                    }
                    else{
                        path.push_back(chunk);
                        chunk = "";
                        chunk += s[idx];
                        dfs(idx + 1, chunk, s);
                        path.pop_back();
                    }
                }
                else{

                    dfs(idx + 1, chunk + s[idx], s);

                    path.push_back(chunk);
                    chunk = "";
                    chunk += s[idx];
                    dfs(idx + 1, chunk, s);
                    path.pop_back();
                }

            }
        }

    }

    vector<string> restoreIpAddresses(string s) {
        dfs(0, "", s);
        vector<string> ret;

        for(auto the_path : paths){
            string tmp = "";
            for(auto chunk : the_path){
                bool is_first = true;
                if(!is_first){
                    tmp += ".";
                }
                else{
                    is_first = false;
                }

                tmp += chunk;
            }
            ret.push_back(tmp);
        }

        for(auto s : ret){
            cout<<s<<endl;
        }

        return ret;
    }

};



int main(){
    string s = "25525511135";
    Solution solution = Solution();
    solution.restoreIpAddresses(s);

    return 0;
}

