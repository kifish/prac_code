//可以通过用set 来判断;也可以用快慢指针来判圈。

class Solution
{
public:
    int change(int n){//输入为正整数
        int res = 0;
        while(n){
            int tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n)
    {
        int fast = n;
        int slow = n;
        do{
            slow = change(slow); //跳一步
            fast = change(fast); // 跳两步
            fast = change(fast);
        }while(fast != slow);
        if(slow != 1) return false;
        return true;
    }
};