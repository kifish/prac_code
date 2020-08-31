class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        map<pair<int,int>,int> M;
        for(auto &v: dominoes){
            if(v[0] > v[1]){
                swap(v[0],v[1]);
            }
            ++M[make_pair(v[0],v[1])];
        }
        for(auto &item : M){
            if(item.second > 1){
                res += item.second * (item.second-1) / 2;
            }
        }
        return res;
    }
};