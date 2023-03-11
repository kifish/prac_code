/*


https://leetcode-cn.com/problems/remove-duplicate-letters/

https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/


https://leetcode-cn.com/problems/remove-duplicate-letters/solution/yi-kan-jiu-hui-jiu-chai-shou-ba-shou-jia-miqw/


https://leetcode-cn.com/problems/create-maximum-number/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-7/



class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> char2left_cnt;
        for(auto ch : s){
            char2left_cnt[ch] += 1;
        }
        vector<char> selected_chars;
        set<char> selected_chars_set;
        for(auto ch : s){
            if(selected_chars_set.find(ch) != selected_chars_set.end()){
                char2left_cnt[ch] -= 1;
                continue;
            }
            while(selected_chars.size() && ch < selected_chars.back() && char2left_cnt[selected_chars.back()] > 0){
                selected_chars_set.erase(selected_chars.back());
                selected_chars.pop_back();
            }
            selected_chars_set.insert(ch);
            selected_chars.push_back(ch);
            char2left_cnt[ch] -= 1;
        }
        string ret = "";
        for(auto ch : selected_chars){
            ret += ch;
        }
        return ret;
    }
};
*/
