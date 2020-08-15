
// AC
// class Solution {
// public:

//     int binary_search_left(vector<int>& nums,int target){
//         int lo = -1;
//         int hi = (int)nums.size() -1;
//         if(lo > hi) return -1;
//         while (lo + 1< hi)
//         {
//             int mid = (lo + hi) / 2;
//             if(nums[mid] < target){
//                 lo = mid; // ѭ����������lo��ʾС��target��������������index
//             }              //��hi�Ĵ��ڵ�����ֻ��Ϊ�˰�������lo
//             else hi = mid;
//         }
//         if(lo + 1 < nums.size() && nums[lo + 1] == target)
//             return (lo + 1);
//         else return -1;
//     }

//     int binary_search_right(vector<int>& nums,int target){
//         int lo = 0;
//         int hi = (int)nums.size();
//         if(nums.size() == 0) return -1;
//         if(lo > hi) return -1;
//         while (lo < hi)
//         {
//             int mid = (lo + hi) / 2;
//             if(nums[mid] > target){
//                 hi = mid;
//             }
//             else lo = mid + 1; // ѭ����������hi��ʾ����target��������С������index
//             // ��lo�Ĵ��ڵ�����ֻ��Ϊ�˰�������hi
//         }
//         if(hi - 1 >= 0 && nums[hi - 1] == target)
//             return (hi - 1);
//         else return -1;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int ret1,ret2;
//         ret1 = binary_search_left(nums,target);
//         if(ret1 == -1){
//             return {-1,-1};
//         }
//         else{
//             ret2 = binary_search_right(nums,target);
//             return {ret1,ret2};
//         }
//     }
// };


// ����˼·���ѣ����Ƕ��ֵ�ϸ�ڻ��Ǻ��鷳�ģ���Ҫ���������ac

class Solution {
public:

    int binary_search_left(vector<int>& nums,int target){
        int lo = -1;
        int hi = (int)nums.size() -1;
        if(nums.size() == 0) return -1;
        while (lo + 1< hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] < target){ // ��Ϊ����Ҫ�����lo��ֵ����������ж��ٿ������ʹ��lo�ƽ���ȷ��ֵ
                lo = mid; // ѭ����������lo��ʾС��target��������������index
            }              //��hi�Ĵ��ڵ�����ֻ��Ϊ�˰�������lo
            else hi = mid; // ���mid -1 ���ܻ�����ȷ�Ľ�
        }
        if(lo + 1 < nums.size() && nums[lo + 1] == target)
            return (lo + 1);
        else return -1;
    }

    int binary_search_right(vector<int>& nums,int target){
        int lo = 0;
        int hi = (int)nums.size();
        if(nums.size() == 0) return -1;
        while (lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target){ // ��Ϊ����Ҫ�����hi��ֵ����������ж��ٿ������ʹ��hi�ƽ���ȷ��ֵ
                hi = mid;
            }
            else lo = mid; // ѭ����������hi��ʾ����target��������С������index
            // ��lo�Ĵ��ڵ�����ֻ��Ϊ�˰�������hi
            // ���mid -1 ���ܻ�����ȷ�Ľ�
        }
        if(hi - 1 >= 0 && nums[hi - 1] == target)
            return (hi - 1);
        else return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int ret1,ret2;
        ret1 = binary_search_left(nums,target);
        if(ret1 == -1){
            return {-1,-1};
        }
        else{
            ret2 = binary_search_right(nums,target);
            return {ret1,ret2};
        }
    }
};