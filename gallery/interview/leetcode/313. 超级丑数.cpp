class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> current_ugly_numbers;
        if(n == 0) return -1;
        int i = 0;
        current_ugly_numbers.push(1);
        int current_min_ugly_number;
        while(i < n){
            i++;
            current_min_ugly_number = current_ugly_numbers.top();
            current_ugly_numbers.pop();
            for(auto prime : primes){
                if(prime <= INT_MAX / current_min_ugly_number) current_ugly_numbers.push(prime * current_min_ugly_number);
                if(current_min_ugly_number % prime == 0) break; // 防止重复的丑数进入队列
            }
        }
        return current_min_ugly_number;
    }
};


// https://leetcode-cn.com/problems/super-ugly-number/solution/dong-tai-gui-hua-he-you-xian-dui-lie-liang-chong-j/

// 这个解法非常巧妙

// 联系 263. 丑数 和 264. 丑数 II

// https://leetcode-cn.com/problems/ugly-number/solution/java-zhi-xing-yong-shi-1-ms-zai-suo-you-java-ti-6/

// https://leetcode-cn.com/problems/ugly-number/solution/cyu-yan-di-gui-pan-duan-chou-shu-chou-shu-zhi-yin-/

// https://leetcode-cn.com/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode/
