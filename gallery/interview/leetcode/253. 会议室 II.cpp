// 给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

// 示例 1:

// 输入: [[0, 30],[5, 10],[15, 20]]
// 输出: 2
// 示例 2:

// 输入: [[7,10],[2,4]]
// 输出: 1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/meeting-rooms-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 贪心即可

// https://leetcode-cn.com/problems/meeting-rooms-ii/solution/hui-yi-shi-ii-by-leetcode/

// 这样写的pq 的运算符重载有点问题
// class Solution {
// public:
//     // https://blog.csdn.net/AAMahone/article/details/82787184
//     static bool cmp(vector<int> & a, vector<int> &b){
//         return a[1] < b[1];
//     }
//     priority_queue<vector<int>, vector<vector<int> >, cmp> pq;
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         int max_room = 0;
//         for(auto &interval : intervals){
//             if(!pq.empty()){
//                 int first_end = pq.top()[1];
//                 if(first_end <= interval[0]){
//                     pq.pop();
//                     pq.push(interval);
//                 }
//                 else{
//                     pq.push(interval);
//                     max_room = max(max_room, pq.size());
//                 }
//             }
//             else{
//                 pq.push(interval);
//                 max_room = max(max_room, pq.size());
//             }
//         }
//         return max_room;
//     }
// };

// https://leetcode-cn.com/problems/meeting-rooms-ii/solution/c-you-xian-dui-lie-xiao-ding-dui-by-lihuihui-amtf/
// c实现优先队列即堆


// https://blog.csdn.net/AAMahone/article/details/82787184

// class Solution {
// public:
//     // https://blog.csdn.net/AAMahone/article/details/82787184
//     // 这样无法重载vector 的 < 
//     bool operator < (vector<int>  a, vector<int> b){
//         return a[1] < b[1];
//     }
//     priority_queue<vector<int> > pq; // 结束时间早点跑在队首
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         int max_room = 0;
//         for(auto &interval : intervals){
//             if(!pq.empty()){
//                 int first_end = pq.top()[1];
//                 if(first_end <= interval[0]){
//                     pq.pop();
//                     pq.push(interval);
//                 }
//                 else{
//                     pq.push(interval);
//                     max_room = max(max_room, pq.size());
//                 }
//             }
//             else{
//                 pq.push(interval);
//                 max_room = max(max_room, pq.size());
//             }
//         }
//         return max_room;
//     }
// };

// 这么写pq还是有问题
// class Solution {
// public:
//     // https://blog.csdn.net/AAMahone/article/details/82787184
//     struct Node
//     {
//         int s;
//         int e;
//         Node(int x, int y):s(x),e(y){}
//     };
    
//     bool operator < (Node & a, Node & b){
//         return a.e < b.e;
//     }

//     priority_queue<Node> pq; // 结束时间早的排在队首
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         int max_room = 0;
//         for(auto &interval : intervals){
//             if(!pq.empty()){
//                 int first_end = pq.top().e;
//                 if(first_end <= interval[0]){
//                     pq.pop();
//                     pq.push(Node(interval[0], interval[1]));
//                 }
//                 else{
//                     pq.push(Node(interval[0], interval[1]));
//                     max_room = max(max_room, pq.size());
//                 }
//             }
//             else{
//                 pq.push(Node(interval[0], interval[1]));
//                 max_room = max(max_room, pq.size());
//             }
//         }
//         return max_room;
//     }
// };


// 这样写还是不行, 有可能是因为operator < 重载的时候本身已经在Solution这个类里面。
// class Solution {
// public:
//     // https://blog.csdn.net/AAMahone/article/details/82787184
//     struct Node
//     {
//         int s;
//         int e;
//         Node(int x, int y):s(x),e(y){}
//     };
    
//     bool operator < (const Node & a, const Node & b){ // 如果有& 则必须有const
//         return a.e < b.e;
//     }

