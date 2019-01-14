http://algorithm.openjudge.cn/201804/


https://blog.csdn.net/mengxiang000000/article/details/52198924

```c
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
struct node
{
    int from;
    int to;
    int w;
    int next;
}e[1515151];
int bian[4500][2];
int divv[100*100];
int map[55][55];
int cur[100*100];
int head[100*100];
int cont,ss,tt,n,m,k;
void add(int from,int to,int w)
{
    e[cont].to=to;
    e[cont].w=w;
    e[cont].next=head[from];
    head[from]=cont++;
}
void getmap()
{
    cont=0;
    ss=1;
    tt=n*2;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
    {
        if(i==1||i==n)
        {
            add(i,i+n,0x3f3f3f3f);
            add(i+n,i,0);
            continue;
        }
        add(i,i+n,1);
        add(i+n,i,0);
    }
    for(int i=0;i<m;i++)
    {
        int x=bian[i][0];
        int y=bian[i][1];
        if(map[1][x]+map[y][n]<k)
        {
            add(x+n,y,1);
            add(y,x+n,0);
        }
    }
}
int makedivv()
{
    memset(divv,0,sizeof(divv));
    divv[ss]=1;
    queue<int >s;
    s.push(ss);
    while(!s.empty())
    {
        int u=s.front();
        if(u==tt)return 1;
        s.pop();
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            int w=e[i].w;
            if(w&&divv[v]==0)
            {
                divv[v]=divv[u]+1;
                s.push(v);
            }
        }
    }
    return 0;
}
int Dfs(int u,int maxflow,int tt)
{
    if(u==tt)return maxflow;
    int ret=0;
    for(int &i=cur[u];i!=-1;i=e[i].next)
    {
        int v=e[i].to;
        int w=e[i].w;
        if(w&&divv[v]==divv[u]+1)
        {
            int f=Dfs(v,min(maxflow-ret,w),tt);
            e[i].w-=f;
            e[i^1].w+=f;
            ret+=f;
            if(ret==maxflow)return ret;
        }
    }
    return ret;
}
void Dinic()
{
    int ans=0;
    while(makedivv()==1)
    {
        memcpy(cur,head,sizeof(head));
        ans+=Dfs(ss,INF,tt);
    }
    printf("%d\n",ans);
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if(n+m+k==0)break;
        memset(map,0x3f3f3f3f,sizeof(map));
        for(int i=1;i<=n;i++)map[i][i]=0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            bian[i][0]=x;
            bian[i][1]=y;
            map[x][y]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    map[j][k]=min(map[j][k],map[j][i]+map[i][k]);
                }
            }
        }
        getmap();
        Dinic();
    }
}
```