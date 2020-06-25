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