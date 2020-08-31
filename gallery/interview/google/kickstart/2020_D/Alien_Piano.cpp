#include<bits/stdc++.h>
using namespace std;

// 贪心, 双AC

int count(vector<int> & nums){
    if(nums.size() == 0){
        return 0;
    }
    const int max_n = nums.size();
    vector<int> dp_from_left(max_n, 0);
    vector<int> dp_from_right(max_n, 0);
    dp_from_left[1] = 0;
    int ret = 0;
    for(int i = 2;i<nums.size();i++){
        if(nums[i] > nums[i-1]){
            dp_from_left[i] = dp_from_left[i-1] + 1;
            if(dp_from_left[i] == 4){ // break rules
                ret++;
                // clear
                dp_from_left[i] = 0;
            }
        }
        else if(nums[i] == nums[i-1]){
            dp_from_left[i] = dp_from_left[i-1];
        }
        else{
            dp_from_left[i] = 0;
        }
    }

    dp_from_right[nums.size() -1] = 0; // 最后一个元素
    for(int i = (int)nums.size() -2;i>=1;i--){
        if(nums[i] > nums[i+1]){
            dp_from_right[i] = dp_from_right[i+1] + 1;
            if(dp_from_right[i] == 4){
                ret++;
                // dp_from_right[i] == 0; //WA: fucking typo // 致命typo, 如果出现样例过了但WA的情况, 要仔细检查这类typo
                dp_from_right[i] = 0;
            }
        }
        else if(nums[i] == nums[i+1]){
            dp_from_right[i] = dp_from_right[i+1];
        }
        else{
            dp_from_right[i] = 0;
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