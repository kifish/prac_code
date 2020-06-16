
// WA

// class Solution {
// public:

//     int partition(vector<string> & nums, int lo, int hi){
//         if(lo == hi) return lo;

//         string pivot = nums[lo];
//         int i = lo; // 跳过pivot
//         int j = hi+1;

//         while(1){
//             i++;
//             j--;
//             while(nums[i] <= pivot && i < hi){ // 避免越界; 注意不是i < j 而是i < hi ;  i<j没测试过
//                 i++;
//             }
//             while(nums[j] >= pivot && j > lo){
//                 j--;
//             }
//             if(i < j){
//                 swap(nums[i], nums[j]);
//             }
//             else{
//                 break;
//             }
//         }
//         swap(nums[lo], nums[j]);
//         return j;
//     }

//     void print_vec(vector<string> & nums){
//         for(auto & num : nums){
//             cout<<num<<" ";
//         }
//         cout<<endl;
//     }
//     string find_kth(vector<string> & nums, int k, int lo,int hi){
//         int pivot_idx = partition(nums, lo, hi);
//         cout<<"pivot_idx : "<<pivot_idx<<endl;
//         print_vec(nums);
//         cout<<"k : "<< k << endl;
//         // IMPORTANT!
//         // 这里有问题
//         if(pivot_idx+1 == k){
//             return nums[k];
//         }
//         else if(pivot_idx+1 > k){
//             return find_kth(nums,k,lo,pivot_idx-1);
//         }
//         else{
//             return find_kth(nums,k - (pivot_idx + 1), pivot_idx + 1, hi);
//         }
//     }

//     int findKthNumber(int n, int k) {
//         vector<string> nums;
//         for(int i = 1;i<=n;i++){
//             nums.push_back(to_string(i));
//         }
//         string ret = find_kth(nums, k, 0, nums.size() - 1);
//         // cout<<ret<<endl;
//         return stoi(ret);
//     }
// };






// 这个实现基本上应该正确，可以用来参考怎么实现第k小。

// 注意由于本题有特殊限制 '字典序'

// 所以这种解法TLE了

// 4289384
// 1922239



// class Solution {
// public:

//     int partition(vector<string> & nums, int lo, int hi){
//         if(lo == hi) return lo;

//         string pivot = nums[lo];
//         int i = lo; // 跳过pivot
//         int j = hi+1;

//         while(1){
//             i++;
//             j--;
//             while(nums[i] <= pivot && i < hi){ // 避免越界; 注意不是i < j 而是i < hi ;  i<j没测试过
//                 i++;
//             }
//             while(nums[j] >= pivot && j > lo){
//                 j--;
//             }
//             if(i < j){
//                 swap(nums[i], nums[j]);
//             }
//             else{
//                 break;
//             }
//         }
//         swap(nums[lo], nums[j]);
//         return j;
//     }

//     void print_vec(vector<string> & nums){
//         for(auto & num : nums){
//             cout<<num<<" ";
//         }
//         cout<<endl;
//     }
//     string find_kth(vector<string> & nums, int k, int lo,int hi){
//         int pivot_idx = partition(nums, lo, hi);
//         // cout<<"pivot_idx : "<<pivot_idx<<endl;
//         // print_vec(nums);
//         // cout<<"k : "<< k << endl;
//         // IMPORTANT!
//         // 这一行代码特别容易忘写
//         // pivot_idx -= lo;
//         //由于pivot_idx是全局的idx, 要变成相对于lo的idx 或者这么写
//         int rank = pivot_idx - lo + 1; // 这里的rank 和 k 都是相对的排序顺序;rank 是代表pivot元素的第几小
//         if(rank == k){
//             return nums[pivot_idx]; // 假设是第1小,则是相对lo的第1小,即nums[lo]
//         }
//         else if(rank > k){
//             return find_kth(nums,k,lo,pivot_idx-1);
//         }
//         else{
//             return find_kth(nums,k - rank, pivot_idx + 1, hi);
//         }
//     }

//     int findKthNumber(int n, int k) {
//         vector<string> nums;
//         for(int i = 1;i<=n;i++){
//             nums.push_back(to_string(i));
//         }
//         string ret = find_kth(nums, k, 0, nums.size() - 1);
//         // cout<<ret<<endl;
//         return stoi(ret);
//     }
// };


// https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/shi-cha-shu-by-powcai/

// 前序遍历
// 模拟前序遍历肯定可以, 这样就是O(k)

//但还可以虚拟模拟树的遍历

// 其实只需要按层节点个数计算即可，图中节点1和节点2在第二层，因为n = 13，节点1可以移动到节点2（同一层）所以在第二层需要移动1步。

// 第三层，移动个数就是 (13 - 10 + 1) = 4 （min（13 + 1， 20） - 10）

// 所以节点1到节点2需要移动 1 + 4 = 5 步

// 作者：powcai
// 链接：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/shi-cha-shu-by-powcai/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 为啥是5步，现在现在n为13图中已经完成把这棵树画出来了
// 字符串'1' 到字符串'2'之间有4个字符串'10' '11' '12' '13' 移动到'2'本身还需要1步, 因此是4 + 1 = 5步

// （min（13 + 1， 20） - 10）
// 10 哪里来的 1*10
// 20 = (1+1)*10

// 再想想哪里来的

// 注意 按照题解的图，从第二层2的节点 虚拟延长一条线到第三层，那么那个节点就是20! 所以我们就知道了第二层的1节点的下面一层的节点个数到底是多少个



// 执行用时 :
// 4 ms
// , 在所有 C++ 提交中击败了
// 16.67%
// 的用户
// 内存消耗 :
// 6.1 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户



class Solution {
public:
    #define LL long long
    int count(LL prefix, int n){ // 该函数求的是当前节点下(当前字符串'1') 通过前序遍历 走到下一个特定字符串('2')需要消耗的步数,通过计算需要5步
        // 计算当前前缀下子节点的个数
        // 看题解第一层为一个节点是0
        // 观察第二层的节点1和节点2
        // 当前字符串是'1', 用LL 表示为prefix
        // 字符串'2'和'1'之前隔了几个数+1 呢？
        LL next_prefix = prefix + 1;
        int cnt = 0;
        while(prefix <= n){
            LL tmp = min((LL) (n + 1), next_prefix);
            cnt += tmp - prefix; // 第一次循环 next_prefix:2 prefix:1 cnt:1
            prefix *= 10;                         //第2次循环 next_prefix:20 prefix:10 cnt:1+4 = 5
            next_prefix *= 10;             // 如果还有第4层, 那么就会有第3次循环
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {

        int cur = 1;
        k--; // 0 不需要消耗一步,假设k为1,即求第k小,那么结果应该是1
        while(k > 0){
            int step_num = count(cur, n);
            if(step_num <= k){
                k -= step_num;
                cur += 1; // 往右边走 (有点bfs的感觉)
            }
            else{
                k -= 1;
                cur *= 10; // 往最左下走 (有点dfs的感觉)
            } // 只会选择这2个方向去搜寻答案
        }
        return cur;
    }
};