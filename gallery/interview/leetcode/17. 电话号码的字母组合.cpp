// 执行用时 :
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗 :
// 7.1 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    map<char, vector<char>> digit2chars;
    vector<string> paths;
    vector<char> path;
    void init(){
        digit2chars['2'] = {'a','b','c'};
        digit2chars['3'] = {'d','e','f'};
        digit2chars['4'] = {'g','h','i'};
        digit2chars['5'] = {'j','k','l'};
        digit2chars['6'] = {'m','n','o'};
        digit2chars['7'] = {'p','q','r','s'};
        digit2chars['8'] = {'t','u','v'};
        digit2chars['9'] = {'w','x','y','z'};
    }
    void dfs(int idx, string digits){
        if(idx == digits.size()){
            string ret = "";
            for(auto c : path){
                ret += c;
            }
            paths.push_back(ret);
            return;
        }

        vector<char> cur_chars = digit2chars[digits[idx]];
        for(auto c : cur_chars){
            path.push_back(c);
            dfs(idx+1, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        init();
        if(digits.size()){
            dfs(0, digits);
        }
        return paths;
    }
};