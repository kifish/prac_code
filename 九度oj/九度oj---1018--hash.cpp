#include<cstdio>
#include<cstring>
int grade[101];
int main(){
    int n;
    int x;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(grade,0,sizeof(grade)); 
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            grade[x]++;
        }
        scanf("%d",&x);
        printf("%d\n",grade[x]);
    }
    return 0;
}
