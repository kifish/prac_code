#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

typedef long long LL;
// or #define LL long long

using namespace std;



// 规则是拿一个数, 这个数及之前的数都被去掉

// 去掉所有数, 游戏结束.

// 谁最后拿数, 则获得胜利


// 1 1 1 | 2 2 2

// a b a b ...
// 如果最后一个group的里个数是奇数,
// 那么a必胜

// 1 1 1 | 2 2 
// 如果最后一个group的里个数是偶数,
// a必然不能选最后一个group
// 无论a做什么选择
// b也不能选最后一个group, 因为这时候最后一个group的里个数是偶数

// a以1起手的话, a就能必胜了
// 无论b怎么做, a都会赢

// 都是理性人的情况下, 要么a必胜要么b必胜

// 如果最后一个group是偶数, a去选择最后一个group就是b必胜了

// 如果最后一个group是偶数, 那么就看倒数第二个group

// 如果倒数倒数第二个是偶数, 那就看倒数第三个

// 从后往前只要碰到有一个group是奇数, 那么a就能必胜

// 否则b必胜


void cal(vector<int> & nums){
    int pre_num = INT_MAX;
    int cur_cnt = 0;
    int idx = (int) nums.size() - 1;
    while(idx >= 0){
        if(nums[idx] != pre_num){
            if(cur_cnt % 2 == 1){
                cout<<"NIUNIU"<<endl; // a
                return;
            }
            else{
                ;
            }
            pre_num = nums[idx];
            cur_cnt = 1;
        }
        else{
            cur_cnt++;
        }

        idx--;
    }
    if(cur_cnt % 2 == 1){
        cout<<"NIUNIU"<<endl; // a
    }
    else
        cout<<"NIUMEI"<<endl; // b
    return;
}

//TODO
int main() {
	std::ios::sync_with_stdio(false);

    int T;
    cin>>T;
    vector<int> nums; 
    while (T--){   
        nums.clear();
        int n;
        cin>>n;
        while(n--){
            int tmp;
            cin>>tmp;
            nums.push_back(tmp);
        }
        cal(nums);
    }
	return 0;
}




