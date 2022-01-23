/*


https://leetcode-cn.com/problems/keyboard-row/

hash

https://leetcode-cn.com/problems/keyboard-row/solution/si-lu-jian-dan-jie-xi-xiang-xi-by-yo-mi-ic2p/
transform(str.begin(),str.end(),str.begin(),::tolower);
有点类似python里的map


执行结果：
通过

执行用时：
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.8 MB, 在所有 C++ 提交中击败了19.04%的用户
通过测试用例：22 / 22

class Solution {
public:
    map<char, int> char2row;

    void init(){
        string chars_1 = "qwertyuiop";
        string chars_2 = "asdfghjkl";
        string chars_3 = "zxcvbnm";
        vector<string> chars_vectors = {chars_1, chars_2, chars_3};
        for(size_t idx = 0; idx < chars_vectors.size(); ++idx){
            string current_chars = chars_vectors[idx];
            for(auto ch:current_chars){
                char2row[ch] = idx + 1;
                if('A' <= ch and ch <= 'Z'){
                    char2row[ch + 'a' - 'A'] = idx + 1;
                }
                else{
                    char2row[ch + 'A' - 'a'] = idx + 1;
                }
            }
        }
        // for(auto item:char2row){
        //     cout<<item.first<<endl;
        //     cout<<item.second<<endl;
        // }
    }

    bool is_valid(string word){
        if(word.size() == 0) return true;
        int the_row = char2row[word[0]];
        // cout<<the_row<<endl;
        for(size_t idx = 1; idx < word.size(); ++idx){
            // cout<<char2row[word[idx]]<<endl;
            if(char2row[word[idx]] != the_row){
                 return false;
            }
        }
        return true;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        init();
        for(auto word:words){
            if(is_valid(word)){
                ret.emplace_back(word);
            }
        }
        return ret;
    }
};




*/