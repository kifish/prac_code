http://algorithm.openjudge.cn/exfinalsim/8/

http://www.hankcs.com/program/algorithm/poj-2987-firing.html

https://www.cnblogs.com/luyouqi233/p/7942879.html

https://blog.csdn.net/zhao5502169/article/details/81669854


profit 和 loss统一表示为profit，profit < 0 即表示损失。

可见google docs
https://drive.google.com/open?id=1lP7C9bb4cCW-vagufLATYDxxzl4h2hDlje02cxVSODY



AC


```c
/*
 * Dinic algo for max flow
 *
 * This implementation assumes that #nodes, #edges, and capacity on each edge <= INT_MAX,
 * which means INT_MAX is the best approximation of INF on edge capacity.
 * The total amount of max flow computed can be up to LLONG_MAX (not defined in this file),
 * but each 'dfs' call in 'dinic' can return <= INT_MAX flow value.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>

#define N (5000+2)
#define M (N*N+4*N)

const int INF = 0x3fffffff;
typedef long long LL;

using namespace std;

struct edge {
    int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

/*
 * When there are multiple test sets, you need to re-initialize before each
 */
void dinic_init(void) {
    num_of_edges = 0;
    memset(head, -1, sizeof(head));
    return;
}

int add_edge(int u, int v, int c1, int c2) {
    int& i=num_of_edges;

    assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
    e[i].v = v;
    e[i].cap = c1;
    e[i].next = head[u];
    head[u] = i++;

    e[i].v = u;
    e[i].cap = c2;
    e[i].next = head[v];
    head[v] = i++;
    return i;
}

void print_graph(int n) {
    for (int u=0; u<n; u++) {
        printf("%d: ", u);
        for (int i=head[u]; i>=0; i=e[i].next) {
            printf("%d(%d)", e[i].v, e[i].cap);
        }
        printf("\n");
    }
    return;
}

/*
 * Find all augmentation paths in the current level graph
 * This is the recursive version
 */
int dfs(int u, int t, int bn) {
    if (u == t) return bn;
    int left = bn;
    for (int &i=cur[u]; i>=0; i=e[i].next) {
        int v = e[i].v;
        int c = e[i].cap;
        if (c > 0 && level[u]+1 == level[v]) {
            int flow = dfs(v, t, min(left, c));
            if (flow > 0) {
                e[i].cap -= flow;
                e[i^1].cap += flow;
                cur[u] = i;
                left -= flow;
                if (!left) break;
            }
        }
    }
    if (left > 0) level[u] = 0;
    return bn - left;
}

bool bfs(int s, int t) {
    memset(level, 0, sizeof(level));
    level[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) return true;
        for (int i=head[u]; i>=0; i=e[i].next) {
            int v = e[i].v;
            if (!level[v] && e[i].cap > 0) {
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
    return false;
}

LL dinic(int s, int t) {
    LL max_flow = 0;

    while (bfs(s, t)) {
        memcpy(cur, head, sizeof(head));
        max_flow += dfs(s, t, INT_MAX);
    }
    return max_flow;
}

int upstream(int s, int n) {
    int cnt = 0;
    vector<bool> visited(n);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i=head[u]; i>=0; i=e[i].next) {
            int v = e[i].v;
            if (e[i].cap > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
                cnt++;
            }
        }
    }
    return cnt; // excluding s
}

int main() {
    int m, n, s, t;
    FILE *fin;

    /*fin = fopen("pigs.dat", "r");
    assert(fin);*/
    fin = stdin;
    int person_n;
    fscanf(fin, "%d %d", &person_n, &m);
    n = person_n + 2;
    LL positive_sum = 0;
    dinic_init();
    s = 0, t = person_n+1;
    for(int i = 1;i<=person_n;i++){
        int profit;
        fscanf(fin, "%d", &profit);
        if(profit >= 0){
            add_edge(s,i,profit,0);
            positive_sum += profit;
        }
        else
            add_edge(i,t,-1*profit,0);
    }
    for(int i = 1;i<=m;i++){
        int u,v;
        fscanf(fin, "%d %d", &u, &v);
        add_edge(u,v,INF,0);
    }
    //print_graph(n+2);
    LL flow = dinic(s, t);
    int cnt = upstream(0,n);
    printf("%d ", cnt);
    printf("%lld\n", positive_sum - flow);
    return 0;
}
```