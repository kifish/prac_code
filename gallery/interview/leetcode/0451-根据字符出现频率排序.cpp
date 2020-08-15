class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char,int> counter;
        for(char ch : s){
            counter[ch]++;
        }
        multimap<int,char> m;
        for(auto it = counter.begin();it != counter.end();it++){
            m.insert({it->second,it->first}); //按词频从小到大排序
        }
        string res(s);
        int i = 0;
        for(auto it = m.rbegin();it != m.rend() && i < s.size();it++){
            int tmp = it->first;
            while(tmp--){
                res[i] = it->second;
                i++;
            }
        }
        return res;
    }
};