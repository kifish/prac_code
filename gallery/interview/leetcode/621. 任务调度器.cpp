
// 以n+1个任务为一轮
// 该轮里第一个任务为目前剩余次数最多的任务, 最后一个任务与第一个任务相同

// WA
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         if(n == 0){
//             return tasks.size();
//         }

//         vector<int> left_nums(26, 0);
//         //由于之后会排序, 因此这里不是hash
//         for(auto task : tasks){
//             left_nums[task - 'A']++;
//         }        
        
//         sort(left_nums.begin(),left_nums.end());
//         int cnt = 0;
//         int cur_cnt = 0;
//         while(left_nums.back() > 0){
//             for(int i = left_nums.size() -1 ; i >=0 ;i--){
//                 left_nums[i]--;
//                 cnt++;
//                 cur_cnt++;

//                 if(cur_cnt == n +1){
//                     break;
//                 }
//             }

//             if(left_nums.back() > 0){

//                 while(cur_cnt != n+1){
//                     cnt++;
//                     cur_cnt++;
//                 }
//                 cur_cnt = 0;

//                 cnt++;
//                 left_nums[left_nums.size() - 1]--;

//             }
//             // 需要重新排序
//              sort(left_nums.begin(),left_nums.end());
//         }
//         return cnt;
//     }
// };

// https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/

// ["A","A","A","A","A","A","B","C","D","E","F","G"]
// 2

// 执行用时 :
// 140 ms
// , 在所有 C++ 提交中击败了
// 26.31%
// 的用户
// 内存消耗 :
// 7.6 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> left_nums(26, 0);
        //由于之后会排序, 因此这里不是hash
        for(auto task : tasks){
            left_nums[task - 'A']++;
        }        
        
        sort(left_nums.begin(),left_nums.end());

        int cnt = 0;
        int cur_cnt = 0;
        while(left_nums.back() > 0){
            for(int i = left_nums.size() -1 ; i >=0 ;i--){
                if(left_nums[i] > 0){      // 有可能是最后一轮了; 所以要判断剩余次数
                    left_nums[i]--;
                    cnt++;
                    cur_cnt++;

                    if(cur_cnt == n + 1){ // 这一轮最多做n+1个任务;如果n=0,相当于一轮可以做无穷多任务
                        break;
                    }
                }
                else{
                    break;
                }
            }
            // 空挡
            if(left_nums.back() > 0){
                if(n > 0){
                    while(cur_cnt != n + 1){
                        cnt++;
                        cur_cnt++;
                    }
                }

                cur_cnt = 0;
            }

            // 有无冷却cd都需要重新排序; 如果想逻辑干净点其实可以一开始对n直接特判,而且这样更高效
            sort(left_nums.begin(),left_nums.end());
        }
        return cnt;
    }
};