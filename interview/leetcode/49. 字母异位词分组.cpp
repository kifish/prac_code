// 当且仅当它们的字符计数（每个字符的出现次数）相同时，两个字符串是字母异位词。
// 相同的字符串也算字母异位词

// https://leetcode-cn.com/problems/group-anagrams/solution/zi-mu-yi-wei-ci-fen-zu-by-leetcode/
// 一种方法是用map,即树
// 还有一种方法是用hash

// https://leetcode-cn.com/problems/group-anagrams/solution/c-yin-ru-hashbiao-shi-jian-32ms-ji-bai-9948-nei-cu/

// 执行用时 :
// 68 ms
// , 在所有 C++ 提交中击败了
// 70.99%
// 的用户
// 内存消耗 :
// 16.1 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> M; // hash not tree
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            if(M.count(tmp)){
                M[tmp].push_back(s);
            }
            else{
                M[tmp] = vector<string> (1, s);
            }
        }
        vector<vector<string>> ret;
        for(unordered_map<string, vector<string>>::iterator it = M.begin();it != M.end(); it++){
            ret.push_back(it->second); // 这里用std::move好像更高效
        }        
        return ret;
    }
};