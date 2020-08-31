class Solution
{
public:
    vector<string> res;
    void dfs(string &s, vector<char> &cur, int idx)
    {
        if (idx == s.size())
        {
            string res_s = "";
            for (char ch : cur)
                res_s += ch;
            res.push_back(res_s);
            return;
        }
        if (isalpha(s[idx]))
        {
            if ('a' <= s[idx] && s[idx] <= 'z')
            {
                cur.push_back(s[idx] - 'a' + 'A');
                dfs(s, cur, idx + 1);
                cur.pop_back();

                cur.push_back(s[idx]);
                dfs(s, cur, idx + 1);
                cur.pop_back();
            }
            else
            {
                cur.push_back(s[idx] - 'A' + 'a');
                dfs(s, cur, idx + 1);
                cur.pop_back();

                cur.push_back(s[idx]);
                dfs(s, cur, idx + 1);
                cur.pop_back();
            }
        }
        else
        {
            cur.push_back(s[idx]);
            dfs(s, cur, idx + 1);
            cur.pop_back();
        }
    }

    vector<string> letterCasePermutation(string S)
    {
        vector<char> cur;
        dfs(S, cur, 0);
        return res;
    }
};