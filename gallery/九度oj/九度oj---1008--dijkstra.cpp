#include<cstdio>
#include<vector>
using namespace std; 
struct E{
    int next;
    int w;
    int c;
};

vector<E> edge[1005];
bool mark[1005];
int dis[1005];
int cost[1005];
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) edge[i].clear();
        while(m--){
            int a,b,d,p;
            scanf("%d %d %d %d",&a,&b,&d,&p);
            E tmp;
            tmp.next=b;
            tmp.w=d;
            tmp.c=p;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        int s,t;
        scanf("%d %d",&s,&t);
        for(int i=1;i<=n;i++){
            mark[i]=0;
            dis[i]=-1;
            cost[i]=0;
        }
        int newP=s;
        mark[s]=1;
        dis[s]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<edge[newP].size();j++){
                int t=edge[newP][j].next;
                int w=edge[newP][j].w;
                int c=edge[newP][j].c;
                if(mark[t]==1) continue;
                if(dis[t]==-1||dis[t]>dis[newP]+w||dis[t]==dis[newP]+w&&cost[t]>cost[newP]+c){
                    dis[t]=dis[newP]+w;
                    cost[t]=cost[newP]+c;
                }
            }
            int min=123123123;
            for(int i=1;i<=n;i++){
                if(mark[i]==1) continue;
                if(dis[i]==-1) continue;
                if(min>dis[i]){
                    min=dis[i];
                    newP=i;
                }
            }
            mark[newP]=1;
        }
        printf("%d %d\n",dis[t],cost[t]);
    }
    return 0;
}
