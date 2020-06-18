

// 13
// 输出
// [1,10,11,12,13,2,3,4,5,6,7,8,9,10,11,12,13]
// 预期结果
// [1,10,11,12,13,2,3,4,5,6,7,8,9]

// class Solution {
// public:
//     vector<int> ret;
//     int global_n;
//     void dfs(int prefix){
//         // 根 左 右 : 先序列遍历
//         if(prefix > global_n) {
//             return;
//         }

//         ret.push_back(prefix);
//         dfs(prefix * 10);
//         dfs(prefix+1); // 注意这棵树并不是常规树的行政, 左子树是正常的,但是右子树是平行的(相当于同一层)

//     }

//     vector<int> lexicalOrder(int n) {
//         global_n = n;
//         dfs(1);
//         return ret;
//     }
// };



// 执行用时 :
// 24 ms
// , 在所有 C++ 提交中击败了
// 34.49%
// 的用户
// 内存消耗 :
// 12.4 MB
// , 在所有 C++ 提交中击败了
// 20.00%
// 的用户


class Solution {
public:
    vector<int> ret;
    int global_n;
    void dfs(int prefix){
        // 根 左 右 : 先序列遍历
        if(prefix > global_n) {
            return;
        }

        ret.push_back(prefix);
        dfs(prefix * 10);
        if((prefix + 1) % 10 > 0)
            dfs(prefix+1); // 注意这棵树并不是常规树的形状, 左子树是正常的,但是右子树是平行的(相当于同一层)
    }

    vector<int> lexicalOrder(int n) {
        global_n = n;
        dfs(1);
        return ret;
    }
};


// https://leetcode-cn.com/problems/lexicographical-numbers/solution/c-jian-dan-dfs-by-da-li-wang/

// 这人写的也挺优雅的, 速度快, 但是思路和我差不多。

