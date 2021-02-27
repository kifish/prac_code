/*



https://leetcode-cn.com/problems/longest-repeating-character-replacement/



https://leetcode-cn.com/problems/longest-repeating-character-replacement/comments/770847



https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/ti-huan-hou-de-zui-chang-zhong-fu-zi-fu-n6aza/

中文题目有点迷糊, 看英文的。

Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


https://leetcode-cn.com/problems/longest-repeating-character-replacement/comments/770996


https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/dong-hua-mo-ni-yao-shi-kan-bu-dong-jiu-g-4rpi/


https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/tong-guo-ci-ti-liao-jie-yi-xia-shi-yao-shi-hua-don/

正常的双重while解法:
https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/fen-xiang-zhen-cang-de-shuang-zhi-zhen-m-fdsk/



https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/cji-hu-shuang-bai-de-hua-dong-chuang-kou-pp3g/




执行结果：
通过
显示详情
执行用时：
4 ms
, 在所有 C++ 提交中击败了
95.17%
的用户
内存消耗：
6.8 MB
, 在所有 C++ 提交中击败了
86.66%
的用户




class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> char2cnt(26, 0);
        int left = 0, right = 0;
        int repeat_char_max_cnt = 0;
        while(right < s.size()){
            int the_char = s[right] - 'A';
            char2cnt[the_char]++;
            
            repeat_char_max_cnt = max(repeat_char_max_cnt, char2cnt[the_char]);
            if(right - left + 1 > repeat_char_max_cnt + k){ // 用if 而不是while, 因为每一轮都会检查是否符合条件, 如果多了the_char就不满足条件, 那么说明正好多了1个字符, 也就只需要让left向右移动一个位置, 即可让当前窗口(的长度)重新符合要求。当前窗口最终长度就是最大长度。
                char2cnt[s[left] - 'A']--;
                left++;
            }

            right++;
        }
        return right - left;
    }
};






*/