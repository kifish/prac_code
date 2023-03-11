#include<bits/stdc++.h>

using namespace std;


vector<int> nums;
vector<int> path;

int total_path_cnt = 0;


void print_vector(vector<int> & path){
    for(auto num : path){
        cout<<num<<" ";
    }
    cout<<endl;
}


// 这不是全排列而是组合
void dfs(int idx, vector<int> & nums, vector<int> & path){
    if(path.size() == nums.size()){
        total_path_cnt++;
        print_vector(path);
        return;
    }

    if(idx == -1 or idx == nums.size()){
        return;
    }

    // select
    path.push_back(nums[idx]);
    dfs(idx, nums, path);
    path.pop_back();
    // do not select
    dfs(idx+1, nums, path);
    // dfs(idx-1, nums, path);

}


// 可重复使用的全排列
void dfs_v2(vector<int> nums, vector<int> & path){

    if(nums.size() == path.size()){
        total_path_cnt++;
        print_vector(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        path.push_back(nums[i]);
        dfs_v2(nums, path);
        path.pop_back();
    }

}




void permutation_v2(){
    dfs_v2(nums, path);
}



// 带限制条件的可重复使用的全排列
void dfs_v3(vector<int> nums, vector<int> & path){

    if(nums.size() == path.size()){
        total_path_cnt++;
        print_vector(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 2 && path.size() && path.back() == 2){
            continue;
        }

        path.push_back(nums[i]);
        dfs_v3(nums, path);
        path.pop_back();
    }

}




void permutation_v3(){
    dfs_v3(nums, path);
}




int main(){
    // nums = {1,2,3,5};
    int n;
    int x;
    cin>>n;
    
    while (n--){   
        cin>>x;
        nums.push_back(x);
    }

    // print_vector(nums);

    cout<<"output:"<<endl;
    // dfs(0, nums, path);

    // permutation_v2();
    // n^n

    permutation_v3();
    

    cout<<"total_path_cnt: "<<total_path_cnt<<endl;
    return 0;
}

// g++ main.cpp -o buf
// ./buf
// 4
// 1 2 3 5