//     priority_queue<Node> pq; // 结束时间早的排在队首
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         int max_room = 0;
//         for(auto &interval : intervals){
//             if(!pq.empty()){
//                 int first_end = pq.top().e;
//                 if(first_end <= interval[0]){
//                     pq.pop();
//                     pq.push(Node(interval[0], interval[1]));
//                 }
//                 else{
//                     pq.push(Node(interval[0], interval[1]));
//                     max_room = max(max_room, pq.size());
//                 }
//             }
//             else{
//                 pq.push(Node(interval[0], interval[1]));
//                 max_room = max(max_room, pq.size());
//             }
//         }
//         return max_room;
//     }
// };



// 执行用时 :
// 100 ms
// , 在所有 C++ 提交中击败了
// 15.63%
// 的用户
// 内存消耗 :
// 18.9 MB
// , 在所有 C++ 提交中击败了
// 14.29%
// 的用户

// class Solution {
// public:
//     // https://blog.csdn.net/AAMahone/article/details/82787184
//     struct Node
//     {
//         int s;
//         int e;
//         Node(int x, int y):s(x),e(y){}
//         bool operator < (const Node & node) const { // 如果有& 则必须有const
//             return e > node.e; //结束时间早的排在队首;这个规律和sort里的反一反;如果是sort那么应该是e<node.e
//         }
//     };
    

//     static bool cmp(vector<int>& a, vector<int> b){
//         return a[0] < b[0];
//     }

//     priority_queue<Node> pq; // 结束时间早的排在队首
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         int max_room = 0;
//         sort(intervals.begin(), intervals.end(), cmp);
//         for(auto &interval : intervals){
//             if(!pq.empty()){
//                 int first_end = pq.top().e;
//                 if(first_end <= interval[0]){
//                     pq.pop();
//                     pq.push(Node(interval[0], interval[1]));
//                 }
//                 else{
//                     pq.push(Node(interval[0], interval[1]));
//                     int cur_rooms = pq.size();
//                     max_room = max(max_room, cur_rooms);
//                 }
//             }
//             else{
//                 pq.push(Node(interval[0], interval[1]));
//                 int cur_rooms = pq.size();
//                 max_room = max(max_room, cur_rooms);
//             }
//         }
//         return max_room;
//     }
// };

// 打破思维惯式, 把一个会议拆开, 分成独立的开始时间和结束时间

// 下面这个算法更快
// 应该是最优解法了
// 题目就是要统计同一时刻进行的最大会议的数量
// 我们可以把所有的开始时间和结束时间放在一起排序，
// 用cur表示当前进行的会议数量，遍历排序后的时间数组
// 如果是开始时间，cur加1，如果是结束时间，cur减一
// 在遍历的过程中，cur出现的最大值就是需要的房间数。

// 作者：loick
// 链接：https://leetcode-cn.com/problems/meeting-rooms-ii/solution/tong-ji-tong-shi-jin-xing-de-hui-yi-by-loick/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 执行用时 :
// 32 ms
// , 在所有 C++ 提交中击败了
// 77.06%
// 的用户
// 内存消耗 :
// 11.3 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    // https://blog.csdn.net/AAMahone/article/details/82787184
    struct Node
    {
        int t;
        int s_or_e;// s:1 ; e:-1
        Node(int x, int y):t(x),s_or_e(y){}
        bool operator < (const Node & node) const { 
            if(t != node.t)
                return t < node.t;
            else 
                return s_or_e < node.s_or_e;
        }
    };

    // 为了解决这种情况

    // 输入:
    // [[13,15],[1,13]]
    // 输出
    // 2
    // 预期结果
    // 1

    // 所以排序的时候, 如果出现起始时间和结束时间相等的情况, 则让结束时间排在起始时间之前

    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<Node> nodes;
        for(auto & interval : intervals){
            nodes.push_back(Node(interval[0],1));
            nodes.push_back(Node(interval[1],-1));
        }
        sort(nodes.begin(),nodes.end());
        int cur_room_cnt = 0;
        int max_room_cnt = 0;
        for(auto & node : nodes){
            cur_room_cnt += node.s_or_e;
            max_room_cnt = max(max_room_cnt,cur_room_cnt);
        }
        return max_room_cnt;
    }
};