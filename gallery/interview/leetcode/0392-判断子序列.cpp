class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if(s.size() == 0) return true;
        int idx1 = 0;
        for(int idx2 = 0;idx2 < t.size();idx2++){
            if(t[idx2] == s[idx1]){
                idx1++;
            }
            if(idx1 == s.size()) return true;
        }
        return false;
    }
};