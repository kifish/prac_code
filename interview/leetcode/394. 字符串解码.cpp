
// WA: "3[a2[c]]"

// class Solution {
// public:
//     string decodeString(string s) {
//         string ret = "";
//         string digits = "";
//         string encoded_string = "";
//         bool saw_a_symbol = false;
//         int num = 0;
//         for(int i = 0;i<s.size();i++){
//             if(s[i] == '['){
//                 num = stoi(digits);
//                 digits = "";
//                 saw_a_symbol = true;
//             }
//             else if(s[i] == ']'){
//                 while(num--){
//                     ret += encoded_string;
//                 }
//                 encoded_string = "";
//                 saw_a_symbol = false;
//             }
//             else{
//                 if(saw_a_symbol)
//                     encoded_string += s[i];
//                 else 
//                     digits += s[i];
//             }
//         }
//         return ret;
//     }
// };

// 递归实现起来比较麻烦
// https://leetcode-cn.com/problems/decode-string/solution/zi-fu-chuan-jie-ma-by-leetcode-solution/


// 执行用时 :
// 4 ms
// , 在所有 C++ 提交中击败了
// 40.88%
// 的用户
// 内存消耗 :
// 6.2 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    stack<char> char_stack;
    string decodeString(string s) {
        for(auto c : s){
            if(c == ']'){
                string encoded_string = "";
                while (char_stack.top() != '[')
                {
                    encoded_string += char_stack.top();
                    char_stack.pop();
                }
                char_stack.pop();
                string digits = "";
                while(char_stack.size() && isdigit(char_stack.top())){
                    digits += char_stack.top();
                    char_stack.pop();
                }
                reverse(encoded_string.begin(), encoded_string.end());
                reverse(digits.begin(), digits.end());
                int num = stoi(digits);
                while(num--){
                    for(auto the_c : encoded_string){
                        char_stack.push(the_c);
                    }
                }
            }
            else{
                char_stack.push(c);
            }
        }
        string ret = "";
        while(char_stack.size()){
            ret += char_stack.top();
            char_stack.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

