#include<bits/stdc++.h>
using namespace std;



//room 1 | 2 | 3 | 4
//  door 1   2   3
int get_the_left_door(vector<int> & doors, vector<bool> & opened, int cur_room){
    int i = cur_room -1;
    for(; i >= 0;i--){
        if(opened[i]) continue;
        else break;
    }
    // i == 0; 左边已经无门了
    return i;
}

int get_the_right_door(vector<int> & doors, vector<bool> & opened, int cur_room){
    int i = cur_room;
    for( ; i < doors.size();i++){
        if(opened[i]) continue;
        else break;
    }
    // i == door.size(); 右边已经无门了
    return i;
}

// http://www.cplusplus.com/reference/deque/deque/erase/

// 双端队列模拟? 貌似只需要双指针

// 第一个test set AC; 第二个test set TLE
// int count(vector<int> & doors, int s, int k){    
//     vector<int> room_order;
//     room_order.push_back(s);
//     if(k == 1) return s;

//     // vector<bool> opened;
//     int left,right;
//     left = s-1;
//     right = s;
//     while(left >= 1 && right < doors.size()){ // doors padding 过
//         if(doors[left] < doors[right]){
//             // go left
//             room_order.push_back(left);
//             left--;
//             if(room_order.size() == k){
//                 return room_order.back();
//             }
//         }
//         else{
//             // go right
//             room_order.push_back(right+1);
//             right++;
//             if(room_order.size() == k){
//                 return room_order.back();
//             }
//         }
//     }
//     while(left >= 1){
//         room_order.push_back(left);
//         left--;
//         if(room_order.size() == k){
//             return room_order.back();
//         }
//     }
//     while(right < doors.size()){
//         room_order.push_back(right+1);
//         right++;
//         if(room_order.size() == k){
//             return room_order.back();
//         }
//     }
// }

// 优化
// 结果没变
// 第一个test set AC; 第二个test set TLE
int count(vector<int> & doors, int s, int k){    
    if(k == 1) return s;

    int left,right;
    left = s-1;
    right = s;
    while(left >= 1 && right < doors.size()){ // doors padding 过
        if(doors[left] < doors[right]){
            // go left
            left--;
            k--;
            if(k == 1){
                return left+1;
            }
        }
        else{
            // go right
            right++;
            k--;
            if(k == 1){
                return right;
            }
        }
    }
    while(left >= 1){
        left--;
        k--;
        if(k == 1){
            return left+1;
        }
    }
    while(right < doors.size()){
        right++;
        k--;
        if(k == 1){
            return right;
        }
    }
}




int main(){
    int case_num = 0;
    cin>>case_num;
    vector<int> nums;
    for(int i = 1;i<=case_num;i++){
        int n,tmp;
        cin>>n;
        int query_num;
        cin>>query_num;

        nums.clear();
        n--;
        nums.push_back(0); // padding
        while(n--){
            cin>>tmp;
            nums.push_back(tmp);
        }
        cout<<"Case #"<<i<<": ";
        for(int j = 1;j<=query_num;j++){
            int s,k;
            cin>>s>>k;
            int ret = count(nums,s,k);
            if(j != 1) cout<<" ";
            cout<<ret;
        }
        cout<<endl;
    }
}