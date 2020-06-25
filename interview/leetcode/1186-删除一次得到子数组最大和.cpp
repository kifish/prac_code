class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        vector<int> dp_from_left(arr.size(),0);
        vector<int> dp_from_right(arr.size(),0);
        for(int i =0;i<arr.size();i++){
            dp_from_left[i] = arr[i];
            dp_from_right[i] = arr[i];
        }
        for(int i = 1;i<arr.size();i++){
            dp_from_left[i] = max(dp_from_left[i], dp_from_left[i - 1] + arr[i]);
        }
        for (int i = (int)arr.size()-2; i > 0; i--)
        {
            dp_from_right[i] = max(dp_from_right[i], dp_from_right[i + 1] + arr[i]);
        }
        int max_sum = max(dp_from_left[0],dp_from_right[arr.size()-1]);
        for(int i=1;i<arr.size()-1;i++){
            max_sum = max(max_sum,dp_from_left[i-1] + dp_from_right[i+1]);
        }
        for(int i=1;i<arr.size();i++){
            max_sum = max(max_sum,dp_from_left[i]);
        }
        return max_sum;
    }
};