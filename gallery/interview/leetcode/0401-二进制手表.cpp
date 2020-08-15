class Solution
{   
    vector<string> res;
public:
    void dfs(int left_cnt, int idx, vector<int> &time)
    {
        if (left_cnt == 0)
        {
            int hour = time[0] * 8 + time[1] * 4 + time[2] * 2 + time[3];
            int minute = time[4] * 32 + time[5] * 16 + time[6] * 8 + time[7] * 4 + time[8] * 2 + time[9];
            if(hour>=12 || minute>=60) return;
            string s = "";
            s += to_string(hour);
            s += ":";
            if (minute < 10)
            {
                s += "0";
                s += to_string(minute);
            }
            else
                s += to_string(minute);
            res.push_back(s);
            return;
        }
        if (idx == time.size())
            return;

        time[idx]++;
        dfs(left_cnt - 1, idx + 1, time);
        time[idx]--;
        dfs(left_cnt, idx + 1, time);
    }
    vector<string> readBinaryWatch(int num)
    {   
        vector<int> time(10,0);
        dfs(num,0,time);
        return res;
    }
};