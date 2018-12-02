模板

```c
const int MAXV = 505;
struct Node{
    int w;//edge_weight
    int v;//node_id;node_weight可另外用数组存
};

vector<Node> adj[MAXV];
int weight[MAXV];//node_weight
const int INF = 0x3fffffff;


int d[MAXV];//min_dis
int num[MAXV] = {0};//顶点的入队次数
int n;
bool inq[MAXV] = {false};
bool spfa(int s){
    //init
    fill(d,d+n,INF);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    inq[s] = 1;
    num[s]++;
    //iteration
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = 0;
        for(int j = 0;j<adj[u].size();j++){
            int v = adj[u][j].v;
            int edge = adj[u][j].w;
            if(d[u] + edge < d[v]){
                d[v] = d[u] + edge;
                if(!inq[v]){
                    Q.push(v);
                    num[v]++;
                    inq[v] = 1;
                    if(num[v] >= n) return false;//有从源点可达的负环
                }
            }
        }
    }
    return true;//无从源点可达的负环
}
```


