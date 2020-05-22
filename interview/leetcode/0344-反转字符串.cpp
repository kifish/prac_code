class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0,j = s.size()-1;
        while(i < j){
            char tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            i++;
            j--;
        }
    }
};