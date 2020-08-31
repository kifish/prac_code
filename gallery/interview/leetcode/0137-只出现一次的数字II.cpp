class Solution {
public:
	/* 易理解的版本。
    int singleNumber(vector<int>& nums) {
        unsigned int mask = 1;
		unsigned int bits;
		int the_bit_cnt;
		iter_cnt = sizeof(int) * 8;//32次
		unsigned int res = 0;
		while (iter_cnt--)
		{	the_bit_cnt = 0;
			for(auto num : nums){
				bits = (unsigned int) num; //考虑负数
				the_bit_cnt += bits & mask > 0;
			}
			if(the_bit_cnt % 3 > 0){
				res |= mask;
			}
			mask <<= 1; // for next iteration
		}
		return (int) res;
    }
	*/
	// best practice
	//x &~x = 0;
	//x &~0 = x;
	int singleNumber(vector<int>& nums) {
		int global_bits_one = 0; //global_bits_first的第i位为1，代表目前(考虑了%3归0)第i位的1出现了1次；
		int global_bits_two = 0; //global_bits_twice的第i位为1，代表目前(考虑了%3归0)第i位的1出现了2次；
		int global_bits_three = 0;
		for(auto num : nums){ // 模拟某个数字出现了三次，思考这三次循环，即可理解；并且可以认为重复的数字可以连续出现，因为以下的整体操作满足结合律，可以调整nums的顺序
			global_bits_two |= num & global_bits_one;
			global_bits_one ^= num;
			global_bits_three = global_bits_one & global_bits_two;
			global_bits_one &= ~global_bits_three;
			global_bits_two &= ~global_bits_three;
		}
		return global_bits_one;
	}
};