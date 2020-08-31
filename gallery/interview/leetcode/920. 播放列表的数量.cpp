/*

https://leetcode-cn.com/problems/number-of-music-playlists/solution/bo-fang-lie-biao-de-shu-liang-by-leetcode/

数学题

https://leetcode-cn.com/problems/number-of-music-playlists/solution/bo-fang-lie-biao-de-shu-liang-by-leetcode/

官方题解的解法1里有个typo

考虑 dp[i][j]。最后一首歌，我们可以播放没有播放过的歌也可以是播放过的。如果未播放过的，那么就是 dp[i-1][j-1] * (N-j) 种选择方法。应该是  dp[i-1][j-1] * (N- j + 1)

令 dp[i][j] 为播放列表长度为 i 包含恰好 j 首不同歌曲的数量。我们需要计算 dp[L][N], 看上去可以通过 dp 来解决。


*/

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {

    }
};