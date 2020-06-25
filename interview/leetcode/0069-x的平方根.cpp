class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int lo = 0,hi = x;
        int mid;
        while(lo<hi){
            mid = (hi-lo)/2 + lo;
            int tmp = x / mid;
            int tmp2 = x / (mid + 1);
            if(tmp == mid) return mid;
            else if(tmp > mid && tmp2 < mid) return mid;
            else if(tmp < mid) hi = mid;
            else lo = mid + 1;
        }
        return lo-1;//不会到达这一分支
    }
};