#include<cstdio>
#include<cstring>
int buf[205];

int main(){
    int n; 
    int x;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&buf[i]);
        }
        scanf("%d",&x);
        int res=-1;
        for(int i=0;i<n;i++){
            if(x==buf[i]){
                res=i;
                break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
