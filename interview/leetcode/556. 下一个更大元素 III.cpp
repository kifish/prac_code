
/*

https://leetcode-cn.com/problems/next-greater-element-iii/solution/xia-yi-ge-geng-da-yuan-su-iii-by-leetcode/

raw:
1 5 8 4 7 6 5 3 1
-->
1 5 8 5 7 6 4 3 1
-->
1 5 8 5 1 3 4 6 7

https://leetcode-cn.com/problems/next-greater-element-iii/solution/dan-diao-zhan-jian-dan-ying-yong-shuang-100-by-con/

感觉不需要用到栈

https://leetcode-cn.com/problems/next-greater-element-iii/solution/cshuang-100si-lu-kan-zhu-shi-by-cloudair-2/

*/

// 1999999999

// 注意这个case 没有更大的数了, 因为换一下位置就会溢出

// 超出32位 int 的表示范围


// 执行用时 :
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗 :
// 5.9 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int the_index = 0; // the index of num to be swapped
        // bool found_a_small_num = false;
        for(the_index = (int) s.size() - 2; the_index >=0 ; the_index--){
            if(s[the_index] < s[the_index + 1]){
                // found_a_small_num = true;
                break;
            }           
        }
        // if(!found_a_small_num){
        //     return -1;
        // }
        if(the_index == -1){
            return -1;
        }
        else{
            int the_other_index = the_index + 2;
            for(;the_other_index < s.size();the_other_index++){
                if(s[the_other_index] <= s[the_index]){ // 注意这里是等于号
                    break;
                }
            }

            // cout<<"s : size : "<< s.size() << endl;
            // cout<<"the_other_index : "<< the_other_index << endl;

            the_other_index -= 1;
            // cout<< "before : "<<s<<endl;
            swap(s[the_index], s[the_other_index]);
            // cout<< "after : "<<s<<endl;
            reverse(s.begin() + the_index + 1, s.end()); // 闭开区间
            // cout<< "after  reverse : "<<s<<endl;
            long long ret = 0;
            for(int i = 0;i<s.size();i++){
                ret = ret * 10 + s[i] - '0';
            }
            if(ret > INT_MAX){
                return -1;
            }
            else{
                return ret;
            }
            // return stoi(s); 可能会溢出
        }
    }
};