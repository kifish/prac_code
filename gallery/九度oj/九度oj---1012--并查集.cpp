#include<cstdio>
using namespace std;
#define N 1000
int root[N];
int findroot(int x){
    if(root[x]==-1) return x;
    else{
        int tmp=findroot(root[x]);
        root[x]=tmp;
        return tmp;
    }
}
 
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF&&n!=0){
        scanf("%d",&m);
        for(int i=1;i<=n;i++) root[i]=-1;
         
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            a=findroot(a);
            b=findroot(b);
            if(a!=b){
                root[a]=b;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(root[i]==-1)
                cnt++;
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}

/*
#include<cstdio>
using namespace std;
#define N 1000
int root[N];
int findroot(int x){
    if(root[x]==-1) return x;
    else{
        int tmp=findroot(root[x]);
        root[x]=tmp;
        return tmp;
    }
}
 
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF&&n!=0){
        scanf("%d",&m);
        for(int i=1;i<=n;i++) root[i]=-1;
         
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            a=findroot(a);
            b=findroot(b);
            if(a!=b){
                root[a]=b;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(root[i]==-1)
                cnt++;
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}

*/
