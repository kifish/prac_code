//测试用例没那么大，floyd似乎也可以
#include<cstdio>
const int inf=100007;
int ans[101][101];
int main(){
    int n,m,x;
    while(scanf("%d %d %d",&n,&m,&x)!=EOF){
        int i,j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans[i][j]=inf;
            }
            ans[i][i]=0;
        }
        while(m--){
            int tmp;
            scanf("%d %d",&i,&j);
            scanf("%d",&tmp);
            ans[i][j]=tmp;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(ans[i][k]==inf||ans[k][j]==inf) continue;
                    if(ans[i][j]==inf||ans[i][k]+ans[k][j]<ans[i][j])
                        ans[i][j]=ans[i][k]+ans[k][j];
                }
            } 
        }
        int max=0;
        
        for(int i=1;i<=n;i++){
            
            if(ans[i][x]+ans[x][i]>max)
                max=ans[i][x]+ans[x][i];
            
        }
        printf("%d\n",max);
    }
    return 0;
}
