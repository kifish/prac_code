
// https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode-solution/

// hash + 暴力

// [9000,8999,8998,8997,8996,8995,8994,8993,8992,8991,8990,8989,8988,8987,8986,8985,8984,8983,8982,8981,8980,8979,8978,8977,8976,8975,8974,8973,8972,8971,8970,8969,8968,8967,8966,8965,8964,8963,8962,8961,8960,8959,8958,8957,8956,8955,8954,8953,8952,8951,8950,8949,8948,8947,8946,8945,8944,8943,8942,8941,8940,8939,8938,8937,8936,8935,8934,8933,8932,8931,8930,8929,8928,8927,8926,8925,8924,8923,8922,8921,8920,8919,8918,8917,8916,8915,8914,8913,8912,8911,8910,8909,8908,8907,8906,8905,8904,8903,8902,8901,8900,8899,8898,8897,8896,8895,8894,8893,8892,8891,8890,8889,8888,8887,8886,8885,8884,8883,8882,8881,8880,8879,8878,8877,8876,8875,8874,8873,8872,8871,8870,8869,8868,8867,8866,8865,8864,8863,8862,8861,8860,8859,8858,8857,8856,8855,8854,8853,8852,8851,8850,8849,8848,8847,8846,8845,8844,8843,8842,8841,8840,8839,8838,8837,8836,8835,8834,8833,8832,8831,8830,8829,8828,8827,8826,8825,8824,8823,8822,8821,8820,8819,8818,8817,8816,8815,8814,8813,8812,8811,8810,8809,8808,8807,8806,8805,8804,8803,8802,8801

// TLE 
// class Solution {
// public:
//     unordered_set<int> unique_nums;

//     int longestConsecutive(vector<int>& nums) {
//         for(auto & num : nums){
//             unique_nums.insert(num);
//         }

//         int ret = 0;
//         for(auto & num : nums){
//             int cur_len = 1;
//             if(unique_nums.count(num - 1)){ // 先判断有没有正好比num 小1的数字
//                 cur_len++;
//             }
//             int cur_num = num;
//             while (unique_nums.count(cur_num + 1))
//             {
//                 cur_len++;
//                 cur_num = cur_num + 1;
//             }
            
//             ret = max(ret, cur_len);

//         }
//         return ret;
//     }
// };


// 下面这个是最优的解法, O(n)

// 执行用时：
// 16 ms
// , 在所有 C++ 提交中击败了
// 91.75%
// 的用户
// 内存消耗：
// 10.9 MB
// , 在所有 C++ 提交中击败了
// 6.67%
// 的用户


class Solution {
public:
    unordered_set<int> unique_nums;
    int longestConsecutive(vector<int>& nums) {
        for(auto & num : nums){
            unique_nums.insert(num);
        }
        int ret = 0;
        for(auto & num : nums){
            if(!unique_nums.count(num - 1)){ 
                // 如果没有比num正好小1的数, 则开始遍历, 因为num是一个可以作为起点的数
                // 举例数字是1 4 3 9 10  (4 这个数其实就没必要判断, 因为判断3的时候就会去判断4) 同理10也是一样
                int cur_len = 1;
                int cur_num = num;
                while (unique_nums.count(cur_num + 1))
                {
                    cur_len++;
                    cur_num = cur_num + 1;
                }
            
                ret = max(ret, cur_len);
            }
        }
        return ret;
    }
};


// 举例数字是1 4 3 9 10  (4 这个数其实就没必要判断, 因为判断3的时候就会去判断4) 同理10也是一样

// 因此自然而然地想到并查集, {1} {3,4} {9,10} 这三组数分别是独立的集合

// 统计不同集合中的数的个数取最大即可



// https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/cbing-cha-ji-xie-fa-dai-ma-ji-duan-by-leck/



