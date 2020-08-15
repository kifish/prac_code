// https://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html

// AC
// class Solution {
// public:

//     int bit_count(int n){
//         int cnt = 0;
//         while(n){
//             n &= n -1; // Çå³ý×îÓÒ±ßµÄ1
//             cnt++;
//         }
//         return cnt;
//     }
//     vector<int> countBits(int num) {
//         vector<int> ret;
//         for(int i = 0;i<=num;++i){
//             ret.push_back(bit_count(i));
//         }
//         return ret;
//     }
// };

// https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/
class Solution {
public:

    vector<int> countBits(int num) {
        vector<int> ret(num + 1,0);
        ret[0] = 0;
        for(int i = 1;i<=num;i++){
            if(i % 2 == 0){
                ret[i] = ret[i/2];
            }
            else{
                ret[i] = ret[i-1] + 1;
            }
        }
        return ret;
    }
};