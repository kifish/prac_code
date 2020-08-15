class Solution
{
public:
    int climbStairs(int n)
    {
        int f1 = 1,f2 = 2;
        int res;
        if(n == 1) return 1;
        else if(n == 2) return 2;
        for(int i = 0;i<n-2;i++){
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
        return res;
    }
};