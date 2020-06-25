// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/

// unordered_map 就是哈希表（字典），它的一个方法 count(key) 相当于 Java 的 containsKey(key) 可以判断键 key 是否存在。

// 可以使用方括号访问键对应的值 map[key]。需要注意的是，如果该 key 不存在，C++ 会自动创建这个 key，并把 map[key] 赋值为 0。

// 所以代码中多次出现的 map[key]++ 相当于 Java 的 map.put(key, map.getOrDefault(key, 0) + 1)。

// 作者：labuladong
// 链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 执行用时 :
// 72 ms
// , 在所有 C++ 提交中击败了
// 22.55%
// 的用户
// 内存消耗 :
// 8.7 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        unordered_map<char,int> target, window;
        for(auto c : p){
            target[c]++;
        }

        int left = 0;
        int right = 0;
        int valid_char_cnt = 0;
        while(right < s.size()){
            char c = s[right];
            if(target.count(c)){
                window[c]++;
                if(window[c] == target[c]){
                    valid_char_cnt++;
                }
            }
            right++;
            

            while(right - left >= p.size()){ // 闭开区间;只有right-left>=p.size()才有left收缩的必要
                if(valid_char_cnt == target.size()){ 
                    //有可能出现这种case
                    // "baa"
                    // "aa"
                    ret.push_back(left);
                }

                char left_c = s[left];
                //  更新窗口
                if(target.count(left_c)){
                    if(window[left_c] == target[left_c]){
                        valid_char_cnt--;
                    }
                    window[left_c]--;
                }
                left++;
            }
        }
        return ret;
    }
};

