/*

https://leetcode-cn.com/problems/shuffle-an-array/

shuffle

https://leetcode-cn.com/problems/shuffle-an-array/solution/zhong-gui-zhong-ju-384-da-luan-shu-zu-by-1slm/

和下面的链接的第一种解法是一样的
https://leetcode-cn.com/problems/shuffle-an-array/solution/xi-pai-suan-fa-shen-du-xiang-jie-by-labuladong/

另一种等价的形式:

https://yjk94.wordpress.com/2017/03/17/%E6%B4%97%E7%89%8C%E7%9A%84%E6%AD%A3%E7%A1%AE%E5%A7%BF%E5%8A%BF-knuth-shuffle%E7%AE%97%E6%B3%95/

def shuffleSort(a):
  N = len(a)
  for i in range(N):
    j = random.randint(0, i)
    a[j], a[i] = a[i], a[j]



*/