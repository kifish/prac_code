class Solution {
public:
    vector<int> solve(string s){
        vector<int> res;
        vector<int> left,right;
        for(int i = 0;i<s.size();i++){
            if(!isdigit(s[i])){
                //https://www.cnblogs.com/xzxl/p/7243490.html
                left = solve(s.substr(0,i));//这里可以memo
                right = solve(s.substr(i+1));
                for(int num1:left){
                    for(int num2:right){
                        if(s[i] == '+') res.push_back(num1+num2);
                        else if(s[i] == '-') res.push_back(num1-num2);
                        else res.push_back(num1*num2);
                    } 
                }
            }
        }
        
        if(res.empty()) res.push_back(stoi(s));
        return res;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        res = solve(input);
        sort(res.begin(),res.end());
        return res;
    }
};