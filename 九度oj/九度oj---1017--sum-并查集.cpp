#include<cstdio>

#define N 10000005
int root[N];
int findroot( int x){
    if(root[x]==-1) return x;
    else{
        int tmp=findroot(root[x]);
        root[x]=tmp;
        return tmp;
    }
}

int sum[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=10000000;i++){
            root[i]=-1;
            sum[i]=1;
        }
        while(n--){
            int a,b;
            scanf("%d %d",&a,&b);
            a=findroot(a);
            b=findroot(b);
            if(a!=b){
                //a=root[b]; mistake,a may be -1
                root[b]=a;
                sum[a]+=sum[b];
            }
        }
        int max=1;
        for(int i=1;i<=10000000;i++){
            if(root[i]==-1&&sum[i]>max){
                max=sum[i];
                
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
