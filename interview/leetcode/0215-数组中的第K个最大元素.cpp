//stlд����ac
//http://c.biancheng.net/view/566.html
// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         int l = (int)nums.size() - k + 1;
//         nth_element(nums.begin(), nums.begin() + l - 1, nums.end());
//         return nums[l - 1];
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        int m = (int)nums.size() -k;
        int lo = 0,hi = (int)nums.size() -1;
        // int mid = (lo + hi) / 2;
        while(lo<=hi){
            int idx = partition(nums,lo,hi);
            if(m < idx){
                hi = idx - 1;
            }
            else if(m > idx){
                lo = idx + 1;
            }
            else{
                return nums[idx];
            }
        }
        return -1;//�������÷�֧
    }
    int partition(vector<int>& nums,int lo,int hi){
        //����
        if(lo == hi - 1){
            if(nums[lo] <= nums[hi]){
                return lo;
            }
            else{
                swap(nums[lo],nums[hi]);
                return lo;
            }
        }
        
        swap(nums[lo],nums[(lo+hi)/2]);
        int pivot = nums[lo];
        int i = lo + 1;
        int j = hi;
        while(i<=j){//������i<=j ���� i<j;���� ��[2,1,3]partition
            while(i<hi && nums[i] <= pivot) i++;
            while(j>lo && nums[j] >= pivot) j--;
            if(i < j) swap(nums[i++],nums[j--]);
            else break;
        }
        swap(nums[lo],nums[j]);//��lo = hi - 1��ʱ����ôд�����
        return j;
    }
};