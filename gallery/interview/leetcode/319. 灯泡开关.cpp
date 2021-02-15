// https://leetcode-cn.com/problems/bulb-switcher/

// 数学题 https://leetcode-cn.com/problems/bulb-switcher/solution/wei-shi-yao-ping-fang-shu-yi-ding-shi-liang-zhao-d/

/*
什么，你又不知道什么是完全平方数了？完全平方指用一个整数乘以自己例如1×1，2×2，3×3等，依此类推。若一个数能表示成某个整数的平方的形式，则称这个数为完全平方数。

作者：ivan1
链接：https://leetcode-cn.com/problems/bulb-switcher/solution/bu-jiu-shi-qiu-ping-fang-gen-ma-by-ivan1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




class Solution {
public:
    int bulbSwitch(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int tmp = sqrt(i);
            if(tmp * tmp == i) {
                cnt++;
            }
        }
        return cnt;
    }
};


*/


