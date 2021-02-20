/*


https://leetcode-cn.com/problems/reverse-words-in-a-string/

https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1011/

poj原题



执行结果：
通过
显示详情
执行用时：
8 ms
, 在所有 C++ 提交中击败了
46.68%
的用户
内存消耗：
7.5 MB
, 在所有 C++ 提交中击败了
44.33%
的用户


*/

class Solution {
public:
    string reverseWords(string s) {
        // 利用stringstream 可以实现split
        stack<string> S;
        string word = "";
        for(auto c : s){
            if(c == ' '){
                if(word.size()){
                    S.push(word);
                    word = "";
                }
            }

            else{
                word += c;
            }
        }
        if(word.size()){
            S.push(word);
        }
        string ret = "";
        bool is_first = true;
        while(!S.empty()){
            if(!is_first){
                ret += " ";
            }
            else{
                is_first = false;
            }
            ret += S.top();
            S.pop();
        }
        return ret;
    }
};


