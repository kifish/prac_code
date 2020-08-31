class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> bits1 = tran_bits(x);
        vector<int> bits2 = tran_bits(y);
        int ret = 0;
        for(int i = 0;i<bits1.size();i++){
            if(bits1[i] != bits2[i]){
                ret++;
            }
        }
        return ret;
    }

    vector<int> tran_bits(int num){
        vector<int> ret(31,0);
        vector<int> bits;
        while(num){
            int last_bit = num % 2;
            bits.push_back(last_bit);
            num /= 2;
        }
        for(int i = 0 ;i<bits.size();i++){
            ret[30-i] = bits[i];
        }
        return ret;
    }
};