http://algorithm.openjudge.cn/algorithmd/F/


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

#define N (400+2)
#define M (N*N+4*N)

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
    int pig[M+1], pre[M+1];
    bool con[N+1];
    FILE *fin;
    fin = stdin;
    int n_cows,n_food,n_drink;
    fscanf(fin, "%d %d %d", &n_cows, &n_food,&n_drink);
    s = 0;
    t = 401;
    dinic_init();
    for(int i = 1;i<=n_food;i++){
        int from = s;
        int to = i;
        add_edge(from,to,1,0);
    }
    for(int i = 1;i<=n_drink;i++){
        int from = i + 300;
        int to = t;
        add_edge(from,to,1,0);
    }
    for(int i = 1;i<=n_cows;i++){
        int from = i + 100;
        int to = i + 200;
        add_edge(from,to,1,0);
    }

    for (int i = 1;i<=n_cows;i++){
        int n_drink_like;
        int n_food_like;
        fscanf(fin,"%d %d",&n_food_like,&n_drink_like);
        while (n_food_like--){
            int from,to;
            to = i + 100;
            fscanf(fin, "%d", &from);
            add_edge(from,to,1,0);
        }
        while (n_drink_like--){
            int from,to;
            from = 200 + i;
            fscanf(fin, "%d", &to);
            to += 300;
            add_edge(from,to,1,0);
        }
    }
    int flow = dinic(s, t);
    printf("%d\n", flow);
    return 0;
}

```


