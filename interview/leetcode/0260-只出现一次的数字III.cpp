class Solution
{
public:
	vector<int> singleNumber(vector<int> &nums)
	{
		int bits = 0;//a ^ b
		for(auto num : nums){
			bits ^= num;
		}
		int num1_bits = 0;
		int num2_bits = 0;
        int mask = 1;
        while((mask & bits) == 0){ //括号是必须的
            mask <<= 1;
        }
		for(auto num : nums){
			if((num & mask) > 0){ //括号是必须的
                num1_bits ^= num;
            }
				
			else{
                num2_bits ^= num;
            } 
		}
		return vector<int>{num1_bits,num2_bits};
	}
};