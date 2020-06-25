class Solution
{
public:
    // 1 t
    // 2 t
    // 3 t
    // 4 f
    // 5 t
    // 6 t
    // 7 t
    // 8 f
    // 9 t
    bool canWinNim(int n) // n == 0?
    {
        if(n % 4 == 0) return false;
        return true;
    }
};