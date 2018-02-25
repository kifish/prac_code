//有个测试点没过。

#include<cstdio>
int in[1000];
int out[1000];
int main(){
    int t;
    int i=0;
    while(scanf("%d",&t)!=EOF){
        in[i++]=t;
    }
    int j=0;
    int cnt=0;
    for(;j<=i-2;j+=2){
        if(in[j+1]==0){
            out[j]=0;
            out[j+1]=0;
        }
        else{
        out[j]=in[j]*(in[j+1]);
        if(out[j]!=0) cnt++;
        out[j+1]=in[j+1]-1;
        }
    } 
    
        for(int k=0;k<=j-3||k<=1;k++){
        if(cnt==0) {printf("0 0");break;}    
        if(k==0) printf("%d",out[k]);
        else printf(" %d",out[k]);
        }
    return 0;
}
