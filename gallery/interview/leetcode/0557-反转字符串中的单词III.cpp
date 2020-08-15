class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string tmp = "";
        for(char c : s){
            if(c == ' '){
                if(tmp.size()){
                    reverse(tmp.begin(),tmp.end());
                    res += tmp;
                    res += " ";
                    tmp = "";
                }
            }
            else{
                tmp += c;
            }
        }
        if(tmp.size()){
            reverse(tmp.begin(),tmp.end());
            res += tmp;
        }
        return res;
    }
};