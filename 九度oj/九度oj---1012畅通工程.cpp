#include<cstdio>
#include<iostream>
#include<algorithm> //fill
using namespace std; 
int root[1005];
int findroot(int x){
    if(root[x]==-1)
        return x;
    else{
        int tmp=findroot(root[x]);
        root[x]=tmp;
        return tmp;
    }
}
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%d",&m);
        
        fill(root,root+1005,-1);
        int tmp1,tmp2;
        for(int i=0;i<m;i++){
            scanf("%d %d",&tmp1,&tmp2);
            int roota=findroot(tmp1);
            int rootb=findroot(tmp2);
            if(roota!=rootb){
                root[roota]=rootb;
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
