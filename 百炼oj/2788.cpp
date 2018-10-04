#include <iostream>
#include <cmath>
using namespace std;
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int m, n;
    int depth;
    int max;
    int sum;
    int last;
    int multiplier;
    while (cin >> m >> n && m + n != 0)
    {
        depth = (int)log2(n) - (int)log2(m);
        multiplier = (int)pow(2, depth);
        max = multiplier * m; //叶子节点层的最左边
        sum = multiplier - 1;
        last = min(n, max + multiplier - 1); //可能m，n代表的节点不在某个层次的同一颗子树上,例如5 13
        if (max <= last)                     // 可能m，n代表的节点不在某个层次的同一颗子树上
            sum += last - max + 1;
        cout << sum << endl;
    }
    return 0;
}