/*
https://leetcode-cn.com/problems/optimal-account-balancing/solution/bao-li-hui-su-by-powcai/


解法思路, 暴力回溯

给每个人建立一个账户
account[i] 表示的第i个人的收支情况
如果他借给别人5快, 则这个人的收支+5
如果欠别人5块, 则这个人的收支-5

最终的平衡状态是所有人的账户收支为0

注意要剪枝


*/


class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {

    }
};