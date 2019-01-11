http://algorithm.openjudge.cn/algorithmd/D/


最大匹配。

```C
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
    /*fin = fopen("pigs.dat", "r");
    assert(fin);*/
    fin = stdin;
    int cow_n,stall_n;
    while(fscanf(fin, "%d %d", &cow_n, &stall_n) == 2){
        n = cow_n + stall_n;
        dinic_init();
        s = 0, t = n+1;
        for(int to = 1;to <= cow_n;to++){
            int from = s;
            add_edge(from,to,1,0);
        }
        for(int from = cow_n + 1;from <= n;from++){
            int to = t;
            add_edge(from,to,1,0);
        }
        for(int i = 1;i<=cow_n;i++){
            int times;
            fscanf(fin,"%d",&times);
            int from = i;
            while (times--){
                int to;
                fscanf(fin,"%d",&to);
                to += cow_n;//偏移量
                add_edge(from,to,1,0);
            }
        }
    //    print_graph(n+2);
        int flow = dinic(s, t);
        printf("%d\n", flow);
    }
    return 0;
}

```

直接用最大匹配的模板也是可以的。
速度基本一样。

```C
/*
 * hungarian algo for maximum_matching
 */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > lnklst;
vector<int> l, r;
vector<bool> visited;

/* make all vectors one element bigger in case the index starts from 1 instead of 0 */
void init(int n1, int n2) {
    lnklst.clear(); lnklst.resize(n1+1);
    l.clear(); l.resize(n1+1,-1);
    r.clear(); r.resize(n2+1,-1);
    return;
}

void add_edge(int u, int v) {
    lnklst[u].push_back(v);
    return;
}

bool dfs(int u) {
    for (int i=0; i<lnklst[u].size(); i++) {
        int v = lnklst[u][i];
        if (visited[v]) continue;
        visited[v] = true;
        if (r[v] < 0 || dfs(r[v])) {
            l[u] = v;
            r[v] = u;
            return true;
        }
    }
    return false;
}

int greedy_match(int n1) {
    int match = 0;
    for (int u=0; u<n1; u++) {
        if (l[u] < 0) {
            for (int i=0; i<lnklst[u].size(); i++) {
                int v = lnklst[u][i];
                if (r[v] < 0) {
                    l[u] = v;
                    r[v] = u;
                    match++;
                    break;
                }
            }
        }
    }
    return match;
}

int hungarian(void) {
    int n1 = l.size();
    int n2 = r.size();
    int match = greedy_match(n1);
    for (int u=0; u<n1; u++) {
        if (l[u] < 0) {
            visited.clear();
            visited.resize(n2);
            if (dfs(u)) {
                match++;
            }
        }
    }
    return match;
}


int main() {
    //freopen("path_cover.dat", "r", stdin);
    int n, m;
    int cow_n,stall_n;
    while (cin >> cow_n >> stall_n) {
        n = cow_n + stall_n;
        init(n, n);
        for (int i=1; i<=cow_n; i++) {
            int u, v;
            u = i;
            int times;
            cin>>times;
            while(times--){
                cin>>v;
                v += cow_n;
                add_edge(u, v);
            }
        }
        int max_match = hungarian();
        cout << max_match << endl;
    }
    return 0;
}

```