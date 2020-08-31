


// 输入:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// 输出:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 此处撰写解题思路
// 按照身高降序，同时人数升序排序得到的结果：
// 7 0 | 7 1 | 6 1 | 5 0 | 5 2 | 4 4 |
// 要放到这样的二维数组中：
// _ _ | _ _ | _ _ | _ _ | _ _ | _ _ |
// 想象一下放[7 0]：
// 7 0 | 0 0 | 0 0 | 0 0 | 0 0 | 0 0 |
// 再放[7 1]：
// 7 0 | 7 1 | 0 0 | 0 0 | 0 0 | 0 0 |
// 此时如果要放[6 1]：
// 因为已经按照身高降序排列过了，所以比6高的仅有1个，其位置就应该在1，这样是满足要求的：
// 7 0 | 6 1 | 7 1 | 0 0 | 0 0 | 0 0 |
// 又考虑到不能覆盖已有元素，所以需要移动原有的元素（如上）。如果现在要插入[5 0]，因为前面的都比5大，
// 所以只能把[5 0]放到第一个位置，其余的元素都往右挪动，到其原本的位置：
// 5 0 | 7 0 | 6 1 | 7 1 | 0 0 | 0 0 |
// 同理，大于等于5的元素有两个，现在都是大于等于5的元素，所以放在第二个位置，其余的往右平移：
// 5 0 | 7 0 | 5 2 | 6 1 | 7 1 | 0 0 |
// 5 0 | 7 0 | 5 2 | 6 1 | 4 4 | 7 1 |

// 作者：qwer-30
// 链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/cyu-yan-by-qwer-30-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/cyu-yan-by-qwer-30-2/


// STL vector insert : https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/

// https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/gen-ju-shen-gao-zhong-jian-dui-lie-by-leetcode/

// 解题的核心就是先排个子高的;再排个子矮的; 这样不会影响k的正确性

// 执行用时 :
// 332 ms
// , 在所有 C++ 提交中击败了
// 41.99%
// 的用户
// 内存消耗 :
// 11.3 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){ // 需要加个static
        if(a[0] > b[0]){
            return true; // 高的排在前面
        }
        else if(a[0] < b[0]){
            return false;
        }
        else{
            return a[1] < b[1];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ret;
        for(auto & p : people){
            ret.insert(ret.begin()+p[1],p);
        }
        return ret;
    }
};


// 用list插入更高效
