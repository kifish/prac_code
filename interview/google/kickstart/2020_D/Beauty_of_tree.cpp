#include<bits/stdc++.h>
using namespace std;

int count(vector<int> & nums){
    if(nums.size() == 0){
        return 0;
    }

    int i = 0;
    int pre;
    while (i<nums.size())
    {
        
    }
    

}



int main(){
    int case_num = 0;
    cin>>case_num;
    vector<int> nums;
    for(int i = 1;i<=case_num;i++){
        int n,tmp;
        cin>>n;
        nums.clear();
        while(n--){
            cin>>tmp;
            nums.push_back(tmp);
        }
        int ret = count(nums);
        cout<<"Case #"<<i<<": "<<ret<<endl;
    }
}