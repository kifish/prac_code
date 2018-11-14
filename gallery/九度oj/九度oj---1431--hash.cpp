#include<cstdio>
#include<cstring>
#define offset 500000
bool isinput[1000001];
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(isinput,0,sizeof(isinput));
        int tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            isinput[tmp+offset]=1;
        }
        for(int i=500000;i>=-500000;i--){
            if(isinput[i+offset]==1){
                m--;
                if(m!=0)
                    printf("%d ",i);
                else{
                    printf("%d\n",i);
                    break;
                }    
            }
                
        }
    }
    return 0;
}
