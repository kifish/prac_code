/*
https://leetcode-cn.com/problems/gas-station/

https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode/

分开来理解total_sum和cur_sum
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_idx = 0;
        int cur_sum = 0;
        int total_sum = 0;
        for(int i = 0; i < gas.size(); i++){
            cur_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if(cur_sum < 0){
                start_idx = i + 1;
                cur_sum = 0;
            }
        }
        if(total_sum < 0){
            return -1;
        }
        else{
            return start_idx;
        }
    }
};
