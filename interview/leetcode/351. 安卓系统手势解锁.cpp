

// 执行用时 :
// 212 ms
// , 在所有 C++ 提交中击败了
// 26.81%
// 的用户
// 内存消耗 :
// 6.2 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

/*

注意这道题的题意，如果是最长对角线, 那么肯定要考虑 最中心的点(1,1)

问题是从9 (2,2) 划到 2 (0,1) 是否需要(1,1) 和 (1,2) 都已经经过？
从结果来看似乎只需要(1,1) 经过即可。

// 如果是需要需要(1,1) 和 (1,2) 都已经经过 
// 那么判断起来就比较复杂了, 可能得枚举。 （这样实现起来比较琐碎）


// 实际使用的时候, 解锁的都是点, 而不是邻接的方块。

// 实际上从从9 (2,2) 划到 2 (0,1) , 对于 (1,1) (1,2) 都不需要考虑是否已经经过


// 即使此题不需要考虑 (1,2), 也有人做了枚举

// https://leetcode-cn.com/problems/android-unlock-patterns/solution/dai-zhuang-tai-de-shen-du-you-xian-by-amchor/

*/

class Solution {
public:
    int cnt = 0;
    vector<vector<bool>> was_used = vector<vector<bool>> (3, vector<bool> (3, false));

    int abs(int x){
        if(x >= 0){
            return x;
        }
        else{
            return -1 * x;
        }
    }

    // 这么写太复杂了
    // bool is_valid(int new_x, int new_y, int x, int y){
    //     if(was_used[new_x][new_y]){
    //         return false;
    //     }

    //     // 因此new_x != x && new_y != y

    //     if(!(new_x == x || new_y == y || abs(new_x - x) == abs(new_y - y) || abs(new_x - x) == 3 * abs(new_y - y) || 3 * abs(new_x - x) == abs(new_y - y) )){
    //         return false;
    //     }

    //     // 水平或垂直或斜45度或2倍关系

    //     if(new_x == x){
    //         if(!was_used[(new_x + x) / 2][new_y]){
    //             return false;
    //         }
    //         else return true;
    //     }
    //     else if(new_y == y){
    //         if(!was_used[x][(new_y + y) / 2]){
    //             return false;
    //         }
    //         else return true;
    //     }
    //     else if(abs(new_x - x) == abs(new_y - y)){
    //         if(!was_used[(new_x + x) / 2][(new_y + y) / 2]){
    //             return false;
    //         }
    //         else return true;
    //     }
    //     else{
    //         if(abs(new_x - x) == 3 * abs(new_y - y)){
    //             if(!was_used[1][1]){
    //                 return false;
    //             }
                
    //             // 剩下一个点肯定在边界上
    //             if((x == 0 && new_x == 1) || (new_x == 0 && x == 1)){
    //                 return was_used[0][1];
    //             }
    //             else if( x == 2 || new_x == 2){
    //                 return 
    //             }
    //             if(!was_used[])


    //         }
    //         else{
    //             if(!was_used[1][1]){
    //                 return false;
    //             }


    //         }
    //     }

    // }



    bool is_valid(int new_x, int new_y, int x, int y){
        if(was_used[new_x][new_y]){
            return false;
        }

        // 因此new_x != x && new_y != y

        if(abs(new_x - x) % 2 == 0 && abs(new_y - y) % 2 == 0 && !was_used[(new_x + x) / 2][(new_y + y) / 2]){
            return false;
        }

        return true;

    }



    void dfs(int x, int y, int step, int m, int n){

        if(m <= step && step <= n){
            cnt++;
        }

        if(step == n){
            return;
        }

        // 每次考虑所有的9个点
        for(int i = 0;i<3;i++){
            for(int j = 0;j < 3;j++){
                int new_x = i;
                int new_y = j;
                if(is_valid(new_x,new_y, x,y)){
                    was_used[new_x][new_y] = true;
                    dfs(new_x,new_y,step+1,m,n);
                    was_used[new_x][new_y] = false;
                }
            }
        }
    }


    void dfs_search(int m, int n){
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                was_used[i][j] = true;
                dfs(i,j,1,m,n);
                was_used[i][j] = false;
            }
        }
    }

    // 可以利用对称的性质只求从1,2,5开始的手势数可以稍微快一些。

    int numberOfPatterns(int m, int n) {
        dfs_search(m, n);
        return cnt;
    }
};