/*

https://leetcode-cn.com/problems/basic-calculator-ii/



*/

class Solution {
    stack<int> nums;
    stack<char> ops;
    map<char, int> op2priority = {
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1}
    };
    void cal_iter(){
        char op = ops.top();
        ops.pop();
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        if(op == '+'){
            nums.push(a + b);
        }
        else if(op == '-'){
            nums.push(a - b);
        }
        else if(op == '*'){
            nums.push(a * b);
        }
        else if(op == '/'){
            nums.push(a / b);
        }
    }
public:
    int calculate(string s) {
        string num_str = "";
        for(auto ch : s){
            if(ch == ' ') {
                if(num_str.size()){
                    nums.push(stoi(num_str));
                    num_str = "";
                }
                continue;
            }

            if(op2priority.count(ch) == 1){
                if(num_str.size()){
                    nums.push(stoi(num_str));
                    num_str = "";
                }
                while(!ops.empty() && op2priority[ops.top()] >= op2priority[ch]){
                    cal_iter();
                }
                ops.push(ch);
            }
            else{
                // num_str += to_string(ch); // WA
                num_str += ch;
            }
        }
        if(num_str.size()){
            nums.push(stoi(num_str));
            num_str = "";
        }
        while(!ops.empty()){
            cal_iter();
        }
        return nums.top();
    }
};
