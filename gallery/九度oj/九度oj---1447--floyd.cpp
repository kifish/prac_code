#include<cstdio>

int ans[101][101];
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0)
            break;
        int i,j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans[i][j]=-1;
            }
            ans[i][i]=0;
        }
        while(m--){
            scanf("%d %d",&i,&j);
            scanf("%d",&ans[i][j]);
            ans[j][i]=ans[i][j];
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(ans[i][k]==-1||ans[k][j]==-1) continue;
                    if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
                        ans[i][j]=ans[i][k]+ans[k][j];
                }
            } 
        }
        printf("%d\n",ans[1][n]);
    }
    return 0;
}
