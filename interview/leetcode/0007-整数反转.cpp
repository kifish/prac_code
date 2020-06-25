class Solution {
//const int INT_MAX = 1<<32-1;
//const int INT_MIN = 1<<31;
public:
    int reverse(int x) {
        //bool sign = false;
        //if(x < 0) sign = true;
        int res = 0;
        while(x){
            int bit = x % 10;
            x /= 10;
            if(res > INT_MAX/10 || res == INT_MAX/10 && bit > 7) return 0;
            if(res < INT_MIN/10 || res == INT_MIN/10 && bit < -8) return 0;
            res = res * 10 + bit;
        }
        return res;
    }
};