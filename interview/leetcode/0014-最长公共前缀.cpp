class Solution {
public:
    bool check(vector<string>& strs,int k){
        char c = strs[0][k];
        for(int i = 0;i<strs.size();i++){
            if(strs[i][k] != c){
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int len = 0;
        int min_len = INT_MAX;
        for(int i = 0;i<strs.size();i++){
            if(strs[i].size() < min_len){
                min_len = strs[i].size();
            }
        }
        for(;len<=min_len;len++){
            if(!check(strs,len)) break;
        }
        if(len == 0) return "";
        else return strs[0].substr(0,len);
    }
};