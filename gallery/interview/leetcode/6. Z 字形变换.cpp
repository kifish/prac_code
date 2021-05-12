
/*

模拟题

https://leetcode-cn.com/problems/zigzag-conversion/solution/6-z-zi-xing-bian-huan-c-c-by-bian-bian-xiong/

*/
class Solution {
public:
    string convert(string s, int numRows) {
        
    }
};


/*

执行结果：
通过
显示详情
添加备注

执行用时：
40 ms
, 在所有 C++ 提交中击败了
15.96%
的用户
内存消耗：
13.8 MB
, 在所有 C++ 提交中击败了
14.57%
的用户

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1){
            return s;
        }
        
        vector<vector<char>> G(numRows, vector<char> {});
        for(int i = 0;i < s.size();i++){
            char the_ch = s[i];
            int row_idx = i % (numRows + numRows - 2);
            if(row_idx < numRows){
                ;
            }
            else{
                row_idx = numRows - 2 - (row_idx % numRows);
            }
            G[row_idx].push_back(the_ch);
        }
        string ret = "";
        for(auto & row : G){
            for(auto & ch : row)
                ret += ch;
        }
        return ret;
    }
};

*/