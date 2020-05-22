class Solution {
public:
    int myAtoi(string str) {
        if(isalpha(str[0])) return 0;
        bool sign = false;
        int sign_num = 0;
        int len = 0;
        long long abs_val = 0;
        for(char c:str){
            if(c == '-' || c == '+'){
                if(len != 0) break;
                
                if(c == '-'){
                    sign = true;
                    sign_num++;
                }
                else if(c == '+'){
                    sign_num++;
                }
                
                if(sign_num == 2) break;
            }    
            else if('0' <= c && c<= '9'){
                len++;
                abs_val = abs_val * 10 + c - '0';
                if(!sign && abs_val > INT_MAX) break;
                if(sign && abs_val-1 > INT_MAX) break;
            }
            else if(c == ' ' && sign_num ==0 && len == 0){
                continue;
            }
            else break;
        }
        if(!sign){
            if(abs_val> INT_MAX) return INT_MAX;
            else return abs_val;
        } 
        else{
            if(abs_val - 1 > INT_MAX) return INT_MIN;
            else return -abs_val;
        } 
    }
};