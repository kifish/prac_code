// https://zh.wikipedia.org/wiki/ASCII
class Solution {
public:
    //测试例子:
    // 330 33
    // 33330

    // 6
    // 730


    // 321
    // 32
    // 32 321

    // 324
    // 32
    // 324 32

    // 32 324

    //wrong: -1应该改成0. 因为返回值是bool,-1会转换成true
    // static bool cmp(string &a,string &b){
    //     int min_len = min(a.size(),b.size());
    //     for(int i = 0;i < min_len;++i){
    //         if(a[i] < b[i]){
    //             return -1;//该种定义下a排在b的右边
    //         }
    //         else if(a[i] > b[i]){
    //             return 1;
    //         }
    //     }
    //     if(a.size() < b.size()){
    //         if(b[b.size() -1] > a[0]){
    //             return -1;//ba
    //         }
    //         else return 1;//ab
    //     }
    //     else{
    //         if(a[a.size() -1] > b[0]){
    //             return 1; //ab
    //         }
    //         else return -1;
    //     }
    // }
    //错误的印象导致的，以前可能写过int cmp(){}

    // fix了上述bug, 220/222 还有2个bug case
    // static bool cmp(string &a,string &b){
    //     int min_len = min(a.size(),b.size());
    //     for(int i = 0;i < min_len;++i){
    //         if(a[i] < b[i]){
    //             return 0;//该种定义下a排在b的右边:ba
    //         }
    //         else if(a[i] > b[i]){
    //             return 1;//该种定义下a排在b的左边:ab
    //         }
    //     }
    //     // cout<<"here"<<endl;
    //     if(a.size() < b.size()){
    //         // cout<<"here1"<<endl;
    //         if(b[b.size() -1] > a[0]){
    //             // cout<<"here2"<<endl;
    //             return 0;//ba
    //         }
    //         else return 1;//ab
    //     }
    //     else{
    //         // cout<<"here3"<<endl;
    //         // cout << "a:"<<a<<endl;
    //         // cout << "b:"<<b<<endl;
    //         if(a[a.size() -1] > b[0]){
    //             // cout<<"here4"<<endl;
    //             return 1;//ab
    //         }
    //         else{
    //             // cout<<"here5"<<endl;
    //             return 0;//ba
    //         } 
    //     }
    // }

    static bool cmp(string &a,string &b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for(auto num : nums){
            nums_str.push_back(to_string(num));
        }
        sort(nums_str.begin(),nums_str.end(),cmp);
        string ret = "";
        for(auto &s : nums_str){
            // cout<<s<<endl;
            ret += s;
        }
        int zero_cnt = 0;
        for(auto c : ret){
            if(c == '0'){
                zero_cnt++;
            }
        }
        if(zero_cnt == ret.size()){
            return "0";
        }
        else return ret;
    }
};