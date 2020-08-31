class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int cnt;
        int max;
        int second;
        int third;
        bool init1,init2,init3;
        init1 = init2 = init3 = false;
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            if(init1 == false || init2 == false || init3 == false){
                if(init1 == false){
                    max = num;
                    init1 = true;
                }
                else if(init2 == false){
                    if(max == num) continue;
                    
                    else if(max > num) second = num;
                    else{
                        second = max;
                        max = num;
                    }
                    init2 = true;
                }
                else{
                    if(num < second) {
                        third = num;
                        init3 = true;
                    }
                    else if(num > second && num < max){
                        third = second;
                        second = num;
                        init3 = true;
                    }
                    else if(num > max){
                        third = second;
                        second = max;
                        max = num;
                        init3 = true;
                    }
                }
            }
            else{
                if(num > max){
                    third = second;
                    second = max;
                    max = num;
                }
                else if(num < max && num > second){
                    third = second;
                    second = num;
                }
                else if(num < second && num > third){
                    third = num;
                } 
            }

        }
        if(init1 == true && init2 == true && init3 == true){
            return third;
        }
        else return max;
    }
};