/*

https://leetcode-cn.com/problems/permutation-sequence/


https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1021/



https://leetcode-cn.com/problems/permutation-sequence/solution/chun-shu-xue-jie-fa-by-arthurpatten/


*/


// 执行用时：
// 12 ms
// , 在所有 C++ 提交中击败了
// 22.52%
// 的用户
// 内存消耗：
// 6.4 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    void print(vector<int> & v){
        for(auto val : v){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    string getPermutation(int n, int k) {
        vector<int> fac(n+1,0);
        fac[0] = 1;
        for(int i = 1;i<=n;i++){
            fac[i] = fac[i-1] * i;
        }
        vector<int> digits;
        for(int i = 1;i<=n;i++){
            digits.push_back(i);
        }

        // list 不能直接从 idx 取出
        // 删除会高效点
        string ret = "";
        int cur = n; // 从高位开始算
        while (cur > 0){ // k==0的时候其实在模拟取剩下数字的第一个数字; 用 k>=0 来判断其实有问题
            cout<<"cur : "<<cur<<endl;
            cout<<"cur k : "<<k<<endl;
            cout<<"left digits:"<<endl;
            print(digits);
            int idx = k / fac[cur-1]; // 这里的idx是从1开始数的
            cout<<"fac: "<<fac[cur-1]<<endl;
            int idx_fix = idx;
            cout<<"idx : "<<idx<<endl;
            if(idx * fac[cur-1] < k){ // ceil
                idx_fix += 1;
            }
            cout<<"idx_fix : "<<idx_fix<<endl;
            int real_idx = idx_fix - 1;

            // 最后一个数字需要特判?
            // if(real_idx == -1) real_idx = 0;
            // 不用特判, k最后会为1, fac[cur-1]会为1, idx==0 or 1; idx_fix==1
            // 举例, n 123, k 1
            // 1->12->123

            cout<<"real_idx : "<<real_idx<<endl;
            char digit_selected = digits[real_idx] + '0';
            cout<<"digit_selected : "<<digit_selected<<endl;
            ret += digit_selected;
            digits.erase(digits.begin() + real_idx);
            // if(idx * fac[cur-1] < k)
            //     k -= idx * fac[cur-1];
            // else 
            //     k -= (idx-1) * fac[cur-1];
            // 逻辑合并
            k -= (idx_fix-1) * fac[cur-1];
            cur--;
            cout<<"--------------"<<endl;
        }
        return ret;
    }
};




/*

打表

https://leetcode-cn.com/problems/permutation-sequence/solution/c-ji-bai-100-3-xing-dai-ma-shi-xian-by-fu-guang/

*/