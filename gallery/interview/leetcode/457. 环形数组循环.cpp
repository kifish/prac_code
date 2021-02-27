/*

https://leetcode-cn.com/problems/circular-array-loop/

You are given a circular array nums of positive and negative integers where you should:

Move nums[i] steps forward if nums[i] is positive, and
Move nums[i] steps backward if nums[i] is negative.
Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Return true if there is a loop (or a cycle) in nums, and false otherwise.

A cycle must start and end at the same index, and the cycle's length is greater than 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circular-array-loop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



快慢指针判环, 链表起始位置可以是数组里的任何一个位置

https://leetcode-cn.com/problems/circular-array-loop/solution/c-xun-huan-wen-ti-jiu-yong-kuai-man-zhi-zhen-by-fu/



*/