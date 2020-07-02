
/*

交互式题目

4分的方法相当于切4块

https://leetcode-cn.com/problems/number-of-ships-in-a-rectangle/solution/ju-xing-nei-chuan-zhi-de-shu-mu-by-leetcode-soluti/

如果小区域 A 递归的结果为 0，那么我们断定对小区域 B 调用 API 一定会返回 True，省去一次 API 的调用；
二分相当于切2块, 竖着切成2块


*/

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        
    }
};