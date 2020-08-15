/*

https://leetcode-cn.com/problems/insert-interval/



https://leetcode-cn.com/problems/insert-interval/solution/coordai-ma-by-shufan-h/


*/


/*

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);
        ans.push_back(newInterval);
        while (i < intervals.size()) {
            vector<int> &itvl1 = ans[ans.size()-1], &itvl2 = intervals[i++];
            if (itvl2[0] <= itvl1[1])  itvl1[1] = max(itvl1[1], itvl2[1]);
            else ans.push_back(itvl2);
        }
        return ans;
    }
};


wrong

*/


/*

优化了一下,AC

执行用时：
16 ms
, 在所有 C++ 提交中击败了
95.82%
的用户
内存消耗：
10.6 MB
, 在所有 C++ 提交中击败了
28.00%
的用户


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);
        ans.push_back(newInterval);
        bool first = true;
        while (i < intervals.size()) {
            vector<int> &itvl1 = ans[ans.size()-1], &itvl2 = intervals[i++];
            if (itvl2[0] <= itvl1[1]) {
                if(first){
                    itvl1[0] = min(itvl1[0], itvl2[0]);
                    first = !first;
                }
                itvl1[1] = max(itvl1[1], itvl2[1]);
            } 
            else ans.push_back(itvl2);
        }
        return ans;
    }
};




*/