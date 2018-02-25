
/*
memset是对整个字节操作。memset(a,0,sizeof(a));可以。memset(a,1,sizeof(a));不行。

改用fill。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
int L[10001];
void remove(int a,int b){
    for(int i=a;i<=b;i++)
        L[i]=0;
}
int main(){
    int Length,M;
    int a,b; 
    while(scanf("%d %d",&Length,&M)!=EOF){
        fill(L,L+Length+1,1);
        while(M--){
            scanf("%d %d",&a,&b);
            remove(a,b);
        }
        int cnt=0;
        for(int i=0;i<=Length;i++) cnt+=L[i];
        printf("%d\n",cnt);
    
    }
    return 0;
}
