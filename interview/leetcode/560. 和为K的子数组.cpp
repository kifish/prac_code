
// 枚举区间两端i和j,那么复杂度最高O(n^2)
// 数组的长度为 [1, 20,000]
// 说明不能靠枚举


// 此题数并不都是正整数, 不能靠滑动窗口


// 执行用时 :
// 160 ms
// , 在所有 C++ 提交中击败了
// 32.77%
// 的用户
// 内存消耗 :
// 22.5 MB
// , 在所有 C++ 提交中击败了
// 6.67%
// 的用户


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> sum2cnt;
        sum2cnt[0] = 1; // 数学上不对, 但是方便代码实现
        int ret = 0;
        int pre_sum = 0;
        for(int i = 0;i<nums.size();i++){
            pre_sum += nums[i];
            int target = pre_sum - k; // 以i结尾;看起点在哪
            if(sum2cnt.count(target)){ // 这里的sum是指从idx 0一直加到idx j (j < i)
                ret += sum2cnt[target];
            }
            if(sum2cnt.count(pre_sum))
                sum2cnt[pre_sum] += 1;
            else 
                sum2cnt[pre_sum] = 1;
        }
        return ret;
    }
};