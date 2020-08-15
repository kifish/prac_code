#include<bits/stdc++.h>
using namespace std;

// int count(vector<int> & nums){

//     vector<int> dp_from_left(nums.size(), 0);
//     vector<int> dp_from_right(nums.size(), 0);

//     for(int i = 1;i<=(int)nums.size()-1;i++){
//         if(i == 1){
//             dp_from_left[i] = nums[i];
//         }
//         else{
//             dp_from_left[i] = max(dp_from_left[i-1], nums[i]);
//         }
//     }

//     for(int i = (int) nums.size() -1;i>=1;i--){
//         if(i == (int) nums.size() -1){
//             dp_from_right[i] = nums[i];
//         }
//         else{
//             dp_from_right[i] = max(dp_from_right[i+1], nums[i]);
//         }
//     } 
//     int ret = 0;
//     for(int i = 1;i<nums.size();i++){
//         if(i == (int)nums.size() - 1){
//             if(i == 1 || nums[i] > dp_from_left[i-1]){
//                 ret++;
//             }
//         }
//         else{
//             //题意理解错了
//         }
//     }

//     return ret;
// }

// 还是理解错题意了
// int count(vector<int> & nums){
//     stack<int> s;
//     s.push(INT_MIN);
//     nums.push_back(INT_MIN);
//     int ret = 0;
//     for(auto num : nums){
//         if(!s.empty() && num < s.top()){
//             s.pop(); // 只能作为一次峰值
//             ret++;
//         }
//         else{
//             while(!s.empty() && num > s.top()){ 
//                 s.pop(); // 不可能作为峰值
//             }
//             if(!s.empty() && num == s.top()){
//                 while(!s.empty() && num == s.top()){
//                     s.pop();
//                 }
//             }
//             else{
//                 s.push(num);
//             }
//         }
//     }
//     return ret;
// }


int count(vector<int> & nums){

    vector<int> dp_from_left(nums.size(), 0);
    vector<int> dp_from_right(nums.size(), 0);

    for(int i = 1;i<=(int)nums.size()-1;i++){
        if(i == 1){
            dp_from_left[i] = nums[i];
        }
        else{
            dp_from_left[i] = max(dp_from_left[i-1], nums[i]);
        }
    }

    int ret = 0;
    for(int i = 1;i<nums.size();i++){
        if(i == (int)nums.size() - 1){
            if(i == 1 || nums[i] > dp_from_left[i-1]){
                ret++;
            }
        }
        else{
           if(i == 1){
               if(nums[i] > nums[i+1]){
                   ret++;
               }
           }
           else{
               if(nums[i] > dp_from_left[i-1] && nums[i] > nums[i+1]){
                   ret++;
               }
           }
        }
    }

    return ret;
}




int main(){
    int case_num = 0;
    cin>>case_num;
    vector<int> nums;
    for(int i = 1;i<=case_num;i++){
        int n,tmp;
        cin>>n;
        nums.clear();
        nums.push_back(0); // padding
        while(n--){
            cin>>tmp;
            nums.push_back(tmp);
        }
        int ret = count(nums);
        cout<<"Case #"<<i<<": "<<ret<<endl;
    }
}