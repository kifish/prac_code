// https://leetcode-cn.com/problems/candy/solution/candy-cong-zuo-zhi-you-cong-you-zhi-zuo-qu-zui-da-/

// 执行用时 :
// 44 ms
// , 在所有 C++ 提交中击败了
// 62.46%
// 的用户
// 内存消耗 :
// 17.4 MB
// , 在所有 C++ 提交中击败了
// 50.00%
// 的用户


// 为什么两次dp取max就行了? 因为糖果数变多一定不会违反原来的规则, 取max之后 左规则和右规则一定全满足了, 从而符合题意


class Solution {
public:

    int candy(vector<int>& ratings) {
        vector<int> dp_from_left(ratings.size(), 1);
        vector<int> dp_from_right(ratings.size(), 1);
        for(int i = 1;i<ratings.size();i++){
            if(ratings[i] > ratings[i-1]){
                dp_from_left[i] = dp_from_left[i-1] + 1;
            }
        }
        for(int i = (int) ratings.size() - 2; i >=0 ; i--){
            if(ratings[i] > ratings[i+1]){
                dp_from_right[i] = dp_from_right[i+1] + 1;
            }
        }
        int sum = 0;
        for(int i = 0;i<dp_from_left.size();i++){
            sum += max(dp_from_left[i], dp_from_right[i]);
        }
        return sum;
    }
};


