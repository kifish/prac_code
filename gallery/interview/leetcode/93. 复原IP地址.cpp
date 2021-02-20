/*

工程题

dfs + path 回溯

https://leetcode-cn.com/problems/restore-ip-addresses/solution/fu-yuan-ipdi-zhi-by-leetcode/

https://leetcode-cn.com/problems/restore-ip-addresses/
https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1044/



https://leetcode-cn.com/problems/restore-ip-addresses/solution/hui-su-suan-fa-hua-tu-fen-xi-jian-zhi-tiao-jian-by/


c++实现:
https://leetcode-cn.com/problems/restore-ip-addresses/solution/dfszi-fu-chuan-cao-zuo-93-fu-yuan-ipdi-zhi-by-zxre/




执行结果：
通过
显示详情
执行用时：
4 ms
, 在所有 C++ 提交中击败了
57.89%
的用户
内存消耗：
8.2 MB
, 在所有 C++ 提交中击败了
6.42%
的用户


dfs 的逻辑还可以优化, 只加1个字符 只加2个字符 只加3个字符的思路来优化。


*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> paths;
    vector<string> path;

    bool valid_chunk(string chunk){
        if(chunk.size() == 3){
            if(chunk > "255"){
                return false;
            }
        }


        return true;
    }

    void dfs(int idx, string chunk, string & s){
        // cout<<"idx :"<<idx<<endl;
        // cout<<"chunk :"<<chunk<<endl;

        if(path.size() == 4){ // 前面已经有四段chunk, 那么说明这个状态是不合法的
            return;
        }

        if(idx == s.size()){
            if(path.size() < 3){
                return;
            }

            if(valid_chunk(chunk)){
                path.push_back(chunk);
                paths.push_back(path);
                path.pop_back();
            }
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
            bool is_first = true;
            for(auto chunk : the_path){
                if(!is_first){
                    tmp += ".";
                }
                else{
                    is_first = false;
                }

                // cout<<chunk<<endl;
                tmp += chunk;
            }
            ret.push_back(tmp);
        }

        // for(auto s : ret){
        //     cout<<s<<endl;
        // }

        return ret;
    }

};



int main(){
    string s = "25525511135";
    Solution solution = Solution();
    solution.restoreIpAddresses(s);

    return 0;
}

