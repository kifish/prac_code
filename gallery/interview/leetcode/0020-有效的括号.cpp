class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(auto c: s){
            if(c == ')'){
                if(S.empty()) return false;
                if(S.top() != '(') return false;
                S.pop();
            }
            else if(c == '}'){
                if(S.empty()) return false;
                if(S.top() != '{') return false;
                S.pop();
            }
            else if(c == ']'){
                if(S.empty()) return false;
                if(S.top() != '[') return false;
                S.pop();
            }
            else S.push(c);
        }
        if(!S.empty()) return false;
        return true;
    }
};