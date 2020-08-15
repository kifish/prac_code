


// 这个思路不对

// 输入:
// [[1,3,5,7,9],[2,4,6,8,10],[11,13,15,17,19],[12,14,16,18,20],[21,22,23,24,25]]
// 13
// 输出
// false
// 预期结果
// true

// class Solution {
// public:
//     int m;
//     int n;

//     bool search(vector<vector<int>>& matrix, int target, int x, int y){
//         if(x == m -1 && y != n -1){
//             if(target == matrix[x][y]){
//                 return true;
//             }
//             else if(target < matrix[x][y]){
//                 return false;
//             }
//             if(y+1 <= n-1){
//                 return search(matrix, target,x,y+1);
//             }
//             else return false;
//         }
//         else if(y == n-1 && x != m-1){
//             if(target == matrix[x][y]){
//                 return true;
//             }
//             else if(target < matrix[x][y]){
//                 return false;
//             }
//             if(x+1 <= m-1){
//                 return search(matrix,target,x+1,y);
//             }
//             else return false;
//         }
//         else if(x == m-1 && y == n-1){
//             if(target == matrix[x][y]){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
//         else{
//             bool right_bigger = true;
//             if(matrix[x+1][y] >= matrix[x][y+1]){
//                 right_bigger = false;
//             }
//             if(target < matrix[x][y]){
//                 return false;
//             }
//             else if(target == matrix[x][y]){
//                 return true;
//             }
//             int max_val;
//             if(right_bigger){
//                 max_val = matrix[x][y+1];
//             }
//             else{
//                 max_val = matrix[x+1][y];
//             }
//             if(target >= max_val){
//                 if(right_bigger){
//                     return search(matrix, target,x,y+1);
//                 }
//                 else{
//                     return search(matrix, target,x+1,y);
//                 }
//             }
//             else{
//                 if(right_bigger){
//                     return search(matrix, target,x+1,y);
//                 }
//                 else{
//                     return search(matrix, target,x,y+1);
//                 }
//             }
//         }
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.size() == 0) return false;
//         if(matrix[0].size() == 0) return false;
//         m = matrix.size();
//         n = matrix[0].size();
//         return search(matrix,target,0,0);
//     }
// };


// 几秒前	超出时间限制	N/A	N/A	Cpp
// class Solution {
// public:
//     int m;
//     int n;

//     bool search(vector<vector<int>>& matrix, int target, int x, int y){
//         if(x == m -1 && y != n -1){
//             if(target == matrix[x][y]){
//                 return true;
//             }
//             else if(target < matrix[x][y]){
//                 return false;
//             }
//             if(y+1 <= n-1){
//                 return search(matrix, target,x,y+1);
//             }
//             else return false;
//         }
//         else if(y == n-1 && x != m-1){
//             if(target == matrix[x][y]){
//                 return true;
//             }
//             else if(target < matrix[x][y]){
//                 return false;
//             }
//             if(x+1 <= m-1){
//                 return search(matrix,target,x+1,y);
//             }
//             else return false;
//         }
//         else if(x == m-1 && y == n-1){
//             if(target == matrix[x][y]){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
//         else{
//             bool right_bigger = true;
//             if(matrix[x+1][y] >= matrix[x][y+1]){
//                 right_bigger = false;
//             }
//             if(target < matrix[x][y]){
//                 return false;
//             }
//             else if(target == matrix[x][y]){
//                 return true;
//             }
//             int max_val;
//             if(right_bigger){
//                 max_val = matrix[x][y+1];
//             }
//             else{
//                 max_val = matrix[x+1][y];
//             }
//             if(target >= max_val){
//                 return search(matrix, target,x,y+1) || search(matrix, target,x+1,y);
//             }
//             else{
//                 if(right_bigger){
//                     return search(matrix, target,x+1,y);
//                 }
//                 else{
//                     return search(matrix, target,x,y+1);
//                 }
//             }
//         }
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.size() == 0) return false;
//         if(matrix[0].size() == 0) return false;
//         m = matrix.size();
//         n = matrix[0].size();
//         return search(matrix,target,0,0);
//     }
// };


// 沿着对角线对行和列分别做2分也可以

// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-5-4/


// 数组从左到右和从上到下都是升序的，如果从右上角出发开始遍历呢？

// 会发现每次都是向左数字会变小，向下数字会变大，有点和二分查找树相似。二分查找树的话，是向左数字变小，向右数字变大。

// 所以我们可以把 target 和当前值比较。

// 如果 target 的值大于当前值，那么就向下走。
// 如果 target 的值小于当前值，那么就向左走。
// 如果相等的话，直接返回 true 。
// 也可以换个角度思考。

// 如果 target 的值小于当前值，也就意味着当前值所在的列肯定不会存在 target 了，可以把当前列去掉，从新的右上角的值开始遍历。

// 同理，如果 target 的值大于当前值，也就意味着当前值所在的行肯定不会存在 target 了，可以把当前行去掉，从新的右上角的值开始遍历。

// 作者：windliang
// 链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-5-4/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



// 执行用时 :
// 124 ms
// , 在所有 C++ 提交中击败了
// 67.41%
// 的用户
// 内存消耗 :
// 10.7 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int m;
    int n;

    bool search(vector<vector<int>>& matrix, int target, int x, int y){
        if(target == matrix[x][y]) {
            return true;
        }
        else if(target < matrix[x][y]){
            if(y-1>=0){
                return search(matrix, target, x,y-1);
            }
            else{
                return false;
            }
        }
        else{
            if(x+1 <= m -1){
                return search(matrix, target, x+1, y);
            }
            else{
                return false;
            }
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        if(matrix[0].size() == 0) return false;
        m = matrix.size();
        n = matrix[0].size();
        return search(matrix,target,0,n-1);
    }
};