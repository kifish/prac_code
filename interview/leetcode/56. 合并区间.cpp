

// 以前也做过类似的题目:
// gallery\贪心\区间合并.md

// 执行用时 :
// 48 ms
// , 在所有 C++ 提交中击败了
// 46.45%
// 的用户
// 内存消耗 :
// 11.6 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    static bool cmp(const vector<int> & a, const vector<int> & b){
        return a[0] < b[0]; // 按左端点从小到大排序
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        int cur_right = 1<<31; // 最小的int
        sort(intervals.begin(), intervals.end());
        for(auto & interval : intervals){
            if(cur_right < interval[0]){
                cur_right = interval[1];
                ret.push_back(interval);
            }
            else{
                cur_right = max(cur_right, interval[1]);
                int merged_left = ret.back()[0];
                vector<int> merged_interval{merged_left, cur_right};
                ret.pop_back();
                // http://www.cplusplus.com/reference/vector/vector/pop_back/
                ret.push_back(merged_interval);
            }
        }
        return ret;
    }
};


