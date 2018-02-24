#include<cstdio>
#define N 105
#include<algorithm>
#include<cmath>
using namespace std;
int root[N];
int findroot(int x){
    if(root[x]==-1) return x;
    else {
        int tmp = findroot(root[x]);
        root[x]=tmp;
        return tmp;
    }
}

struct Edge{
    int a,b;
    double cost;
    bool operator < (const Edge &A) const{
        return cost<A.cost;
    }
}edge[6000];

struct Point{
    double x;
    double y;
    double getDistance(Point A){
        double tmp=(x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);
        return sqrt(tmp);
    }
}point[101];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&point[i].x,&point[i].y);
        }
        int size=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                edge[size].a=i;
                edge[size].b=j;
                edge[size].cost=point[i].getDistance(point[j]);
                size++; 
            }
        }
        sort(edge,edge+size);
        for(int i=1;i<=n;i++){
            root[i]=-1;
        }
        double ans=0;
        for(int i=0;i<=size-1;i++){
            int a=findroot(edge[i].a);
            int b=findroot(edge[i].b);
            if(a!=b){
                root[a]=b;
                ans+=edge[i].cost;
            }
            
        }
        printf("%.2f\n",ans);//or %.2lf
    }
    return 0; 
}
