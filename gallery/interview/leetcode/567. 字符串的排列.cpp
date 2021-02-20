/*

https://leetcode-cn.com/problems/permutation-in-string/

https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1016/

更新窗口的时候要判断ch是不是在s1中


https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/

https://leetcode-cn.com/problems/permutation-in-string/solution/zhu-shi-chao-xiang-xi-de-hua-dong-chuang-rc7d/


滑动窗口只是一个思路, 硬套模板容易思维僵化

*/


// 字串必定连续, 联想到滑动窗口


// 执行用时：
// 28 ms
// , 在所有 C++ 提交中击败了
// 22.96%
// 的用户
// 内存消耗：
// 7.4 MB
// , 在所有 C++ 提交中击败了
// 26.10%
// 的用户


class Solution {
public:


    void print_window(map<char, int> window_counter){
        cout<<"----------"<<endl;
        for(auto it : window_counter){
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<"----------"<<endl;
    }


    bool checkInclusion(string s1, string s2) {
        // s2 include unordered s1 ?

        int target_len = s1.size();
        int hit_char_cnt = 0;


        int right = 0;
        int left = 0;
        int target_char_cnt = 0;
        map<char, int> window_counter;
        map<char, int> s1_stat;
        for(auto c : s1){
            s1_stat[c]++;
        }
        target_char_cnt = s1_stat.size();
        

        // 这里有个限制条件 window的长度必须是s1的长度
        // 因此只需要一重循环, 不需要收缩窗口, 只需要更新窗口
        while(right < s2.size()){
            char right_c = s2[right++];
            window_counter[right_c]++;
            if(s1_stat.count(right_c) and s1_stat[right_c] == window_counter[right_c]){
                hit_char_cnt++;
            }


            if(right - left == target_len){
                // print_window(window_counter);
                if(hit_char_cnt == target_char_cnt){
                    return true;
                }
                else{
                    char left_c = s2[left];
                    window_counter[left_c]--;
                    if(s1_stat.count(left_c) and s1_stat[left_c] == window_counter[left_c] + 1){
                        hit_char_cnt--;
                    }
                    left++;
                }
                // print_window(window_counter);
            }
        }
        return false;
    }
};



