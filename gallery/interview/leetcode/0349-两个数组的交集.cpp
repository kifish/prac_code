class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u;
        for(int num:nums1) u.insert(num);
        vector<int> res;
        for(int num:nums2){
            if(u.find(num) != u.end()){
                res.push_back(num);
                u.erase(num);
            }
        }
        return res;
    }
};