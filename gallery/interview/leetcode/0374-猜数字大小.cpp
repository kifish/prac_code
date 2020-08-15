// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1,hi = n;
        while(lo <= hi){
            int mid = (hi - lo) /2 + lo;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == 1) lo = mid + 1;
            else hi = mid -1;
        }
        return -1;
    }
};