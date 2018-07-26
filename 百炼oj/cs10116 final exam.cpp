http://cs101.openjudge.cn/practice/12560/

样例的结果是对的，但是WA,还没找到原因

#include<cstdio>
int map[105][105];
bool issur[105][105];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int cnt=0;
            if(i-1>=1&&j-1>=1)
                cnt+=map[i-1][j-1];
            if(i-1>=1&&j>=1)
                cnt+=map[i-1][j];
            if(i-1>=1&&j+1<=m)
                cnt+=map[i-1][j+1];
            if(i>=1&&j-1>=1)
                cnt+=map[i][j-1];
            if(i>=1&&j+1<=m)
                cnt+=map[i][j+1];
            if(i+1<=m&&j-1>=1)
                cnt+=map[i+1][j-1];
            if(i+1<=m&&j>=1)
                cnt+=map[i+1][j];
            if(i+1<=m&&j+1<=m)
                cnt+=map[i+1][j+1];
            if(map[i][j]==1){
                if(cnt<2||cnt>3)
                    issur[i][j]=0;
                else issur[i][j]=1;
            }
            else{
                if(cnt==3)
                    issur[i][j]=1;
                else issur[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j!=1)
                 printf(" ");
            if(issur[i][j])
                printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}
