// 这个解法是子序列，不是子数组，子数组要求连续
// class Solution {
// public:
//     int cnt = 0;
//     int sum_th = 0;
//     set<vector<int>> paths;
//     void dfs(vector<int>& arr,int left,int start_idx,int cur_sum,vector<int>& path){
//         if(left == 0 || start_idx == arr.size()){
//             if(cur_sum >= sum_th && left == 0){
//                 cnt++;
//                 paths.insert(path);
//             }
//             return;
//         }
//         path.push_back(arr[start_idx]);
//         dfs(arr,left-1,start_idx+1,cur_sum+arr[start_idx],path);
//         path.pop_back();
//         dfs(arr,left,start_idx+1,cur_sum,path);
//     }
//     int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//         sum_th = k * threshold;
//         // dfs
//         vector<int> path;
//         dfs(arr,k,0,0,path);
//         for(auto path : paths){
//             for(auto v : path){
//                 cout<<v<<" ";
//             }
//             cout<<endl;
//         }
//         return paths.size();
//     }
// };

// TLE 
// class Solution {
// public:
//     int cnt = 0;
//     int sum_th = 0;
//     void dfs(vector<int>& arr,int left,int start_idx,int cur_sum,vector<int>& path){
//         if(left == 0 || start_idx == arr.size()){
//             if(cur_sum >= sum_th && left == 0){
//                 bool contiguous = true;
//                 for(int i = 1;i<path.size();i++){
//                     if(path[i] != path[i-1] + 1){
//                         contiguous = false;
//                         break;
//                     }
//                 }
//                 if(contiguous){
//                     cnt++;
//                 }
//             }
//             return;
//         }
//         path.push_back(start_idx);
//         dfs(arr,left-1,start_idx+1,cur_sum+arr[start_idx],path);
//         path.pop_back();
//         dfs(arr,left,start_idx+1,cur_sum,path);
//     }
//     int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//         sum_th = k * threshold;
//         // dfs
//         vector<int> path;
//         dfs(arr,k,0,0,path);
//         return cnt;
//     }
// };


// TLE
// class Solution {
// public:
//     int cnt = 0;
//     int sum_th = 0;
//     int global_k = 0;
//     void dfs(vector<int>& arr,int left,int start_idx,int cur_sum,vector<int>& path){
//         if(left == 0 || start_idx == arr.size()){
//             if(cur_sum >= sum_th && left == 0){
//                 bool contiguous = true;
//                 if(path.size() > 1 && path.back() - path[0] != global_k - 1){
//                     contiguous = false;
//                 }
//                 if(contiguous){
//                     cnt++;
//                 }
//             }
//             return;
//         }
//         path.push_back(start_idx);
//         dfs(arr,left-1,start_idx+1,cur_sum+arr[start_idx],path);
//         path.pop_back();
//         dfs(arr,left,start_idx+1,cur_sum,path);
//     }
//     int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//         sum_th = k * threshold;
//         global_k = k;
//         // dfs
//         vector<int> path;
//         dfs(arr,k,0,0,path);
//         return cnt;
//     }
// };

class Solution {
public:
    int cnt = 0;
    int sum_th = 0;


    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        sum_th = k * threshold;
        // 滑动窗口
        int cur_sum = 0;
        int the_first_num_idx = 0;
        int cur_v_num = 0;
        for(int idx = 0;idx < arr.size();idx++){
            int num = arr[idx];
            if(cur_v_num == k){
                cur_sum = cur_sum - arr[the_first_num_idx] + num;
                the_first_num_idx++;
                if(cur_sum >= sum_th){
                    cnt++;
                }
            }
            else{
                cur_sum += num;
                cur_v_num++;
                if(cur_v_num == k){
                    if(cur_sum >= sum_th)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};