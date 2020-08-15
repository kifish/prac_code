class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for(int i = 0;i<tokens.size();i++){
            string op = tokens[i];
            if(op.size() == 1){
                if(op[0] == '+'){
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.push(a+b);
            }
            else if(op[0] == '-'){
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.push(a-b);
            }
            else if(op[0] == '/'){
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.push(a/b);
            }
            else if(op[0] == '*'){
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                S.push(a*b);
            }
            else{
                int num = atoi(op.c_str());
                S.push(num);
            }
            }
            else{
                int num = atoi(op.c_str());
                S.push(num);
            }
        }
        return S.top();
    }
};