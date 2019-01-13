#include <cstdio>
#include <queue>
using namespace std;
struct X
{
    int v, q, j, n, f;
    bool operator<(const X &a) const
    {
        if (q == a.q)
            return j > a.j;
        return q > a.q;
    } //重载运算符
} x[10005];
priority_queue<X> qq; //调用系统堆
int main()
{
    int k, n, m;
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u;
        scanf("%d%d%d%d", &u, &x[i].v, &x[i].q, &x[i].j);
        x[i].n = x[u].f;
        x[u].f = i;
    }
    qq.push((X){1, 0, 0, 0, 0}); //载入初始节点
    while (!qq.empty())
    {
        X t = qq.top();
        qq.pop();
        if (t.v == n)
        {
            printf("%d", t.q); //到达n即为最优解
            return 0;
        }
        for (int i = x[t.v].f; i; i = x[i].n)
            if (t.j + x[i].j <= k)
                qq.push((X){x[i].v, x[i].q + t.q, x[i].j + t.j, 0, 0});
    }
    printf("-1");
    return 0;
}