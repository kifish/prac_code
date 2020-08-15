class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0,i = 0;
        while(j <s.size() && i < g.size()){
            if(s[j] >= g[i]){
                cnt++;
                j++;
                i++;
            }
            else j++;
        }
        return cnt;
    }
};