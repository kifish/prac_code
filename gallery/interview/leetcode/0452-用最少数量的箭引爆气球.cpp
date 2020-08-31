bool cmp(vector<int> &a, vector<int> &b) //要写在class外面
{
    return a[0] < b[0];
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int left, right;
        left = points[0][0];
        right = points[0][1];
        int cnt = 1;
        for (int i = 1; i < points.size(); i++)
        {
            //经过排序后 points[i][0] >= left
            if (points[i][0] >= left && points[i][0] <= right)
            {
                left = points[i][0];
                right = min(right, points[i][1]);
            }
            else{
                cnt++;
                left = points[i][0];
                right = points[i][1];
            }
        }
        return cnt;
    }
}
;