#include<cstdio>
#include<cstring>
int book[205];
int buf[205];
int main(){
    int n,m;
    int tmp;
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(book,0,sizeof(book));
        for(int i=0;i<n;i++) {
            scanf("%d",&tmp);
            book[tmp]++;
            buf[i]=tmp;
        }
        for(int i=0;i<n;i++){
            if(book[buf[i]]==1){
                printf("BeiJu\n");    
            }
            else printf("%d\n",book[buf[i]]-1);
        }
    
    }
    return 0;
}
