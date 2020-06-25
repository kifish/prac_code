class Solution {
public:
	/* �����İ汾��
    int singleNumber(vector<int>& nums) {
        unsigned int mask = 1;
		unsigned int bits;
		int the_bit_cnt;
		iter_cnt = sizeof(int) * 8;//32��
		unsigned int res = 0;
		while (iter_cnt--)
		{	the_bit_cnt = 0;
			for(auto num : nums){
				bits = (unsigned int) num; //���Ǹ���
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
		int global_bits_one = 0; //global_bits_first�ĵ�iλΪ1������Ŀǰ(������%3��0)��iλ��1������1�Σ�
		int global_bits_two = 0; //global_bits_twice�ĵ�iλΪ1������Ŀǰ(������%3��0)��iλ��1������2�Σ�
		int global_bits_three = 0;
		for(auto num : nums){ // ģ��ĳ�����ֳ��������Σ�˼��������ѭ����������⣻���ҿ�����Ϊ�ظ������ֿ����������֣���Ϊ���µ���������������ɣ����Ե���nums��˳��
			global_bits_two |= num & global_bits_one;
			global_bits_one ^= num;
			global_bits_three = global_bits_one & global_bits_two;
			global_bits_one &= ~global_bits_three;
			global_bits_two &= ~global_bits_three;
		}
		return global_bits_one;
	}
};