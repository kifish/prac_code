class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> M;
        stack<int> S;
        for(int v:nums1){
            M[v] = -1;
        }
        for(int num:nums2){
            while(!S.empty() && S.top() < num){
                M[S.top()] = num;
                S.pop();
            }
            
            S.push(num);
        }
        vector<int> res;
        for(int v:nums1){
            res.push_back(M[v]);
        }
        return res;
    }
};

class Solution {
    stack<int> s;
    map<int, int> num2idx;
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> buf;
        for(int i = int(nums2.size() - 1); i >= 0; i--){
            while(!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }
            if(s.empty()){
                buf.push_back(-1);
            }
            else{
                buf.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(buf.begin(), buf.end());
        for(int i = 0; i < nums2.size(); i++){
            num2idx[nums2[i]] = i;
        }
        vector<int> ret;
        for(auto num : nums1){
            ret.push_back(buf[num2idx[num]]);
        }
        return ret;
    }
};
