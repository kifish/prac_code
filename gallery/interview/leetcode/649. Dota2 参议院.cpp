/*

https://leetcode-cn.com/problems/dota2-senate/

https://leetcode-cn.com/problems/dota2-senate/solution/java-649dota2can-yi-yuan-chao-9961-by-mu-0dqh/

https://leetcode-cn.com/problems/dota2-senate/solution/dota2-can-yi-yuan-by-leetcode-solution-jb7l/



执行结果：
通过
显示详情
添加备注

执行用时：
8 ms
, 在所有 C++ 提交中击败了
79.09%
的用户
内存消耗：
7.9 MB
, 在所有 C++ 提交中击败了
41.83%
的用户


class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dire_q;
        queue<int> radiant_q;
        int n = senate.size();
        for(int idx = 0; idx < senate.size(); idx++){
            char ch = senate[idx];
            if(ch == 'R')
                radiant_q.push(idx);
            else
                dire_q.push(idx);
        }
        
        while(!radiant_q.empty() && !dire_q.empty()){
            int cur_dire = dire_q.front();
            dire_q.pop();
            int cur_radiant = radiant_q.front();
            radiant_q.pop();
            if(cur_radiant < cur_dire){
                radiant_q.push(cur_radiant + n);
            }
            else{
                dire_q.push(cur_dire + n);
            }
        }
        if(!radiant_q.empty()) return "Radiant";
        else return "Dire";
    }
};


*/