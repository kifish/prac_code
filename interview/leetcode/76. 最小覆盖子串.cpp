
/*


string find




执行用时：
264 ms
, 在所有 C++ 提交中击败了
22.48%
的用户
内存消耗：
368.6 MB
, 在所有 C++ 提交中击败了
6.25%
的用户



*/

class Solution {
public:
    string minWindow(string s, string t) {
        int valid_ch_cnt = 0;
        int right = 0;
        int left = 0;
        unordered_map<char, int> target;
        for(auto c : t){
            target[c]++;
        }
        unordered_map<char, int> window;
        string ret;
        while(right < s.size()){
            char right_c = s[right];
            if(target.count(right_c)){
                window[right_c]++;
                if(window[right_c] <= target[right_c]){
                    valid_ch_cnt++;
                }
            }
            right++;

            // while(left < right && valid_ch_cnt == t.size()){
            while(valid_ch_cnt == t.size()){
                string tmp = s.substr(left, right - left);
                // cout<<"left :"<<left<<" right :"<<right<<endl;
                if(ret.size() == 0 || tmp.size() < ret.size()){
                    ret = tmp;
                }

                char left_c = s[left];
                if(target.count(left_c)){
                    window[left_c]--;
                    if(window[left_c] < target[left_c]){
                        valid_ch_cnt--;
                    }
                }

                left++;
            }
        }
        return ret;
    }
};



/*


注意我上面的实现和下面这个url里的valid意义不一样. 我的实现, valid_ch_cnt代表总共的字符个数
下面这个url, valid代表总共的unique字符个数


https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/

*/