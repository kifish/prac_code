//ԭʼ�汾���ٶȽ�������������˼·����������
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum / k;
        if(target * k != sum) return false;
        vector<int> sums(k,0);
        sort(nums.rbegin(),nums.rend());
        return dfs(nums,sums,target,0);
    }
    bool dfs(vector<int> &nums,vector<int>& sums,int target,int idx){
        if(idx == nums.size()){ //����߽�
            for(auto sum : sums){
                if(sum != target){
                    return false;
                }
            }
            return true;
        }
        for(int i = 0;i<sums.size();i++){
            //�������ϣ����Ǹ����Ͽ��Է��������
            //��֦
            if(sums[i] + nums[idx] > target) continue;
            sums[i] += nums[idx];
            if(dfs(nums,sums,target,idx+1)) return true;
            sums[i] -= nums[idx];
        }
        return false;
    }
};


