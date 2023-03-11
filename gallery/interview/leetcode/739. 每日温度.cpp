// https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode/
// 栈的方法很巧妙

// 执行用时 :
// 168 ms
// , 在所有 C++ 提交中击败了
// 15.93%
// 的用户
// 内存消耗 :
// 34.3 MB
// , 在所有 C++ 提交中击败了
// 7.69%
// 的用户

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> next(101,-1);
        vector<int> ret(T.size(),0);
        for(int i = (int)T.size() -1;i>=0;i--){
            int min_index = -1;
            for(int candidate_t = T[i] + 1;candidate_t < next.size();candidate_t++){
                if(next[candidate_t] != -1){
                    if(min_index == -1){
                        min_index = next[candidate_t];
                    }
                    else{
                        min_index = min(min_index, next[candidate_t]);
                    }
                }
            }
            if(min_index != -1){
                ret[i] = min_index - i;
            }
            next[T[i]] = i;
        }
        return ret;
    }
};

class Solution {
    stack<int> s;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret;
        for(int i = int(temperatures.size() - 1); i >= 0; i--){
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                s.pop();
            }
            if(s.empty()){
                ret.push_back(0);
            }
            else{
                ret.push_back(s.top() - i);
            }
            s.push(i);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
